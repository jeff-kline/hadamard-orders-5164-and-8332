STAGE: PROOF-AUDIT
VERDICT: VERIFIED

CLAIM: For every prime q ≡ 1 (mod 4) and every real weighing matrix W(q+3, q+1), the construction of paper/main.tex Sections 2–3 (commit 508d3e7) yields L of order 4v, v = q+2, whose 2×2 cells are all signed permutations, with L Lᵀ = 2v I; hence H = L(I ⊗ F) is a real Hadamard matrix of order 4(q+2). Scope: the conditional theorem only. Existence of the input W(1292,1290), W(2084,2082) (Section 4), the primality of 1289 and 2081, the novelty claims and the C++ verifier are outside this audit.

EVIDENCE: Every step was re-derived by hand in real 2×2-cell form; nothing was taken from the text on trust. Notation: c = (q+3)/2 (even), n = c−1 (odd), R = image of i, A = (I+R)/2, S = √2·A, E = e ⊗ I₂, U = e ⊗ R.

(a) Section 2.
- Two zeros per row by weight; W square with W Wᵀ = wI gives Wᵀ W = wI, so two zeros per column.
- Two rows' zero sets meeting in one column leave 2c−3 common nonzeros, odd, contradicting orthogonality. So zero sets are equal or disjoint. A column a in zero set {a,b} has exactly two zeros, and every row vanishing at a has zero set {a,b}; so each zero set is shared by exactly two rows and the c zero sets partition the columns. (The text's "therefore the rows occur in pairs" needs the column count; it is stated one sentence earlier.)
- Signs: rows r₁,r₂ of pair i are orthogonal on 2c−2 common nonzeros, so ∏_{j≠i} h_ij = (−1)^{c−1}. Against a row s of pair k ≠ i each has 2c−4 common nonzeros and c−2 disagreements; the product of the two sign products is (−1)^{2(c−2)} = 1 and equals ∏_{j≠i,k} h_ij because s-entries square out. Hence h_ik = (−1)^{c−1} = −1 as c is even. A ±1 2×2 block [[a,b],[c,d]] is Hadamard iff abcd = −1.
- D = W(I ⊗ F/2): a Hadamard 2×2 cell has rows ±(1,1), ±(1,−1) in some order, and (1,1)F = (2,0), (1,−1)F = (0,2), so each cell becomes a signed permutation. D Dᵀ = W(I ⊗ FFᵀ/4)Wᵀ = (c−1)I and likewise Dᵀ D = (c−1)I.

(b) Normalization. Right-multiply block column j ≥ 1 by D₀ⱼ⁻¹, then left-multiply block row i ≥ 1 by the inverse of the new D_i0; the second step does not touch row 0. Both are block-diagonal orthogonal, so both Grams and the zero diagonal survive. With row 0 = (0, I, …, I) and row i = (I, Z_i·): (D Dᵀ)₀ᵢ = (Σ_k Z_ik)ᵀ = 0 and (D Dᵀ)ᵢⱼ = I + Σ_k Z_ik Z_jkᵀ = nδ_ij I, so Z Zᵀ = (nI−J) ⊗ I₂ with zero block row sums; Dᵀ D gives the column statements. No hypothesis on the choice of normalizers.

(c) Cells. X′ at spatial (j,k), j ≠ k: ±(M_jk A + N_jk Aᵀ) = ±(A ± Aᵀ) ∈ {±I, ±R}. At j = k: A ± N_jj Aᵀ ∈ {I, R} (uses M_jj = 0, all other M, N entries ±1). Y′: Z_jk for j ≠ k, ±I for j = k. Borders ±I, ±R. Ỹ cells S⁻¹ z S: rotations fixed; the four reflections (axes 0°, 45°, 90°, 135°) are permuted. Transposes preserve the group.

(d) Grams. Y = [[I, U],[Uᵀ, Y′]], X = [[I, E],[−Eᵀ, X′]], Ỹ = Σᵀ Y Σ with Σ = I ⊗ S (every term of Y other than J₂ ⊗ Z has rotation cells).
- X′X′ᵀ = P² ⊗ [(M²+N²) ⊗ AAᵀ + (MN − NM) ⊗ R/2] + J₂² ⊗ I ⊗ AAᵀ = (qP + J₂) ⊗ I, using AAᵀ = I/2, A² = R/2 = −(Aᵀ)², MN = NM (circulants), PJ₂ = 0. Same for X′ᵀX′.
- Y′Y′ᵀ = 2J₂ ⊗ ZZᵀ + 2P ⊗ I = 2J₂ ⊗ (nI−J) ⊗ I₂ + 2P ⊗ I; same for Y′ᵀY′ via ZᵀZ.
- Sum = (vP + vJ₂) ⊗ I − 2J_{2n} ⊗ I₂ = (2vI − 2J_{2n}) ⊗ I₂.
- Block sums: X′ rows and columns sum to 2A = I+R; Y′ rows and columns sum to 0.
- XXᵀ + YYᵀ: (1,1) = 2(1+2n)I = 2vI; (1,2) = −E + e ⊗ (I−R) + U + 0 = 0; (2,2) = 2J ⊗ I₂ + core sum = 2vI.
- XᵀX + YᵀY: (1,2) = E − e ⊗ (I+R) + U + 0 = 0; the rest as above.
- Ỹᵀ Ỹ = Σᵀ(2vI − XᵀX)Σ = 2vI − XᵀX, because X has only rotation cells and commutes with Σ.
- Mixed block of L Lᵀ is X Ỹ − Y X (confirmed from L = [[X, Y],[Ỹᵀ, −Xᵀ]]). (1,1): both I − 2nR. (1,2): U + E Ỹ′ = U (column sums of Z̃ vanish) versus E + U X′ = e ⊗ (I + R(I+R)) = U. (2,1): −Eᵀ − eᵀ ⊗ (I+R)R = −eᵀ ⊗ R versus Uᵀ − Y′Eᵀ = −eᵀ ⊗ R. (2,2): −J ⊗ R + X′Ỹ′ versus −J ⊗ R + Y′X′, where X′Ỹ′ = 2P ⊗ (M ⊗ A + N ⊗ Aᵀ) + 2J₂ ⊗ (I ⊗ A)Z̃ and Y′X′ = 2P ⊗ (M ⊗ A + N ⊗ Aᵀ) + 2J₂ ⊗ Z(I ⊗ A). Equality is A z̃ = z A cellwise, which is the definition z̃ = A⁻¹ z A. The paper's two-subspace argument is this computation split along the eigenvectors (1,1), (1,−1) of P and J₂; it is correct. Without the conjugation the requirement is Az = zA, false for reflections.
- So L Lᵀ = 2vI, and H Hᵀ = L(I ⊗ FFᵀ)Lᵀ = 4vI with every cell gF a full ±1 block.

(e) Yamada's circulants, proved independently rather than cited. With f(k) = ψ(Tr ξᵏ): Tr x = 0 iff x^{q−1} = −1 iff k ≡ n (mod 2n), giving β₀ = 0 and no other zeros (n odd). f(k+2n) = ψ(g) f(k) = −f(k), g = ξ^{q+1} primitive in GF(q), so both sequences have period n. Symmetry from Tr(x⁻¹) = Tr(x)/N(x), with N(ξ^{4m}) a square and ψ(g)^{n+1} = 1. PAF_α(s) + PAF_β(s) = Σ_{k mod 2n} f(k) f(k+4s) = (q−1)⁻¹ Σ_{x ≠ 0} ψ(Tr x)ψ(Tr xy), y = ξ^{4s}; for s ≢ 0 (mod n), y ∉ GF(q), x ↦ (Tr x, Tr xy) is a GF(q)-linear bijection and the sum is (Σψ)² = 0; for s = 0 it is 2n − 1 = q. Hence M² + N² = qI. Kumar's border equations were re-derived above in real form, not assumed.

(f) Hypotheses. q ≡ 1 (mod 4) is used twice: c even (h = −1) and n odd (Yamada pattern and symmetry). No condition on W beyond W Wᵀ = (q+1)I, none on the normalizers, no symmetry of Z. Primality is not used beyond prime power.

Exact integer computations (finite, supporting only): full pipeline W → pairing → D → Z → L → H for q = 5, 13, 17 (two Golay routes), 41, 73 (orders 28, 60, 76, 172, 300), original and randomly signed/permuted W, 16 runs: every cell a signed permutation, both diagonal Grams, mixed block zero, L Lᵀ = 2vI, H Hᵀ = 4vI all pass. Runs with reflection cells present (6 to 624 reflections) fail L Lᵀ = 2vI when the conjugation is omitted; runs with zero reflections pass either way, as the algebra predicts. Script: audit_check.py

COVERAGE: Checked: all of items (a)–(f); paper/main.tex Sections 2–3; kumar-weighing-transfer.md (same derivation); Kumar CONFERENCE.md Theorem 3 at the pinned commit (statement, Yamada paragraph, proof). Not checked: Section 4 (Gysin–Seberry supply, Golay lengths 320 and 520), primality of 1289 and 2081, the order-5164 and order-8332 matrices themselves, the C++ verifier, Craigen's and Gysin–Seberry's originals (not needed; the paper's own parity argument is self-contained), Yamada's 1989 paper (replaced by the proof in (e)).

DEPENDENCIES: Discharged: Yamada M, N properties (proved in (e)); Kumar's border equations (re-derived); cell property of D (proved in (a)). Remaining for the two headline orders, outside this audit: existence of the two weighing matrices and the two primality facts.

ERRATA: No correctness defects found.
Presentation (optional):
1. The pairing sentence "Therefore the rows occur in pairs" silently uses the two-zeros-per-column count to get exactly two rows per zero set; one clause would make it explicit.
2. The mixed-block paragraph asserts the border products "are unchanged from Kumar's proof"; the real-form check needs only the block sums (X′: I+R, Y′ and Ỹ′: 0), and a single line listing the four blocks would make it self-contained.
3. "Y′ and Ỹ′ are twice the identity" on the (1,−1) span is right, and X′ there is 2(M ⊗ A + N ⊗ Aᵀ); the text omits that the two then commute trivially.
Optional generalization (not a defect): the argument holds verbatim for prime powers q ≡ 1 (mod 4).

EXPOSURE: Reviewed commit 508d3e7: paper/main.tex, kumar-weighing-transfer.md; Kumar CONFERENCE.md at d885022. The final "Proof review" paragraph of kumar-weighing-transfer.md reports a prior internal review outcome; it was read as part of the assigned file and was not relied on. Not opened: evidence/, VERIFICATION.md, kumar-weighing-audit/, README.md, the reviews directory, STAGE1-REPORT.md.

RESOURCES: One Python script, single core, nice 19, venv interpreter, about 2 CPU-seconds total (limit 120); largest matrix order 300. One curl fetch of CONFERENCE.md. No subagents.
