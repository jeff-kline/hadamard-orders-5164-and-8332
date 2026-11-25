# Verification and review history

Codex drafted the transfer under the author’s direction. A fresh Astra examiner checked the general proof, including the mixed Gram identity. The [two-stage audit](README.md) records the scope of that examination.

Claude implemented the array separately, reusing the existing Yamada generator. It rebuilt the two target matrices and checked their entries and full Gram matrices, then repeated the checks from a fresh clone at commit `d8ad6c4`. That reproduction took 44 seconds on one core. The [first report](../evidence/claude-report.md) and [fresh-clone review](../evidence/claude-clone-review.md) record both runs. The [matrix digests](../evidence/matrix-sha256.txt) come from that review.

The release verifier now hashes the same signed-byte row order while the matrix is in memory. The assembly, sign test and Gram test are the ones reproduced at `d8ad6c4`. For this revision Codex exercised the hash path on small controls. The two target-size digests are the independently supplied reference values.

## External proof review requested before tagging

The proposed Fable review concerns the universal implication. Its [first-stage packet](section3-statement.md) contains only the claim and definitions. The coordinator should save its initial assessment before giving the examiner Section 3 of [the paper](../paper/main.tex), with Section 2 supplied for its input identities. In the proof stage, independently derive the core and border blocks of both mixed products, including their signs and transposes. Check arbitrary reflection cells and identify exactly where zero row and column sums enter. Record the reviewed commit, the equations checked, and any remaining gap. The intended return path is `kumar-weighing-audit/fable-section3.md`.
