// Build with c++ -std=c++17 -O2. All Gram entries are streamed.
#include <array>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

struct Block { int a, b, c, d; };
Block operator+(Block x, Block y) {
    return {x.a+y.a, x.b+y.b, x.c+y.c, x.d+y.d};
}
Block operator*(int s, Block x) { return {s*x.a,s*x.b,s*x.c,s*x.d}; }
Block operator*(Block x, Block y) {
    return {x.a*y.a+x.b*y.c, x.a*y.b+x.b*y.d,
            x.c*y.a+x.d*y.c, x.c*y.b+x.d*y.d};
}
bool operator==(Block x, Block y) {
    return x.a==y.a && x.b==y.b && x.c==y.c && x.d==y.d;
}
Block transpose(Block x) { return {x.a,x.c,x.b,x.d}; }
int det(Block x) { return x.a*x.d-x.b*x.c; }
constexpr Block I{1,0,0,1}, R{0,-1,1,0}, F{1,1,1,-1};
Block half(Block x) {
    if (x.a%2 || x.b%2 || x.c%2 || x.d%2) throw std::logic_error("nonintegral");
    return {x.a/2,x.b/2,x.c/2,x.d/2};
}

// Paley conference on infinity=9 and F3[u]/(u^2+1), indexed by x+3y.
// The quadratic character agrees with the F3 character of the norm.
int paley(int i, int j) {
    if (i==j) return 0;
    if (i==9 || j==9) return 1;
    int x=i%3-j%3, y=i/3-j/3;
    return (x*x+y*y)%3==1 ? 1 : -1;
}
int swap01(int x) { return x==0 ? 1 : (x==1 ? 0 : x); }
Block paley_input(int i,int j) {
    return {paley(i,j),0,0,paley(swap01(i),swap01(j))};
}
using Conference = std::array<std::array<Block,10>,10>;
Conference conference;
Block twist(Block z) { return half(transpose(I+R)*z*(I+R)); }

// Yamada rows from quadratic characters of traces at powers 4j+9 and 4j
// of 3+w in F17[w]/(w^2-3), respectively.
constexpr std::array<int,9> M{0,1,-1,1,1,1,1,-1,1};
constexpr std::array<int,9> N{1,-1,-1,1,1,1,1,-1,-1};

Block X(int row,int col) {
    if (row==0) return I;
    if (col==0) return -1*I;
    int i=(row-1)%9,j=(col-1)%9,shift=(j-i+9)%9;
    int p=(row-1)/9==(col-1)/9 ? 1 : -1;
    int a=p*M[shift]+(i==j), b=p*N[shift];
    return half((a+b)*I+(a-b)*R);
}
Block Y(int row,int col,bool twisted) {
    if (row==0 && col==0) return I;
    if (row==0) return R;
    if (col==0) return -1*R;
    int i=(row-1)%9,j=(col-1)%9;
    if (i==j) return ((row-1)/9==(col-1)/9 ? 1 : -1)*I;
    Block z=conference[i][j];
    return twisted ? twist(z) : z;
}
Block entry(int i,int j,bool twisted) {
    int r=i%19,c=j%19;
    if (i<19) return j<19 ? X(r,c) : Y(r,c,false);
    return j<19 ? transpose(Y(c,r,twisted)) : -1*transpose(X(c,r));
}
void check(bool ok) { if (!ok) throw std::logic_error("control failed"); }
int gram_errors(bool twisted) {
    int errors=0;
    for (int i=0;i<38;i++) for (int j=0;j<=i;j++) {
        Block gram{};
        for (int k=0;k<38;k++) {
            Block a=entry(i,k,twisted)*F, b=entry(j,k,twisted)*F;
            check(std::abs(a.a)==1 && std::abs(a.b)==1 &&
                  std::abs(a.c)==1 && std::abs(a.d)==1);
            gram=gram+a*transpose(b);
        }
        if (!(gram==(i==j ? 76 : 0)*I)) ++errors;
    }
    return errors;
}
void check_conference() {
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
        Block gram{};
        for (int k=0;k<10;k++) gram=gram+conference[i][k]*transpose(conference[j][k]);
        check(gram==(i==j ? 9 : 0)*I);
    }
}
using Words = std::array<std::array<int,5>,4>;
int gs_entry(const Words &words,int r,int c) {
    // Codes +/-1,...,+/-4 specify A,B,C,D with the Goethals-Seidel signs.
    constexpr int table[4][4]={{1,2,3,4},{-2,1,-4,3},{-3,4,1,-2},{-4,-3,2,1}};
    int a=r/5,b=c/5,i=r%5,j=c%5,code=table[a][b];
    int shift=j-i;
    if (a!=b) shift=(a==0 || b==0) ? -(i+j) : i+j;
    return (code<0 ? -1 : 1)*words[std::abs(code)-1][(shift+10)%5];
}
void gs_control(const Words &words,int golay_length) {
    std::array<std::array<int,2>,10> rows{},columns{};
    std::array<bool,20> assigned{};
    int groups=0;
    for (int r=0;r<20;r++) {
        if (assigned[r]) continue;
        check(groups<10);
        auto &holes=columns[groups];
        int zeros=0;
        for (int j=0;j<20;j++) if (gs_entry(words,r,j)==0) {
            check(zeros<2);
            holes[zeros++]=j;
        }
        check(zeros==2);
        int companions=0;
        for (int s=r;s<20;s++) if (gs_entry(words,s,holes[0])==0 &&
                                      gs_entry(words,s,holes[1])==0) {
            check(!assigned[s] && companions<2);
            rows[groups][companions++]=s;
            assigned[s]=true;
        }
        check(companions==2);
        ++groups;
    }
    check(groups==10);
    for (int r=0;r<20;r++) for (int s=0;s<=r;s++) {
        int gram=0;
        for (int j=0;j<20;j++) gram+=gs_entry(words,r,j)*gs_entry(words,s,j);
        check(gram==(r==s ? 18 : 0));
    }
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
        auto r=rows[i],c=columns[j];
        Block raw{gs_entry(words,r[0],c[0]),gs_entry(words,r[0],c[1]),
                  gs_entry(words,r[1],c[0]),gs_entry(words,r[1],c[1])};
        conference[i][j]=half(raw*F);
        check(conference[i][j]*transpose(conference[i][j])==(i==j ? 0 : 1)*I);
    }
    for (int i=0;i<9;i++) {
        Block left=transpose(conference[i][9]);
        for (int j=0;j<10;j++) conference[i][j]=left*conference[i][j];
    }
    for (int j=0;j<9;j++) {
        Block right=transpose(conference[9][j]);
        for (int i=0;i<10;i++) conference[i][j]=conference[i][j]*right;
    }
    check_conference();
    int errors=gram_errors(true);
    check(errors==0);
    std::cout << "Golay g=" << golay_length << " -> W(20,18) -> D4(10) -> H(76): "
              << errors << " Gram errors\n";
}
using Word = std::vector<int>;
using Pair = std::array<Word,2>;

Word signs(const std::string &text) {
    Word result;
    for (char c:text) {
        check(c=='1' || c=='-');
        result.push_back(c=='1' ? 1 : -1);
    }
    return result;
}
template<std::size_t Count>
void check_correlations(const std::array<Word,Count> &words,int weight,bool periodic) {
    int n=static_cast<int>(words[0].size());
    for (const Word &w:words) check(static_cast<int>(w.size())==n);
    for (int shift=0;shift<n;shift++) {
        int sum=0;
        for (const Word &w:words) for (int i=0;i<(periodic ? n : n-shift);i++)
            sum+=w[i]*w[(i+shift)%n];
        check(sum==(shift==0 ? weight : 0));
    }
}
Pair turyn_product(const Pair &a,const Pair &b) {
    Pair out;
    for (std::size_t i=0;i<a[0].size();i++) {
        int agree=(a[0][i]+a[1][i])/2, differ=(a[0][i]-a[1][i])/2;
        for (std::size_t j=0;j<b[0].size();j++) {
            std::size_t k=b[0].size()-1-j;
            out[0].push_back(agree*b[0][j]+differ*b[1][j]);
            out[1].push_back(agree*b[1][k]-differ*b[0][k]);
        }
    }
    return out;
}

// Both target primes have quadratic nonresidue 3. Use w^2=3.
struct FieldElement { long long x,y; };
FieldElement multiply(FieldElement a,FieldElement b,int q) {
    return {(a.x*b.x+3*a.y*b.y)%q,(a.x*b.y+a.y*b.x)%q};
}
FieldElement power(FieldElement a,int n,int q) {
    FieldElement b{1,0};
    while (n>0) {
        if (n%2) b=multiply(b,a,q);
        a=multiply(a,a,q);
        n/=2;
    }
    return b;
}
void check_yamada(int q,int scalar) {
    int n=(q+1)/2, order=q*q-1;
    Word character(q,-1);
    character[0]=0;
    for (int x=1;x<q;x++) character[x*x%q]=1;
    check(character[3]==-1);
    FieldElement generator{scalar,1};
    auto identity=[](FieldElement a) { return a.x==1 && a.y==0; };
    check(identity(power(generator,order,q)));
    int remaining=order;
    for (int p=2;p<=remaining;p++) if (remaining%p==0) {
        check(!identity(power(generator,order/p,q)));
        while (remaining%p==0) remaining/=p;
    }
    FieldElement beta=power(generator,n,q), alpha{1,0}, step=power(generator,4,q);
    Pair rows;
    for (int j=0;j<n;j++) {
        rows[0].push_back(character[(2*beta.x)%q]);
        rows[1].push_back(character[(2*alpha.x)%q]);
        check(std::abs(rows[0].back())==(j==0 ? 0 : 1) && std::abs(rows[1].back())==1);
        beta=multiply(beta,step,q);
        alpha=multiply(alpha,step,q);
    }
    for (const Word &row:rows) for (int j=0;j<n;j++) check(row[j]==row[(n-j)%n]);
    check_correlations(rows,q,true);
}
void check_target(const Pair &pair,int suffix,int q,int generator_scalar) {
    int g=static_cast<int>(pair[0].size());
    for (const Word &w:pair) for (int x:w) check(std::abs(x)==1);
    check_correlations(pair,2*g,false);
    std::array<Word,4> words{pair[0],pair[0],pair[1],pair[1]};
    const std::array<Word,4> tails=(suffix==1)
        ? std::array<Word,4>{{{1},{-1},{0},{0}}}
        : std::array<Word,4>{{{1,1,-1},{-1,-1,1},{1,0,1},{-1,0,-1}}};
    int t=g+suffix;
    check(4*t-3==q);
    for (std::size_t j=0;j<4;j++) words[j].insert(words[j].end(),tails[j].begin(),tails[j].end());
    check_correlations(words,4*t-2,false);
    check_yamada(q,generator_scalar);
    std::cout << "g=" << g << ", padded length=" << t << ", weight=" << 4*t-2
              << ", Yamada length=" << (q+1)/2 << ", q=" << q
              << ": all correlations and entry patterns verified\n";
}
void target_controls() {
    // Craigen, Holzmann and Kharaghani, "Complex Golay sequences:
    // structure and applications", equation (1).
    Pair two{signs("11"),signs("1-")};
    Pair ten{signs("11-1-1--11"),signs("11-11111--")};
    Pair twenty_six{signs("1111-11--1-1-1--1-111--111"),signs("1111-11--1-11111-1---11---")};
    check_correlations(two,4,false);
    check_correlations(ten,20,false);
    check_correlations(twenty_six,52,false);
    Pair first=ten;
    for (int i=0;i<5;i++) first=turyn_product(first,two);
    check_target(first,3,1289,4);
    Pair second=turyn_product(turyn_product(ten,twenty_six),two);
    check_target(second,1,2081,3);
}
int main(int argc,char **argv) {
    if (argc==2 && std::string(argv[1])=="--targets") {
        target_controls();
        return 0;
    }
    if (argc!=1) {
        std::cerr << "usage: kumar-dihedral-control [--targets]\n";
        return 2;
    }
    for (int i=0;i<10;i++) for (int j=0;j<10;j++) conference[i][j]=paley_input(i,j);
    check_conference();
    int positive=-1,negative=-1;
    for (int j=2;j<9;j++) {
        if (det(conference[0][j])==1) positive=j;
        else negative=j;
    }
    check(positive>=0 && negative>=0);
    int cycle=det(conference[9][positive])*det(conference[0][positive])*
              det(conference[0][negative])*det(conference[9][negative]);
    check(cycle==-1);
    int corrected=gram_errors(true), plain=gram_errors(false);
    check(corrected==0 && plain>0);
    std::cout << "conference Gram = 9I; determinant product " << cycle
              << " on rows infinity,0 and columns " << positive << ',' << negative
              << "\nH(76) lower-triangular block Gram errors: twisted=" << corrected
              << " untwisted=" << plain << '\n';
    // Theorem 7(i), X=111-, Y=11-1; (ii), X=11, Y=1-.
    gs_control(Words{{{1,1,1,-1,1},{1,1,1,-1,-1},{1,1,-1,1,0},{1,1,-1,1,0}}},4);
    gs_control(Words{{{1,1,1,1,-1},{1,1,-1,-1,1},{1,-1,1,0,1},{1,-1,-1,0,-1}}},2);
}
