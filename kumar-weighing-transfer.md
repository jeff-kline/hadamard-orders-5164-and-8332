# Hadamard matrices of orders 5164 and 8332 from real weighing matrices

**Theorem.** Let $q\equiv1\pmod4$ be a prime. A real weighing matrix $W(q+3,q+1)$ suffices for an ordinary Hadamard matrix of order $4(q+2)$. Here $W(N,w)$ has entries $0,\pm1$ and row Gram $wI_N$. Two applications below use existing binary Golay pairs and Yamada's standard circulants. The construction is an existence proof with explicit ingredients.

| Binary Golay length $g$ | Weighing matrix | $q$ | Real Hadamard order |
|---:|---|---:|---:|
| 320 | $W(1292,1290)$ | 1289 | 5164 |
| 520 | $W(2084,2082)$ | 2081 | 8332 |

## From weight deficit two to a conference array

Write $q+3=2c$, so $c$ is even. Let $W=W(2c,2c-2)$. Each row and column has exactly two zeros since the row and column Grams agree. The zero sets of two rows cannot meet in precisely one column, since their common nonzero support would have odd size. Therefore the rows occur in pairs with identical zero sets, each a distinct column pair. Independent row and column permutations put the zero cells on the diagonal of a $c\times c$ array of $2\times2$ cells. This is the pairing in the half-weight construction of [Gysin and Seberry, Theorem 3](https://ajc.maths.uq.edu.au/pdf/12/ocr-ajc-v12-p157.pdf).

Craigen identified the signed-permutation conference matrix obtained by this compression in 1995. The parity argument below gives a short proof of the cell property. [Craigen, Theorem 4 and footnote 16](https://us.ticmeet.com/assets/archivos/d6f1d9b8-d39f-4888-925a-7eb81c4905cc/Craigen_handouts.pdf#page=11)

Let $h_{ij}$ be the product of the four signs in cell $i,j$, for $i\ne j$. Within row pair $i$, orthogonality gives $c-1$ disagreements, so $\prod_{j\ne i}h_{ij}=(-1)^{c-1}$. Now compare each of those two rows with the same row of pair $k\ne i$. In each comparison there are $2c-4$ common nonzeros and $c-2$ disagreements. Multiplying the two sign products cancels the signs from row $k$, giving $\prod_{j\ne i,k}h_{ij}=1$. Consequently $h_{ik}=(-1)^{c-1}=-1$ for every full cell. Each full cell is a Hadamard matrix of order two.

Put $F=\left(\begin{smallmatrix}1&1\\1&-1\end{smallmatrix}\right)$. Multiplying every cell on the right by $F/2$ gives a real matrix $D$ of Gram $(c-1)I_{2c}$ with zero diagonal cells and off-diagonal cells in the group of eight signed permutation matrices of size two. Conversely multiplying such an array on the right by block-diagonal copies of $F$ recovers a weighing matrix. In particular the input equivalence is exact. Quaternary conference matrices give the special case consisting of quarter-turn rotations.

## The modified Kumar array

Write $n=c-1=(q+1)/2$, $v=2n+1$, and use ordinary transpose on real block matrices throughout. Identify a complex scalar $a+bi$ with $\left(\begin{smallmatrix}a&-b\\ b&a\end{smallmatrix}\right)$. Denote the image of $i$ by $R$, and let $A=(I_2+R)/2$. Thus $A$ represents $(1+i)/2$. Scalars, border signs, identities and the real Yamada circulants below act through this representation. Transpose is taken on both cell coordinates and array coordinates.

Independently multiply block rows and columns of $D$ by signed permutations to make its first block row and column equal to $I_2$ outside the corner. If $Z$ is its remaining $n\times n$ array, its block row and column sums vanish and
$$
ZZ^T=Z^TZ=(nI_n-J_n)\otimes I_2 .
$$
Let $P=\left(\begin{smallmatrix}1&-1\\-1&1\end{smallmatrix}\right)$, $J_2$ the all-ones matrix, and $M,N$ Yamada's real symmetric circulants of order $n$, with $M$ zero on the diagonal, $N$ full, and $M^2+N^2=qI_n$. Use the core and borders from [Kumar, Theorem 3](https://github.com/vatskishan03/Hadamard/blob/d885022144ba6bf4efa8315e14871a3736947527/complex-hadamard/CONFERENCE.md#3-the-template):
$$
 X'=P\otimes(M\otimes A+N\otimes A^T)
       +J_2\otimes I_n\otimes A,\qquad
 Y'=J_2\otimes Z+P\otimes I_n\otimes I_2 .
$$
In the next display each scalar in a border stands for its $2\times2$ matrix, and $e$ is the all-ones row of length $2n$:
$$
 X=\begin{pmatrix}1&e\\-e^T&X'\end{pmatrix},\qquad
 Y=\begin{pmatrix}1&i e\\-i e^T&Y'\end{pmatrix}.
$$
Form $\widetilde Y$ by replacing every cell $z$ of $Z$ by $A^{-1}zA$. This is global orthogonal conjugation of $Y$ by block copies of $S=\sqrt2 A$, since $S$ is a rotation by $45^\circ$ and every other term in $Y$ commutes with it. Conjugation by $S$ preserves the eight signed permutations: rotations are fixed and the four reflection axes are permuted.

Put
$$
 L=\begin{pmatrix}X&Y\\\widetilde Y^T&-X^T\end{pmatrix}.
$$
Each cell of $L$ is a signed permutation. On an off-diagonal spatial position the cells of $X'$ represent $\pm A\pm A^T$, equal to $\pm I_2$ or $\pm R$. The same possibilities occur on the diagonal using the $J_2$ term instead of $M$. In $Y'$ every off-diagonal spatial position uses a cell of $Z$, and every diagonal position uses $\pm I_2$.

For the diagonal Grams, the core sum is
$$
 X'X'^T+Y'Y'^T
   =\big[(q+2)P\otimes I_n+
           J_2\otimes((2n+1)I_n-2J_n)\big]\otimes I_2
   =(2vI_{2n}-2J_{2n})\otimes I_2.
$$
Here $PJ_2=0$, $P^2=2P$, $J_2^2=2J_2$; the same equality holds with transposes reversed. The block sums of $X'$ are $I_2+R$ in every row and column, and those of $Y'$ are zero. Thus the borders cancel the term $-2J_{2n}$, and their off-diagonal Gram entries vanish by the identical scalar border equations in Kumar's proof. This gives both $XX^T+YY^T=2vI$ and $X^TX+Y^TY=2vI$. Since $X$ commutes with block copies of $S$, $Y^TY=2vI-X^TX$ commutes with them as well. Hence $\widetilde Y^T\widetilde Y=Y^TY$.

The mixed Gram block is $X\widetilde Y-YX$. In the span of $(1,1)$ in the first core tensor coordinate, $X'$ is $2I_n\otimes A$, $Y'$ is $2Z$, and $\widetilde Y'$ is $2\widetilde Z$. On this subspace equality is exactly $A\widetilde z=zA$ in each cell. In the span of $(1,-1)$, both $Y'$ and $\widetilde Y'$ are twice the identity. All border products are unchanged from Kumar's proof by the zero block sums of $Z,\widetilde Z$, and the identical borders. Therefore $LL^T=2vI$. Multiplying $L$ on the right by diagonal copies of $F$ turns every signed permutation into a full sign block and doubles the Gram. The resulting ordinary Hadamard matrix has order $4v$.

## Golay inputs and the two orders

For a binary Golay pair $X,Y$ of length $g$, write polynomials in $z$, $\mathcal N(U)=U(z)U(z^{-1})$, so $\mathcal N(X)+\mathcal N(Y)=2g$. Gysin and Seberry's Theorem 7 supplies both $W(4g+4,4g+2)$ and $W(4g+12,4g+10)$. Their Corollary 5 explicitly includes $t=323,521$ for $W(4t,4t-2)$. [Paper, p. 162](https://ajc.maths.uq.edu.au/pdf/12/ocr-ajc-v12-p157.pdf#page=6)

One can check the weights directly. At length $g+1$, take the four words $X+z^g,X-z^g,Y,Y$, padding the last two with zeros. Their norms sum to $4g+2$. At length $g+3$, take $X\pm z^g(1+z-z^2)$ and $Y\pm z^g(1+z^2)$. The two tail norms sum to five, so these four norms sum to $4g+10$. Evaluation on the cyclic shift of the respective length in the Goethals–Seidel array gives the stated weighing matrices. Binary Golay pairs exist at $320=2^5\cdot10$ and $520=2\cdot10\cdot26$ by the classical product construction.

Consequently a Golay length $g$ gives $H(16g+12)$ whenever $4g+1$ is prime, and $H(16g+44)$ whenever $4g+9$ is prime. For $g=320$ the second formula has $q=1289$. For $g=520$ the first has $q=2081$. Trial division through their square roots proves both primes.

The 2026 survey's Table 5 and Kumar's subsequent frontier list both ordinary orders as open. They establish the comparison with those lists. Priority against every earlier construction has not been established. [Egan et al., Table 5](https://arxiv.org/html/2610.27175v2#S4.T5) · [Kumar's frontier](https://github.com/vatskishan03/Hadamard/blob/d885022144ba6bf4efa8315e14871a3736947527/FRONTIER.md)

The [C++ control](arith/kumar-dihedral-control.cpp) exercises the rotation and reflection cases at $q=17$. Two end-to-end controls use the two Golay constructions at lengths 4 and 2, each passing through $W(20,18)$ to $H(76)$. A separate input has a negative determinant product on a four-cycle. Its corrected array passes every Gram check, whereas leaving the lower-left block uncorrected produces 64 erroneous lower-triangular Gram blocks. The code streams the small example and does not store an output Hadamard matrix.

For the two target orders, the verifier constructs the Golay pairs from binary seeds of lengths 2, 10 and 26, verifies every coefficient of the four padded words' norm sum, and generates both Yamada sequences. In the field model $w^2=3$ it uses primitive elements $4+w$ at 1289 and $3+w$ at 2081. It checks primitivity, the sign and zero patterns, symmetry, and every periodic autocorrelation. This calculation needs only one-dimensional sequences.

Run from the directory containing this note.

~~~sh
clang++ -std=c++17 -O2 -Wall -Wextra -pedantic arith/kumar-dihedral-control.cpp -o /tmp/kumar-dihedral-control
/tmp/kumar-dihedral-control
/tmp/kumar-dihedral-control --targets
~~~

**Scope of the order count.** Substituting the classical Golay lengths $2^a10^b26^d$ into the two displayed formulas and intersecting with the 120 numerical rows of the pinned Kumar frontier, which run from 2396 through 11996, gives exactly 5164 and 8332. Other weighing-matrix constructions are outside this count.

**Proof review.** A separate Astra examiner first identified the potential failure of reducing all signed permutations to complex rotations. After reading the proof it verified the corrected mixed Gram including all four border terms, both diagonal Grams, the supplier theorem, both parameter substitutions and both concrete pairs of Yamada rows. The initial and proof-stage reports have SHA-256 digests e626dd3b6ce7a3687ad3fe79982159689b29284bbbbb71d2818a27111cd763b6 and b189b9e77dfffd3b1cea4d91c95cc0bc1db6de5875eace91c2be7d2f7987b8f0 respectively. This was an internal mathematical review.
