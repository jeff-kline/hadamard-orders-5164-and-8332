# Stage-1 packet (statement and construction only; no proof)

Source: jeff-kline/hadamard-orders-5164-and-8332 at commit 508d3e7, paper Sections 2–3, construction
sentences only. The author's proof sentences, verification results and reviews are withheld.

## Claim
Let q ≡ 1 (mod 4) be prime and W a real weighing matrix W(q+3, q+1) (entries 0, ±1, W Wᵀ = (q+1) I).
Then the construction below gives a real ±1 matrix H of order 4(q+2) with H Hᵀ = 4(q+2) I.

## Construction
1. Write q+3 = 2c (c even). Each row and column of W has exactly two zeros. Rows are grouped in pairs
   with identical zero sets, each zero set a column pair; permute rows and columns so that the zero
   cells are the diagonal cells of a c×c array of 2×2 cells. (Claimed: every off-diagonal cell is a
   ±1 2×2 matrix whose four signs multiply to −1.)
2. F = [[1,1],[1,−1]]. Multiply every cell on the right by F/2. This gives D (order 2c) with zero
   diagonal cells, off-diagonal cells among the eight 2×2 signed permutation matrices (rotations ±I,
   ±R and reflections), and D Dᵀ = (c−1) I.
3. n = c−1 = (q+1)/2, v = 2n+1. Identify a+bi with [[a,−b],[b,a]]; R is the image of i;
   A = (I₂+R)/2 (the image of (1+i)/2). Transpose acts on cell and array coordinates.
4. Multiply block rows and columns of D by signed permutations so that the first block row and column
   are I₂ outside the corner. Z = the remaining n×n array of 2×2 cells. (Claimed: block row and column
   sums of Z vanish and Z Zᵀ = Zᵀ Z = (nIₙ − Jₙ) ⊗ I₂.)
5. P = [[1,−1],[−1,1]], J₂ = all-ones 2×2. M, N: Yamada's real symmetric circulants of order n (first
   rows β_m = ψ(Tr ξ^{4m+n}) and α_m = ψ(Tr ξ^{4m}), ψ the quadratic character of GF(q), ξ primitive in
   GF(q²)); M has zero diagonal, N is ±1, M N = N M, M² + N² = q Iₙ.
       X′ = P ⊗ (M ⊗ A + N ⊗ Aᵀ) + J₂ ⊗ Iₙ ⊗ A,      Y′ = J₂ ⊗ Z + P ⊗ Iₙ ⊗ I₂.
6. Borders (each scalar stands for its 2×2 matrix; e = all-ones row of length 2n):
       X = [[1, e], [−eᵀ, X′]],      Y = [[1, i e], [−i eᵀ, Y′]].
7. Ỹ: replace every cell z of Z (inside Y′) by A⁻¹ z A; all other parts of Y unchanged.
8. L = [[X, Y], [Ỹᵀ, −Xᵀ]]   (order 2·2v, cells 2×2).
9. H = L · (I ⊗ F)   (order 4v = 4(q+2)).

Background (verifiable): this modifies Kumar's quaternary template (github.com/vatskishan03/Hadamard,
complex-hadamard/CONFERENCE.md, Theorem 3), where Z has complex unit entries (rotations only) and the
lower-left block is Y*. Gysin and Seberry (Australas. J. Combin. 12, 1995) construct W(4t, 4t−2).
