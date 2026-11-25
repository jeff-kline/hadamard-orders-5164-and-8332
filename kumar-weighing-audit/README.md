# Proof and priority audit for Hadamard orders 5164 and 8332

24 November 2026. A fresh Astra examiner checked the transfer and both applications. Two other Astra reviewers investigated historical constructions and recent preprints independently. The proof passed internal review. We located no earlier construction of either ordinary real Hadamard order. One directly relevant 2019 paper could be checked only through its abstract.

| Hadamard order | Binary Golay length | Published real weighing matrix | Prime in the transfer | Historical Hadamard order at the same odd part |
|---:|---:|---|---:|---:|
| 5164 | 320 | W(1292,1290) | 1289 | 10328 |
| 8332 | 520 | W(2084,2082) | 2081 | 16664 |

## Proof

1. The examiner received the theorem and parameter claims before seeing the proof or code. It independently derived the pairing of the two zeros per row and flagged that row and column pairings can differ. [Initial examination](hm-prio-cold-v2.txt)
2. After disclosure, the examiner checked the compression to signed permutations, independent row and column normalization, the two diagonal Gram identities, all four mixed border products, and the final conversion to signs. In the symmetric core component the essential equality is \(A\widetilde z=zA\). It holds for reflections as well as rotations because \(\widetilde z=A^{-1}zA\). The examiner also derived the Yamada row correlations using two independent trace forms and checked both substitutions in the weighing-matrix theorem. [Proof examination](hm-prio-proof-v2.txt) · [Derivation](../kumar-weighing-transfer.md) · [Gysin and Seberry, Theorem 7 and Corollary 5](https://ajc.maths.uq.edu.au/pdf/12/ocr-ajc-v12-p157.pdf#page=6)
3. The examiner rebuilt the C++ control and reran it. Both order-76 controls passed. In a reflection example omitting the conjugation gave 64 erroneous Gram blocks. The corrected example gave zero. Target checks covered all Golay input correlations and both pairs of Yamada rows. The two target matrices were never generated. The code rerun used the existing implementation. [C++ source](../arith/kumar-dihedral-control.cpp)

## Historical and recent priority

| Source or construction | Finding |
|---|---|
| Seberry–Yamada (1992), Table A.2 and Corollary 8.14 | Both entries read exponent 3 with construction code w#q. The eight Williamson-type matrices give orders 8·1291 and 8·2083. [Historical table](https://documents.uow.edu.au/~jennie/WEBPDF/175_1992.pdf) |
| Cati–Pasechnik, Table 4 | Both entries again carry exponent 3. [Table 4](https://arxiv.org/pdf/2411.18897#page=18) |
| Yamada and Miyamoto | Yamada's symmetric real conference inputs would have weights 645 and 1041. Each has odd valuation at 3, violating the sum-of-two-squares condition. The direct Miyamoto construction at either odd part fails its order conditions. [Yamada](https://doi.org/10.1017/S144678870003086X) · [Miyamoto](https://www.sciencedirect.com/science/article/pii/0097316591900085) |
| Earlier weighing-matrix constructions | Gysin–Seberry explicitly supply both inputs. Craigen's earlier doubling of these weighing matrices gives 2584 and 4168. The explicit signed-group new-order list of Craigen–Kharaghani omits both odd parts. [Gysin–Seberry](https://ajc.maths.uq.edu.au/pdf/12/ocr-ajc-v12-p157.pdf#page=6) · [Craigen](https://us.ticmeet.com/assets/archivos/d6f1d9b8-d39f-4888-925a-7eb81c4905cc/Craigen_handouts.pdf#page=11) · [Craigen–Kharaghani](https://doi.org/10.1023/A:1008241809111) |
| Egan–Kotsireas–London–Ó Catháin, Table 5 | Both odd parts appear explicitly in the open 4p column. [Version 2, Table 5](https://arxiv.org/pdf/2610.27175v2#page=10) |
| Kumar | His frontier already identifies both targets and the sufficient quaternary conference orders 646 and 1042. Neither target appears among his 34 constructed orders. The present transfer allows signed permutation cells including reflections. [Pinned frontier](https://github.com/vatskishan03/Hadamard/blob/d885022144ba6bf4efa8315e14871a3736947527/FRONTIER.md) · [Construction report](https://generalised.si/research/hadamard-matrices) |
| Alternative quaternary inputs | Zaitsev lists a full quaternary Hadamard matrix at 646. Kumar requires a conference matrix there. The Jedwab–Pender Legendre-pair families do not supply lengths 1290 or 2082, and neither length appears among the explicit additions checked in 2026. [Catalogue](https://www.cs.uleth.ca/~zaitsevv/quaternary.html) · [Jedwab–Pender](https://arxiv.org/abs/2408.08472) · [2026 paper](https://arxiv.org/abs/2609.04589) |

**Open bibliographic question.** Lou, Xia and Xia (2019) discuss T-matrices for primes of the form \(6m+1=a^2+3b^2\). Both odd parts qualify arithmetically, since \(1291=28^2+3\cdot13^2\) and \(2083=44^2+3\cdot7^2\). A T-matrix system at either prime would give the corresponding real Hadamard order. The publisher's abstract mentions two special cases and omits their hypotheses. We could not retrieve the full text to decide whether either case supplies a target. The accessible 2017 predecessor covers neither in its explicit examples. Unconditional historical priority remains unresolved. [2019 publisher abstract](https://www.pphmj.com/article.php?act=art_abstract_show&art_id=12700&flag=next) · [2017 predecessor](https://documents.uow.edu.au/~jennie/WEB/WEB17/Xtb32_6mp1.pdf)

**Follow-up on the LXX hypothesis.** Theorem 2 of the 2017 paper states that every prime congruent to 1 modulo 3 has a representation by the form above. Thus the representation holds for every prime of the form 6m+1 and gives no evidence for membership in either 2019 special case. For the two targets the values of m are 215 and 347. In the 2017 construction even the sign-count equation (5) is feasible at both, with r=m and respective pairs of sign sums (9,13) and (−15,7). Equation (6) imposes a separate autocorrelation condition. Table 1 supplies explicit sequences only through prime-power order 79. The general prime-power existence statement is labeled a conjecture. [2017 paper, Theorem 2 and §3](https://documents.uow.edu.au/~jennie/WEB/WEB17/Xtb32_6mp1.pdf)

Crossref points to the publisher download, which returned HTTP 403. OpenAlex lists the article as closed and provides no repository copy. A November 2026 paper records the same access gap at three different orders. Its discussion provides no evidence about the two target primes. [Crossref record](https://api.crossref.org/works/10.17654/DM021020163) · [OpenAlex record](https://api.openalex.org/works/doi:10.17654/DM021020163) · [2026 discussion, p. 21](https://hexagonmath.org/pdf/2611.00637v1#page=21)

## Follow-up on signed groups and the two concrete outputs

Craigen's 1995 work already provides the compression from a real weighing matrix of order n and weight n−2 to a conference matrix over the eight signed permutations of order two. For n divisible by four, his real Hadamard construction gives order 2n. Substituting 1292 and 2084 gives 2584 and 4168. Craigen–Kharaghani's Theorem 3 also produces a multiple of its weighing-matrix order. The outputs here are 4n−4, which is not a multiple of either input order. Yamada's symmetric real conference route is excluded by the weight obstruction above. The primary Miyamoto Corollary 4 was available through restatements only. Kumar's scalar quaternary inputs permit rotations. The 45-degree conjugation in this paper works for reflection cells too. [Craigen's structural paper](https://www.academia.edu/81900583/The_structure_of_weighing_matrices_having_large_weights) · [Craigen–Kharaghani, Theorem 3](https://doi.org/10.1023/A:1008241809111) · [Yamada's paper](https://doi.org/10.1017/S144678870003086X) · [Kumar](https://generalised.si/research/hadamard-matrices)

On November 24 a second reviewer searched the arXiv, GitHub and aiXiv web indexes for the target orders and the signed-group construction. Direct GitHub searches for both numerical orders with “Hadamard”, and for “4(q+2)” with “signed” and “hadamard”, returned no matches. These bounded searches and the original-source comparisons identified no earlier transfer with the stated input and output. The missing LXX hypotheses remain relevant to historical priority.

The first proof review above checked only input sequences at the target parameters. Claude subsequently implemented the assembly separately and reported full entry and Gram checks at both target orders. [Independent report](../evidence/claude-report.md)

## Reviewed versions

| Artifact | SHA-256 |
|---|---|
| Transfer proof | `2a3969171f7ce39b568bf99973cefaf249051418e6bae07070f9d28cc35a83ac` |
| C++ control | `2b9bb2bda1901230152dca5edf6d017536865bfbb5ffb79710907ba626870591` |
| Claim-only report | `97b4bd1d6810e2686a991f6404ddfba7af6462d00ed095ea0b7662c047f5101c` |
| Proof-stage report | `2d8ec01b6fed356020c939329f459b96195f4b0fd34255f3c1831eadc7539dfd` |
