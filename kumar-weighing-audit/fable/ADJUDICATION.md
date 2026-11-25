# Cold examination of Section 3, commit 508d3e7 — adjudication (2026-11-24)

| Stage | Reviewer | Exposure | Verdict | Report (sha256) |
|---|---|---|---|---|
| 1 isolated failure search | Fable, fresh context | sealed packet PACKET.md (9c9cda44…): statement + construction, no proof | NOT-BROKEN | STAGE1-REPORT.md (69408b01…) |
| 2 proof audit | Fable, separate fresh context | paper Sections 2–3, kumar-weighing-transfer.md, Kumar CONFERENCE.md; not the evidence, prior reviews or Stage 1 | VERIFIED | stage2-proof-audit.md (ae7a102b…) |

- Stage 2 re-derived every load-bearing step by hand (zero pairing, h_ij = −1 with c even, Grams of D
  and Z, cell membership, both diagonal Grams, all four parts of the mixed block reducing to Az̃ = zA,
  Yamada's identities proved directly). No correctness defects; three optional presentation notes;
  optional generalization: q a prime power ≡ 1 (mod 4).
- Stage 1 found no failure: own implementation at q = 13, 17, 37, 61, 73; 64 normalizations; both
  orientations of R; several primitive elements; dropping the conjugation (or using A z A⁻¹) fails
  once Z has reflection cells. Noted limits: 158 CPU-s (over its 120 s allocation), q = 5 output
  truncated, numerical not symbolic, two families of W.
- Combined with the dense exact builds at 5164 and 8332 (RESULT.md, reproduced from a fresh clone by
  `make verify-full`), the claim stands for promotion: proof VERIFIED by a process-separated
  reviewer; computations certified at both target orders. These are AI reviews, not expert peer review.
- Out of scope here: Section 4 supply (covered at the two targets by the dense builds), priority
  (Lou–Xia–Xia accepted by the author as not openly accessible).
