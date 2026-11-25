# Hadamard matrices of orders 5164 and 8332 from real weighing matrices

Jeffery Kline

**Status.** Private review version 0.1.0-dev, November 24, 2026. [Review record](ADMISSION.md)

## Introduction

We construct real Hadamard matrices of orders **5164** and **8332**, two orders listed as open in the 2026 survey by Egan, Kotsireas, London and Ó Catháin (arXiv:2610.27175v2). A Hadamard matrix is a square array of signs whose distinct rows have dot product zero. Both constructions follow from a general theorem and use weighing matrices known since 1995. [Paper](paper/main.pdf) · [Survey, Table 5](https://arxiv.org/pdf/2610.27175v2#page=10)

## What is new

Kumar identified both targets. His construction would give them from quaternary conference matrices of orders 646 and 1042, respectively. We show how to use real weighing matrices whose rows each contain two zeros. [Kumar’s construction](https://github.com/vatskishan03/Hadamard/blob/d885022144ba6bf4efa8315e14871a3736947527/complex-hadamard/CONFERENCE.md#3-the-template) · [Kumar’s table](https://github.com/vatskishan03/Hadamard/blob/d885022144ba6bf4efa8315e14871a3736947527/FRONTIER.md)

**Theorem.** For every prime $q\equiv1\pmod4$, a real weighing matrix of order $q+3$ and weight $q+1$ gives a real Hadamard matrix of order $4(q+2)$.

Craigen showed how to express the weighing matrix in terms of two-dimensional signed permutations. These can include rotations and reflections. Kumar’s quaternary entries correspond to rotations. Conjugating the blocks in one corner of his array by a 45-degree rotation makes the orthogonality identity hold for reflections as well. Gysin and Seberry’s construction then supplies both inputs directly. [Craigen, Theorem 4](https://us.ticmeet.com/assets/archivos/d6f1d9b8-d39f-4888-925a-7eb81c4905cc/Craigen_handouts.pdf#page=11) · [Gysin and Seberry, Theorem 7 and Corollary 5](https://ajc.maths.uq.edu.au/pdf/12/ocr-ajc-v12-p157.pdf#page=6)

| Binary Golay pair length | Weighing matrix (order, weight) | Prime $q$ | Hadamard order |
|---:|---:|---:|---:|
| 320 | (1292, 1290) | 1289 | **5164** |
| 520 | (2084, 2082) | 2081 | **8332** |

**Golay corollary.** A binary Golay pair of length $g$ gives order $16g+12$ whenever $4g+1$ is prime, and order $16g+44$ whenever $4g+9$ is prime. Among the 120 orders in Kumar’s pinned frontier, substituting the classical Golay lengths $2^a10^b26^d$ with nonnegative exponents gives exactly 5164 and 8332. [Derivation and scope](kumar-weighing-transfer.md)

## Earlier work and priority

Seberry and Yamada’s historical table records Hadamard orders $8\cdot1291=10328$ and $8\cdot2083=16664$. The present construction gives $4\cdot1291$ and $4\cdot2083$. We found no earlier construction of either order. One question remains open. Lou, Xia and Xia (2019) discuss two special cases for constructing T-matrices. A T-matrix system at 1291 or 2083 would give the corresponding Hadamard order. Both primes satisfy the arithmetic condition in their abstract. The full text was inaccessible during this review, and the abstract omits the hypotheses of the two cases. Historical priority therefore remains provisional. [Seberry and Yamada, Table A.2](https://documents.uow.edu.au/~jennie/WEBPDF/175_1992.pdf) · [Lou, Xia and Xia](https://doi.org/10.17654/DM021020163) · [Priority audit](kumar-weighing-audit/README.md)

## Evidence and limits

| Claim | Evidence |
|---|---|
| General transfer | Algebraic proof, internal examination and a separate symbolic audit of Sections 2–3. [Proof review](kumar-weighing-audit/fable/stage2-proof-audit.md) |
| Inputs at both orders | Exact sequence correlations checked in C++ |
| Every entry and the full Gram matrix at both orders | `make verify-full` checks both complete matrices against the sign and Gram identities, then matches their SHA-256 digests. |
| Historical priority | Both census entries verified. The 2019 T-matrix cases remain unresolved. |

The proof establishes orthogonality for the whole family. The C++17 verifier checks every required correlation in the input sequences for both target orders. It also checks two examples of order 76 end to end. A separate example with a reflection gives 64 failing Gram-block checks when the conjugation is omitted and zero when it is included. The C++ check uses one-dimensional sequences at the target parameters. [Audited derivation](kumar-weighing-transfer.md) · [Verifier source](arith/kumar-dihedral-control.cpp)

At order 300, the same inputs pass the full Gram check with the conjugation and fail when it is omitted. [Verification record](VERIFICATION.md) · [Review history](kumar-weighing-audit/ATTRIBUTION.md)

## Reproduce

Run the bounded checks from the repository root.

~~~sh
make verify
~~~

The optional `make verify-full` builds both target matrices sequentially. A fresh-clone run of the full Gram checks took 44 seconds on one core. The order-8332 build used about 2.2 GB. [Dependencies and verification record](VERIFICATION.md)

## Role of AI

AI assisted the derivations, the computer verification, the literature search and the exposition under the author's direction. Process-separated AI reviews checked the proofs and certificates; they are not independent expert peer review, and no independent human expert has examined the proofs. The release repository records the sources, the reviews and their dispositions.

## Related work

The related paper *New Hadamard orders above 10000* applies Kumar's array to powers of quaternary conference matrices. The present paper handles the two orders below 10000 by admitting reflections in the array. [Related release](https://github.com/jeff-kline/new-hadamard-orders-above-10000)

## License and citation

The paper, source and accompanying materials are available under GPL-3.0-only. [License](LICENSE) · [Citation](CITATION.cff) · [Release status](ADMISSION.md) · [Corrections](CORRECTIONS.md)
