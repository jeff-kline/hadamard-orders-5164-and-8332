"""Independent build-and-check of the weighing-matrix transfer (kumar-weighing-transfer.md):
binary Golay pair of length g -> Gysin–Seberry W(4L, 4L-2) (L = g+1 or g+3) -> compression to a
signed-permutation conference array -> modified Kumar array -> real Hadamard matrix of order 4(q+2),
q = 2(2L)-3. Dense exact checks of every stage, including H H^T = N I for the final matrix.

Usage: python build.py control        (orders 76 (both forms), 172, 300 + negative control)
       python build.py 320 g3         (order 5164)
       python build.py 520 g1         (order 8332)
Written from the theorem statement only; Yamada's circulants from ../certify/certify.py.
"""
import sys, os, json, time
import numpy as np
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "certify"))
import certify as C

SEEDS = {2: ("++", "+-"), 10: ("++-+-+--++", "++-+++++--"),
         26: ("++++-++--+-+-+--+-+++--+++", "++++-++--+-+++++-+---++---")}
def seq(s): return np.array([1 if ch == "+" else -1 for ch in s], dtype=np.int64)

def acorr_sum(ws):
    tot = None
    for w in ws:
        c = np.correlate(w, w, mode="full")
        tot = c if tot is None else tot + c
    return tot

def is_golay(a, b):
    t = acorr_sum([a, b]); m = len(a)
    return t[m - 1] == 2 * m and np.count_nonzero(t) == 1

def golay_product(A, B, Cc, D):
    """Turyn product: (A,B) length m, (Cc,D) length n -> length mn."""
    m, n = len(A), len(Cc)
    P, Q = (Cc + D) // 2, (Cc - D) // 2
    Ab, Bb = A[::-1], B[::-1]
    E = np.zeros(m * n, dtype=np.int64); F = np.zeros(m * n, dtype=np.int64)
    for i in range(m):
        E[i * n:(i + 1) * n] = A[i] * P + B[i] * Q
        F[i * n:(i + 1) * n] = Bb[i] * P - Ab[i] * Q
    return E, F

def golay(g):
    """Binary Golay pair of length g = 2^a 10^b 26^c by Turyn products of the seeds."""
    a, b = seq(SEEDS[2][0]), seq(SEEDS[2][1]); base = None
    parts = []
    for p in (26, 10):
        while g % p == 0: parts.append(p); g //= p
    while g % 2 == 0: parts.append(2); g //= 2
    assert g == 1
    X, Y = seq(SEEDS[parts[0]][0]), seq(SEEDS[parts[0]][1])
    for p in parts[1:]:
        X, Y = golay_product(X, Y, seq(SEEDS[p][0]), seq(SEEDS[p][1]))
    assert is_golay(X, Y)
    return X, Y

def gs_words(X, Y, form):
    g = len(X)
    if form == "g1":
        L = g + 1; t = np.zeros(L, dtype=np.int64); t[g] = 1
        Xp = np.concatenate([X, [0]]); Yp = np.concatenate([Y, [0]])
        return [Xp + t, Xp - t, Yp, Yp], 4 * g + 2
    L = g + 3
    Xp = np.concatenate([X, [0, 0, 0]]); Yp = np.concatenate([Y, [0, 0, 0]])
    t1 = np.zeros(L, dtype=np.int64); t1[g:] = [1, 1, -1]
    t2 = np.zeros(L, dtype=np.int64); t2[g:] = [1, 0, 1]
    return [Xp + t1, Xp - t1, Yp + t2, Yp - t2], 4 * g + 10

def circ(w):
    L = len(w); idx = (np.arange(L)[None, :] - np.arange(L)[:, None]) % L
    return w[idx]

def goethals_seidel(words):
    A, B, Cc, D = (circ(w) for w in words); L = A.shape[0]
    R = np.eye(L, dtype=np.int64)[::-1]
    return np.block([[A, B @ R, Cc @ R, D @ R],
                     [-B @ R, A, D.T @ R, -Cc.T @ R],
                     [-Cc @ R, -D.T @ R, A, B.T @ R],
                     [-D @ R, Cc.T @ R, -B.T @ R, A]])

def compress(W):
    """Pair rows by zero sets, order rows/cols so zero cells sit on the diagonal; return the
    2x2-cell array times F/2 (signed permutations) as a real matrix, plus checks."""
    N = W.shape[0]; zs = [tuple(np.flatnonzero(W[r] == 0)) for r in range(N)]
    assert all(len(z) == 2 for z in zs)
    groups = {}
    for r, z in enumerate(zs): groups.setdefault(z, []).append(r)
    assert all(len(v) == 2 for v in groups.values())
    cols = [j for z in groups for j in z]
    assert sorted(cols) == list(range(N))
    rows = [r for z in groups for r in groups[z]]
    Wp = W[np.ix_(rows, cols)]
    c = N // 2; F = np.array([[1, 1], [1, -1]])
    cells_ok = True
    D = np.zeros_like(Wp)
    for i in range(c):
        for j in range(c):
            blk = Wp[2 * i:2 * i + 2, 2 * j:2 * j + 2]
            if i == j:
                cells_ok &= bool(np.all(blk == 0)); continue
            cells_ok &= bool(blk[0, 0] * blk[0, 1] * blk[1, 0] * blk[1, 1] == -1)
            D[2 * i:2 * i + 2, 2 * j:2 * j + 2] = (blk @ F) // 2
    return D, cells_ok

def normalize(D):
    """Block row/column signed permutations so block row 0 and column 0 are I2 off the corner."""
    c = D.shape[0] // 2; D = D.copy()
    for j in range(1, c):
        b = D[0:2, 2 * j:2 * j + 2].copy(); D[:, 2 * j:2 * j + 2] = D[:, 2 * j:2 * j + 2] @ b.T
    for i in range(1, c):
        b = D[2 * i:2 * i + 2, 0:2].copy(); D[2 * i:2 * i + 2, :] = b.T @ D[2 * i:2 * i + 2, :]
    return D

def assemble(Z, q, conjugate=True):
    n = Z.shape[0] // 2; I2 = np.eye(2, dtype=np.int64)
    Rm = np.array([[0, -1], [1, 0]], dtype=np.int64)
    al, be, _ = C.yamada(q)
    M, Nn = circ(be), circ(al)                       # M zero diagonal, N full
    # work in units of 1/2 to stay integral: A2 = 2A = I+R, A2^T = I-R
    A2 = I2 + Rm
    P = np.array([[1, -1], [-1, 1]]); J2 = np.ones((2, 2), dtype=np.int64); In = np.eye(n, dtype=np.int64)
    X2 = np.kron(P, np.kron(M, A2) + np.kron(Nn, A2.T)) + np.kron(J2, np.kron(In, A2))   # = 2 X'
    assert np.all(X2 % 2 == 0); Xc = X2 // 2
    Yc = np.kron(J2, Z) + np.kron(P, np.kron(In, I2))
    if conjugate:   # z -> A^{-1} z A, A^{-1} = I - R, A = (I+R)/2
        Ainv = I2 - Rm
        Zb = Z.reshape(n, 2, n, 2).transpose(0, 2, 1, 3)               # (i, j, 2, 2) cells
        T2 = np.einsum('ab,ijbc,cd->ijad', Ainv, Zb, A2); assert np.all(T2 % 2 == 0)
        Zt = (T2 // 2).transpose(0, 2, 1, 3).reshape(2 * n, 2 * n)
        Yt = np.kron(J2, Zt) + np.kron(P, np.kron(In, I2))
    else:
        Yt = Yc
    m = 2 * n
    e = np.kron(np.ones((1, m), dtype=np.int64), I2)          # 2 x 2m
    def border(core, corner, top, left):
        return np.block([[corner, top], [left, core]])
    X = border(Xc, I2, e, -e.T)
    Y = border(Yc, I2, np.kron(np.ones((1, m), dtype=np.int64), Rm), -np.kron(np.ones((m, 1), dtype=np.int64), Rm))
    Yt_ = border(Yt, I2, np.kron(np.ones((1, m), dtype=np.int64), Rm), -np.kron(np.ones((m, 1), dtype=np.int64), Rm))
    L = np.block([[X, Y], [Yt_.T, -X.T]])
    H = np.empty(L.shape, dtype=np.int8)                               # H = L (I (x) F), column pairs
    H[:, 0::2] = L[:, 0::2] + L[:, 1::2]; H[:, 1::2] = L[:, 0::2] - L[:, 1::2]
    return H

def hadamard_check(H):
    N = H.shape[0]
    pm1 = bool(np.all(np.abs(H) == 1))
    Hf = H.astype(np.float32)
    G = Hf @ Hf.T
    ok = pm1 and bool(np.array_equal(G, N * np.eye(N, dtype=np.float32)))
    return dict(order=N, entries_pm1=pm1, gram_exact=ok)

def run(g, form, conjugate=True):
    t0 = time.time(); rep = {"g": g, "form": form}
    X, Y = golay(g); rep["golay_ok"] = True
    words, w = gs_words(X, Y, form)
    t = acorr_sum(words); L = len(words[0])
    rep["aperiodic_norm_sum_constant"] = bool(t[L - 1] == w and np.count_nonzero(t) == 1)
    W = goethals_seidel(words); N = W.shape[0]
    rep["W"] = [N, w]; rep["weighing_ok"] = bool(np.array_equal(W @ W.T, w * np.eye(N, dtype=np.int64))) if N <= 3000 else None
    if N > 3000:
        Wf = W.astype(np.float32); rep["weighing_ok"] = bool(np.array_equal(Wf @ Wf.T, w * np.eye(N, dtype=np.float32)))
    D, cells_ok = compress(W); rep["cells_are_H2"] = cells_ok
    Dn = normalize(D); c = N // 2; n = c - 1; q = 2 * n - 1
    rep["q"], rep["q_prime"], rep["q_mod_4"] = q, C.is_prime(q), q % 4
    first_ok = all(np.array_equal(Dn[0:2, 2 * j:2 * j + 2], np.eye(2)) and np.array_equal(Dn[2 * j:2 * j + 2, 0:2], np.eye(2)) for j in range(1, c))
    Z = Dn[2:, 2:]
    Zf = Z.astype(np.float32)
    target = np.kron(n * np.eye(n) - np.ones((n, n)), np.eye(2)).astype(np.float32)
    rep["core_ok"] = bool(first_ok and np.array_equal(Zf @ Zf.T, target) and np.array_equal(Zf.T @ Zf, target))
    blocks = Z.reshape(n, 2, n, 2)
    refl = sum(1 for i in range(n) for j in range(n) if i != j and int(round(np.linalg.det(blocks[i, :, j, :]))) == -1)
    rep["reflection_cells"] = refl
    H = assemble(Z, q, conjugate)
    rep.update(hadamard_check(H)); rep["expected_order"] = 4 * (q + 2)
    rep["seconds"] = round(time.time() - t0, 1)
    return rep

if __name__ == "__main__":
    if sys.argv[1] == "control":
        out = [run(2, "g3"), run(4, "g1"), run(10, "g1"), run(16, "g3"), run(16, "g3", conjugate=False)]
        out[-1]["note"] = "negative control: conjugation omitted"
    else:
        out = [run(int(sys.argv[1]), sys.argv[2])]
    for r in out: print(json.dumps(r))
