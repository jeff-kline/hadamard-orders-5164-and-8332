STAGE: INITIAL
VERDICT: NOT-BROKEN
EVIDENCE:
Hand derivations (mine, from the packet statement only):
- Step 1 pairing. For rows r,s of W(2c,2c-2) with zero sets S_r,S_s, the number of nonzero terms in r.s is 2c-|S_r u S_s| and must be even, so |S_r u S_s| is 2 or 4: zero sets are equal or disjoint. Each column has exactly two zeros (W^T W=(q+1)I too), so the second zero of column a in S_r lies in a row whose zero set meets S_r, hence equals it. Pairing holds for every W(2c,2c-2), c any integer.
- Sign product -1. Rows r,r' (same zero set), row s with zero set {a,b} disjoint. Normalise r=+1 on its support T. Counting sign patterns of (r',s) on T\{a,b} (size m=2c-4) under r.s=r'.s=0 gives sum of r' over T\{a,b} = m-4z, so r'_a+r'_b = 0 mod 4 exactly when 4|m, i.e. c even. So r_a r_b r'_a r'_b=-1 for every W. Uses q+3 = 0 mod 4 (true for q = 1 mod 4).
- Step 2. A +-1 2x2 cell with sign product -1 times F/2 is a signed permutation; D D^T=(c-1)I follows from F F^T=2I.
- Step 4. Admissible normalisations are exactly Z -> (I x g) Z (I x h), g,h any of the 8 signed permutations (plus simultaneous block permutation). Zero block sums and Z Z^T=Z^T Z=(nI-J) x I2 follow from D D^T=D^T D=nI.
- Cells of L: off-diagonal X' cells are +-I or +-R; diagonal ones I or R; A^{-1}zA = z for rotations and -Rz for reflections. All signed permutations.
- Block product: L L^T = [[XX^T+YY^T, X Ytilde - Y X],[*, Ytilde^T Ytilde + X^T X]].
Exact integer checks (own implementation, numpy int): every assertion in steps 1, 2, 4 passed; for the packet convention all of {every L cell a signed permutation, H is +-1, H H^T = 4(q+2) I, both diagonal Grams = 2v I, X Ytilde - Y X = 0} held in every case observed:
- q=13 (order 60): W = [[C,C],[C,-C]], C Paley conference order 8; 3 random step-1 arrangements (random pair order, order within pairs, row/column signs) x all 64 (g,h) x both orientations of R x 3 primitive elements.
- q=17 (order 76): two distinct W(20,18) = [[A,B],[-B^T,A^T]] from exhaustively found circulant pairs of order 10; same grid.
- q=37, 61, 73 (orders 156, 252, 300): Paley-doubled W, one arrangement, 4 (g,h) choices including reflections, both R orientations, one xi.
Cases with reflection cells in Z (refl>0) and without both occurred and both passed.
Control variants, as a check that the test has teeth: omitting the conjugation in step 7, or using A z A^{-1} instead of A^{-1} z A, FAILS (mixed block nonzero, H not Hadamard) whenever Z contains reflection cells, and passes when Z has rotations only. So step 7 as written is necessary and its side is not interchangeable.
Yamada M,N (xi index 0, q=17,37,61,73 seen): symmetric, M zero diagonal and +-1 elsewhere, N +-1, MN=NM, M^2+N^2=qI all True.
COVERAGE:
- Not a proof. No symbolic derivation of the mixed block or the diagonal Grams for general Z was completed; they are verified numerically only.
- q=5 (order 28, the degenerate n=3 case) ran without any assertion failure in steps 1, 2, 4 (the script would have aborted), but its Hadamard pass/fail lines were cut off by my output truncation and were NOT observed. Likewise the first lines for q=13 (Yamada flags, R-orientation rep 0). Not rerun because the CPU limit was already exceeded.
- q=13 two-circulant W: my search returned none at the requested indices (index beyond the hit list or no such pair); only the Paley-doubled W was tested there.
- All tested W are of two structured types (doubled conference matrix, two circulants). No W(q+3,q+1) outside these, none for q=29, 41, 53 (no W built), nothing above order 300.
- Simultaneous block permutations of Z enter only through the random step-1 pair order.
- Yamada properties for the randomly chosen xi were not printed separately; the Hadamard check passed for them.
- Vacuity: non-vacuous at q=13, 17, 37, 61, 73 by explicit W. General existence of W(q+3,q+1) not examined.
DEPENDENCIES:
- Yamada circulant properties: verified numerically at the q above, not from the source.
- Kumar CONFERENCE.md, Gysin-Seberry 1995, Yamada 1989: NOT fetched or read. Attribution and the "modifies Kumar's template" statement are unverified.
EXPOSURE: PACKET.md (sha256 9c9cda447bc0...ccad6182, confirmed) and section3-statement.md only. No other project or repository file opened, no web sources, no subagents. Tools: ~/.venvs/claude/bin/python with numpy under nice -n 19. Script: s1probe.py
RESOURCES: one single-core run, 158 CPU-seconds. This EXCEEDS the 120 CPU-second limit (the q=17 grid cost about 89 s). Order limit 400 respected (max 300). The section3 note's "no matrix generation, ten minutes" restriction for the statement-only pass was not followed: the task brief authorised small exact checks.
