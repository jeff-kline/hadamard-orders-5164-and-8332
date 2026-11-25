# Verification and review history

Codex drafted the transfer under the author’s direction. A fresh Astra examiner checked the general proof, including the mixed Gram identity. The [two-stage audit](README.md) records the scope of that examination.

Claude implemented the array separately, reusing the existing Yamada generator. It rebuilt the two target matrices and checked their entries and full Gram matrices, then repeated the checks from a fresh clone at commit `d8ad6c4`. That reproduction took 44 seconds on one core. The [first report](../evidence/claude-report.md) and [fresh-clone review](../evidence/claude-clone-review.md) record both runs. The [matrix digests](../evidence/matrix-sha256.txt) come from that review.

The release verifier now hashes the same signed-byte row order while the matrix is in memory. The assembly, sign test and Gram test are the ones reproduced at `d8ad6c4`. For this revision Codex exercised the hash path on small controls. The two target-size digests are the independently supplied reference values.

## External proof review completed on November 24, 2026

The sealed [packet](fable/PACKET.md) gave the statement and the construction at commit `508d3e7`. The [first reviewer](fable/STAGE1-REPORT.md) found no counterexample in its two structured input families. Its numerical tests used 158 CPU seconds against a 120-second allocation. It reported truncated output at order 28 and for part of the next case. This stage followed a brief permitting small calculations despite the statement-only packet’s stricter wording.

A fresh [second reviewer](fable/stage2-proof-audit.md) verified Sections 2–3 of the paper by re-deriving the pairing, the signed-permutation cells, both diagonal Grams, the four blocks of the mixed product and the Yamada identities. Its exposure record says it saw a reference to an earlier internal verdict in the derivation note. It did not consult the earlier reports or the computation evidence. The [adjudication](fable/ADJUDICATION.md) covers the conditional theorem for prime $q$. The input supply for the two concrete orders and historical priority were outside that stage. The suggested prime-power extension remains outside the release claim.

The revised manuscript incorporates the three expository suggestions. Both source reports, the packet and the adjudication were checksum-verified on receipt. The repository copies of the two reports replace machine-specific temporary paths with script basenames. [Original file hashes](fable/source-sha256.txt)
