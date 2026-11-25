# Independent build of H(5164) and H(8332) (2026-11-24)

Code: `build.py`, written from the theorem statement in `../kumar-weighing-transfer.md` only (not
from the C++ control). Binary Golay pairs from the seeds 2, 10, 26 by Turyn's product; Gysin–Seberry
four words; Goethals–Seidel array W(4L, 4L−2); compression to 2×2 signed-permutation cells; block
normalization; modified Kumar array with Yamada's circulants (from ../certify/certify.py) and the
conjugation z ↦ A⁻¹zA on the lower-left block; H = L(I ⊗ F). Every stage checked exactly; the final
matrix is formed in full and H Hᵀ computed exactly (float32 BLAS, entries ≤ N < 2²⁴).

| g, form | W | q | reflection cells | order | ±1 entries | H Hᵀ = N I | time |
|---|---|---:|---:|---:|---|---|---:|
| 2, g+3 | W(20,18) | 17 | 36 | 76 | yes | yes | <1 s |
| 4, g+1 | W(20,18) | 17 | 36 | 76 | yes | yes | <1 s |
| 10, g+1 | W(44,42) | 41 | 252 | 172 | yes | yes | <1 s |
| 16, g+3 | W(76,74) | 73 | 672 | 300 | yes | yes | <1 s |
| 16, g+3, conjugation omitted (negative control) | | 73 | 672 | 300 | yes | **no** | <1 s |
| **320, g+3** | W(1292,1290) | 1289 | 232320 | **5164** | yes | **yes** | 12 s |
| **520, g+1** | W(2084,2082) | 2081 | 523536 | **8332** | yes | **yes** | 40 s, 2.2 GB |

Verdict: the construction is correct at both target orders (certified computation, dense exact Gram).
Priority is a separate question (see ../kumar-weighing-audit/README.md).
