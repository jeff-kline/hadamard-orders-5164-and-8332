# Verification for the private review version

The proof applies to every prime and weighing matrix satisfying the theorem. Computations check the two applications and the effect of the conjugation.

| Order | Weighing matrix and prime | Reflection cells in the normalized core | Full checks |
|---:|---|---:|---|
| 5164 | W(1292,1290), q = 1289 | 232320 | All entries are signs and the full row Gram is 5164 times the identity |
| 8332 | W(2084,2082), q = 2081 | 523536 | All entries are signs and the full row Gram is 8332 times the identity |

`make verify-full` constructs each matrix, checks that every entry is a sign, and compares the complete row Gram matrix with the order times the identity. The binary32 products are signs. Every partial sum is an integer of magnitude at most the order, within the exact binary32 integer range. The target also hashes each matrix as row-major signed 8-bit entries with no header or padding (+1 is `01`, −1 is `ff`) and compares the result with the [two pinned SHA-256 digests](evidence/matrix-sha256.txt). Equivalent matrices with different row or column orderings can have different hashes. [Verifier](evidence/build.py) · [Review history and provenance](kumar-weighing-audit/ATTRIBUTION.md)

## Reproduce

- `make verify` uses C++17 and compares stdout against the two tracked files in `evidence/`. It checks the target input sequences and the small end-to-end controls.
- `make paper` uses pdfLaTeX with a fixed source date. The reference build used pdfTeX 1.40.22 from TeX Live 2021. The PDF SHA-256 is `940b3f46935c95107177d9aaaa97bb5ff4b6df53a5dd37cc5ffca48f50a6d8ab`.
- `make verify-full` is an opt-in target for the two full builds. It runs each order separately, saves the JSON under `build/`, and uses jq to require all stage checks, the expected order and weight, and the expected reflection count. It requires jq and a virtual-environment interpreter with NumPy. The default interpreter is `.venv/bin/python`. To reuse a compatible documented environment, pass `FULL_PY=/absolute/path/to/venv/bin/python`. For a new project environment, install the pinned dependency with `.venv/bin/python -m pip install -r evidence/requirements.txt`.
- `shasum -a 256 -c MANIFEST.sha256` checks the distributed files.

## Checks performed for packaging

The bounded C++ verifier reproduced both reference files with Apple clang 21.0.0. The independent builder's small controls were rerun with Python 3.9.6 and NumPy 2.0.2 in an explicitly selected virtual environment. Both order-76 examples and the order-172 and order-300 examples passed the full-result predicate. Dropping the conjugation at order 300 made the Gram test fail and the predicate rejected that result. The full Gram checks at both target orders were reproduced from a fresh clone of `d8ad6c4`. The added hash comparison was tested on small matrices, including a changed digest. The [review history](kumar-weighing-audit/ATTRIBUTION.md) records which revision each test covered. The 120 numerical rows in Kumar’s pinned table were checked against the two corollary formulas and classical Golay lengths, giving exactly 5164 and 8332.

## Review dispositions

The [original draft review](evidence/claude-draft-review.md) predates this snapshot. The release includes its full-matrix evidence, opt-in reproduction target, formal references, citation metadata and verification record. The paper and README use the author’s AI disclosure. The [proof and priority record](kumar-weighing-audit/README.md) includes the additional signed-group comparison. The claim of existence and the unresolved historical question are reported separately.
