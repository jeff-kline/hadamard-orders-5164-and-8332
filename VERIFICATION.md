# Verification for the private review version

The proof applies to every prime and weighing matrix satisfying the theorem. Computations check the two applications and the effect of the conjugation.

| Order | Independent build | Number of reflection cells in the normalized core | Final checks reported by Claude |
|---:|---|---:|---|
| 5164 | W(1292,1290), q = 1289 | 232320 | All entries are signs and the full row Gram is 5164 times the identity |
| 8332 | W(2084,2082), q = 2081 | 523536 | All entries are signs and the full row Gram is 8332 times the identity |

Claude wrote its own assembly from the mathematical description and reused the earlier Yamada generator. The [report](evidence/claude-report.md), [assembly and comparisons](evidence/build.py) and [shared generator](certify/certify.py) are included. The reported multiplication uses binary32 with sign entries. Each ordinary partial sum in a dot product is an integer of magnitude at most the order, well within binary32’s exact integer range. The published comparisons use exact equality. Reported runtimes were 12 and 40 seconds, with 2.2 GB reported for the larger case. Entrywise matrix-file digests were not recorded in the report.

## Reproduce

- `make verify` uses C++17 and compares stdout against the two tracked files in `evidence/`. It checks the target input sequences and the small end-to-end controls.
- `make paper` uses pdfLaTeX with a fixed source date. The reference build used pdfTeX 1.40.22 from TeX Live 2021. The PDF SHA-256 is `6d4a09f0e9082ab2592b7b33225466ea857185c138acff066b6765d93ff4814e`.
- `make verify-full` is a separate, opt-in target for readers who wish to reproduce Claude’s dense builds. It runs each order separately, saves the JSON under `build/`, and uses jq to require all stage checks, the expected order and weight, and the reported reflection count. It requires jq and a virtual-environment interpreter with NumPy. The default interpreter is `.venv/bin/python`. To reuse a compatible documented environment, pass `FULL_PY=/absolute/path/to/venv/bin/python`. For a new project environment, install the pinned dependency with `.venv/bin/python -m pip install -r evidence/requirements.txt`.
- `shasum -a 256 -c MANIFEST.sha256` checks the distributed files.

## Checks performed for packaging

The bounded C++ verifier reproduced both reference files with Apple clang 21.0.0. The independent builder's small controls were rerun with Python 3.9.6 and NumPy 2.0.2 in an explicitly selected virtual environment. Both order-76 examples and the order-172 and order-300 examples passed the full-result predicate. Dropping the conjugation at order 300 made the Gram test fail and the predicate rejected that result. The target-size dense results above come from Claude’s original run. The 120 numerical rows in Kumar’s pinned table were checked against the two corollary formulas and classical Golay lengths, giving exactly 5164 and 8332.

## Review dispositions

The [original draft review](evidence/claude-draft-review.md) predates this snapshot. The release includes its full-matrix evidence, opt-in reproduction target, formal references, citation metadata and verification record. The paper and README use the author’s AI disclosure. The [proof and priority record](kumar-weighing-audit/README.md) includes the additional signed-group comparison. The claim of existence and the unresolved historical question are reported separately.
