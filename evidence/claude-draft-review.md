# Review of the draft release `hadamard-weighing-transfer_release` (2026-11-24)

Reviewer: Claude (process-separated from the session that wrote the draft). Read: README.md,
paper/main.tex (3 pp), ADMISSION.md, CITATION.cff, Makefile, evidence/, kumar-weighing-audit/README.md.

## Mathematics
- The theorem and both applications are correct as far as computation can show: an independent
  implementation written from the theorem statement (RESULT.md here) forms H(5164) and H(8332) in full
  and checks H Hᵀ = N I exactly; controls at 76 (both forms), 172, 300 pass; omitting the conjugation
  fails. This is stronger than the draft's own evidence, which checks inputs only.
- Pairing argument (Section 2): complete as written; it uses W Wᵀ = wI ⇒ Wᵀ W = wI for the column
  zero count, and the odd-common-support argument for the pairing. Fine.

## Must fix before any freeze
1. **Add the full-matrix check.** The draft says "computation confined to their one-dimensional
   inputs" and "the two target matrices were never generated". A `make verify-full` that builds both
   matrices and checks H Hᵀ exactly (about 1 minute, 2.2 GB, Python + NumPy) closes the main evidential
   gap. Update the README "Checking the result", the paper's last section, and ADMISSION's pending
   "Independent reproduction" row.
2. **Broken link:** ADMISSION.md links VERIFICATION.md, which does not exist.
3. **Role of AI:** use the standard text verbatim ("AI assisted the derivations, the computer
   verification, the literature search and the exposition under the author's direction.
   Process-separated AI reviews checked the proofs and certificates; they are not independent expert
   peer review, and no independent human expert has examined the proofs. The release repository
   records the sources, the reviews and their dispositions."). Keep per-system attribution in a
   repository record (e.g. audit/ATTRIBUTION.md), not in the paper.
4. **Prior art, one more targeted check (P1):** the general theorem (any signed-permutation
   conference matrix of order (q+3)/2 suffices) is the kind of statement Craigen's signed-group
   framework might already contain: Yamada 1989 and Miyamoto 1991 Cor. 4 are the symmetric cases,
   Kumar 2026 the quaternary one. Search specifically for Yamada/Miyamoto-type 4(q+2) constructions
   over signed groups or with weighing-matrix inputs (Craigen 1995, Craigen–Kharaghani 1997,
   Craigen's Handbook chapter, Seberry–Yamada 2020 ch. on Yamada's theorem), plus the usual GitHub /
   arXiv / aiXiv fast-follow scan. The Lou–Xia–Xia 2019 residual stays as stated.
5. **Mirror the predecessor release format** (owner's rule): README sections Introduction / What is
   new / Earlier work / Evidence and limits (verification-scope table) / Reproduce / Role of AI /
   License; status paragraph; paper with a thebibliography (references are inline links only now),
   10pt layout and title-block status line like the previous releases; VERIFICATION.md with the PDF
   hash; MANIFEST.sha256; CITATION with repository URL.

## Should fix
6. State the family as a corollary: H(16g+12) when 4g+1 is prime, H(16g+44) when 4g+9 is prime, for
   every binary Golay length g; and say plainly that within Kumar's frontier (odd parts ≤ 2999) it
   gives exactly 5164 and 8332 (the README of the audit says so; the paper does not).
7. Say once that 8·1291 and 8·2083 were known (it does) and that the theorem is a strict
   generalisation of Kumar's template (quaternary entries = the rotation case), with the conjugation
   by the 45° rotation as the one new step. The README does this well; the abstract could name it.
8. "the November 2026 survey" → "the 2026 survey of Egan, Kotsireas, London and Ó Catháin
   (arXiv:2610.27175v2)"; v1 is dated October.
9. Optional: pin SHA-256 hashes of the two generated matrices (row-major ±1 bytes) so later
   reproductions can be compared byte for byte.

## Relation to `new-hadamard-orders-above-10000` (v0.1.0, admitted today)
Different mechanism and different orders; a separate release is right. Its README/paper could later
gain a one-line pointer ("two open orders below 10^4, 5164 and 8332, are settled in …") as v0.1.1
living metadata, after this release has a DOI.
