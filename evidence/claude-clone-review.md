# Review of jeff-kline/hadamard-orders-5164-and-8332 at d8ad6c4 (2026-11-24)

Reviewer: Claude. Fresh clone of the private repository.

## Reproduced
- `make verify`: MATCH (order-76 controls, reflection control, both target input checks).
- `make verify-full FULL_PY=<venv with NumPy 2.0.2>`: MATCH 5164 and MATCH 8332 (44 s, one core).
- `shasum -a 256 -c MANIFEST.sha256`: all OK.
- `evidence/build.py` and `certify/certify.py` are byte-identical to the reviewer's originals.
- Matrix digests (SHA-256 of the final H, row-major, int8 entries ±1), from `digest.py` here:
  - 5164: `cb3dad46e7c728fc793b22a3b3b27b531004081832adcd177de479539f8a4323`
  - 8332: `78d26895a489ca6991cdacec9a0cd42f91adacc3ed7ed7fa6e84a47d2fd67091`

## Resolved since the first review
Full-matrix target (`make verify-full`), formal bibliography, standard Role-of-AI text, VERIFICATION.md,
MANIFEST, CITATION repository URL, Golay corollary with the Kumar-frontier scope, signed-group
follow-up in the priority record, README section structure.

## Remaining
1. **Present the dense check as the release's own verification, not as "reported by Claude".** The
   release ships the code and `make verify-full` reproduces it in under a minute; it was just
   reproduced from a fresh clone. README "Evidence and limits", VERIFICATION.md and the paper's last
   section can say "`make verify-full` builds both matrices and checks every entry and H Hᵀ = hI
   exactly", and keep who-wrote-what in a repository record (e.g. audit/ATTRIBUTION.md). The release
   standard keeps system names out of reader-facing prose. Pin the two digests above.
2. **Proof review is single-system.** The transfer proof was examined only by the drafting system's
   own reviewer; the dense builds cover the two applications, not the general theorem. Given that
   the result settles two open orders, one cold, process-separated proof audit of the general theorem
   (Section 3: the mixed Gram block with reflection cells and the four border products) is worth
   running before the tag.
3. **Consistency:** ADMISSION.md says "the November 2026 survey" and CITATION.cff "the November 2026
   census"; README and paper say "version 2 of the 2026 survey (arXiv:2610.27175v2)". Use one form.
4. **Paper, last section:** the sentence "Its routine C++ checks use the one-dimensional inputs"
   repeats the previous paragraph; and the dense paragraph can drop the provenance and simply state
   the check and its exactness argument.
5. Priority residual (Lou–Xia–Xia 2019) is stated correctly on every surface.
