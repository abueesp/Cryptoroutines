##Credits: http://web.mit.edu/arayo/www/bignums.html
 
# carnahan.c #
 
#include <stdlib.h>

int a(int k,int n,int *x) {
int *y,i,m=0;
y = malloc(2*n);
if(n==1)return *x+9;
else{
for(i=0;i<n;i++){
if(!x[i]){m++;n--;}
y[i]=i>1?b(k-1,x[m+i]):(i?(n-1?x[m+i]-1:0):x[m+i]);
}
for(i=0;i<n;i++)y[n+i]=i?a(k,n,y):*y-1;
i=a(k,n,y+n);
free(y);
return i;
}
}

int b(int k, int n){
int *v,i;
v=malloc(n);
for(i=0;i<n;i++)v[i]=n;
i=k?a(k,n,v):n;
free(v);
return i;
}

int d(int l,int m,int n){
return l?(m?d(l-1,d(l,m-1,n),d(l,m-1,n)):d(l-1,d(l,l-1,n),d(l,l-1,n))):(m?d(0,m-1,d(0,m,n-1)):b(n,n));
}

int main(){
return d(d(d(9999,9,9),9,9),9,9);
}
 
 
 
 
# chan.c #
 
int A(int y, int z) { return !y?z+1:!z?A(y-1,1):A(y-1,A(y,z-1)); }

#define _(A, B) int B(int y, int z) { return !y?A(z+1,z+1):!z?\
B(y-1,1):B(y-1,B(y,z-1)); }

_(A,B)_(B,C)_(C,D)_(D,E)_(E,F)_(F,G)_(G,H)_(H,I)_(I,J)_(J,K)_(K,L)
_(L,M)_(M,N)_(N,O)_(O,P)_(P,Q)_(Q,R)_(R,S)_(S,T)_(T,U)_(U,V)_(V,W)
_(W,X)_(X,Y)_(Y,Z)_(Z,a)_(a,b)_(b,c)_(c,d)_(d,e)_(e,f)_(f,g)_(g,h)
_(h,i)_(i,j)_(j,k)_(k,l)_(l,m)_(m,n)_(n,o)_(o,p)_(p,q)_(q,r)_(r,s)
_(s,t)_(t,u)_(u,v)_(v,w)_(w,x)

int main(void) { return x(99999, 99999); }

 
 
 
 
# chan-2.c #
 
int A(int x, int y, int z)
{ return !x?y+z:!z?y:A(x-1,y,A(x,y,z-1)); }

#define B(x, y) A(y, y, y)

#define _(F, G) int G(int x, int y) \
{ return !x?G(F(0,y),F(0,y)):x==1?F(0,y):G(x-1,F(0,y)); }

_(B,C)_(C,D)_(D,E)_(E,F)_(F,G)_(G,H)_(H,I)_(I,J)_(J,K)_(K,L)
_(L,M)_(M,N)_(N,O)_(O,P)_(P,Q)_(Q,R)_(R,S)_(S,T)_(T,U)_(U,V)
_(V,W)_(W,X)_(X,Y)_(Y,Z)_(Z,a)_(a,b)_(b,c)_(c,d)_(d,e)_(e,f)
_(f,g)_(g,h)_(h,i)_(i,j)_(j,k)_(k,l)_(l,m)_(m,n)_(n,o)_(o,p)
_(p,q)_(q,r)_(r,s)_(s,t)_(t,u)_(u,v)_(v,w)

int main(void)
{ return w(0, 999999999999999999999999999999999999999); }
 
 
 
 
# chan-3.c #
 
int A(int x, int y, int z)
{ return !x?y+z:!z?y:A(x-1,y,A(x,y,z-1)); }

int B(int z)
{ return A(z,z,z); }

int C(int t, int u, int v, int w, int x, int y, int z)
{ return !t?B(z):
!u?B(C(t,C(t-1,0,0,0,0,0,B(z)),v,w,x,y,B(z))):u==1?B(z):
!v?B(C(t,u,C(t,u-1,0,0,0,0,B(z)),w,x,y,B(z))):v==1?B(z):
!w?B(C(t,u,v,C(t,u,v-1,0,0,0,B(z)),x,y,B(z))):w==1?B(z):
!x?B(C(t,u,v,w,C(t,u,v,w-1,0,0,B(z)),y,B(z))):x==1?B(z):
!y?B(C(t,u,v,w,x,C(t,u,v,w,x-1,0,B(z)),B(z))):y==1?B(z):
   B(C(t,u,v,w,x,y-1,B(C(t,u,v,w,x-1,0,B(z))))); }

int main(void)
{ return C(9999, 0, 0, 0, 0, 0, 9999); }
 
 
 
 
# dovey.c #
 
int main(void)
{  return ~0u >> 1;
}
 
 
 
 
# edelson.c #
 
int main(void)
{
    return (unsigned int) -1;
}
 
 
 
 
# f.c #
 
unsigned int u;int main(void){return --u;}
 
 
 
 
# harper.c #
 
#define I int
#define w while
#define r return
I l(I x){I y=x;w(y--)x*=x;r x;}
I k(I x,I y){w(y--)x*=k(x,y)*l(x);r x;}
I j(I x,I y){w(y--)x*=j(x,y)*k(x,y);r x;}
I i(I x,I y){w(y--)x*=i(x,y)*j(x,y);r x;}
I h(I x,I y){w(y--)x*=h(x,y)*i(x,y);r x;}
I g(I x,I y){w(y--)x*=g(x,y)*h(x,y);r x;}
I f(I x,I y){w(y--)x*=f(x,y)*g(x,y);r x;}
I e(I x,I y){w(y--)x*=e(x,y)*f(x,y);r x;}
I d(I x,I y){w(y--)x*=d(x,y)*e(x,y);r x;}
I c(I x,I y){w(y--)x*=c(x,y)*d(x,y);r x;}
I b(I x,I y){w(y--)x*=b(x,y)*c(x,y);r x;}
I a(I x,I y){w(y--)x*=a(x,y)*b(x,y);r x;}
I main(void){r a(9<<99999999,9<<99999999);}
 
 
 
 
# ioannis.c #
 
int a(int k,int m,int n)
{if (k==1) return(m+n);
else {if (n==1) return m;
else return a(k-1,m,a(k,m,n-1));}}
#define d(n) a(n,n,n)
int main(void)
{return d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(
d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(
d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(
d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(d(
d(d(d(d(d(d(d(d(9)))))))))))))))))))))))))))))))))))))))
))))))))))))))))))))))))))))))))))))))))))))))))))))))))
)))))))))))))))))))));}
 
 
 
 
# loader.c #
 
#define R { return
#define P P (
#define L L (
#define T S (v, y, c,
#define C ),
#define X x)
#define F );}

int r, a;
P y, X
   R y - ~y << x;
}
Z (X
   R r = x % 2 ? 0 : 1 + Z (x / 2 F
L X
   R x / 2 >> Z (x F
#define U = S(4,13,-4,
T  t)
{
   int
      f = L t C         
      x = r;
   R
         f - 2 ?
         f > 2 ?
         f - v ? t - (f > v) * c : y :
         P f, P T  L X  C 
                          S (v+2, t  U y C  c, Z (X )))
         :
         A (T  L X  C 
                T  Z (X ) F
}
A (y, X
   R L y) - 1
      ? 5 << P y, X 
      : S (4, x, 4, Z (r) F
#define B (x /= 2) % 2 && (
D (X 
{
   int
      f,
      d,
      c = 0,
      t = 7,
      u = 14;
   while (x && D (x - 1 C  B 1))
      d = L L D (X ) C
         f = L r C
         x = L r C
         c - r || (
            L u) || L r) - f ||
            B u = S (4, d, 4, r C 
                   t = A (t, d) C
            f / 2 & B  c = P d, c C 
                              t  U t C 
                              u  U u) )
             C
         c && B
            t = P
               ~u & 2 | B
                  u = 1 << P L c C  u) C 
               P L c C  t) C
            c = r  C
         u / 2 & B 
            c = P t, c C 
            u  U t C 
            t = 9 );
   R a = P P t, P u, P x, c)) C 
                                a F
}
main ()
   R D (D (D (D (D (99)))) F
 
 
 
 
# marxen.c #
 
typedef int	J;
J P(J x,J y)	{ return x+y ? x%2 + y%2*2 + P(x/2,y/2)*4 : 0 ;}
J H(J z)	{ return z ? z%2 + 2*H(z/4) : 0 ;}
J I(J f,J e,J r){ return f ? P(P(f,e),r) : r ;}
J M(J x,J e)	{ return x ? I(x%2, M(e,0), M(x/2, e+1)) : 0 ;}
J D(J,J);	 
J E(J f,J e,J r,J b)
{
    return e ? E(1, D(e,b), I(b-1, D(e,b), I(f-1,e,r)), b) : I(f-1,e,r) ;
}
J D(J x,J b)	{ return x ? E( H(H(x)), H(H(x)/2), H(x/2), b) : 0 ;}
J F(J x,J b)	{ return x ? F(D(x,b+1),b+1) : b ;}
J G(J x)	{ return F(M(x,9), 9) ;}
J f(J n,J x)	{ return n ? f(n-1, G(x ? f(n,x-1) : n)) : G(x) ;}
J g(J x)	{ return f(x,x) ;}
J h(J n,J x)	{ return n ? h(n-1, g(x ? h(n,x-1) : n)) : g(x) ;}
J main(void)	{ return h(g(9),9) ;}
 
 
 
 
# pete.c #
 
int main(void)
{
    int intmax = 1;

    do{
        intmax <<= 1;
    }while(intmax < intmax << 1);
    intmax += intmax - 1;    
    return intmax;
}
 
 
 
 
# pete-2.c #
 
int main(void)
{
    int intmin = 0x4000;

    while(intmin < intmin << 1)
        intmin <<= 1;
    return intmin << 1;
}
 
 
 
 
# pete-3.c #
 
int main() 
{               
    return     
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 <<
        9 << 9 << 9 << 9 << 9 << 9 << 9 << 9 << 99;  
}
 
 
 
 
# pete-4.c #
 
#define F(Q,R,P) Q(int x){int i=x;while(i--)x=R(x,x);return x;}\
P(int L,int x){int i=x;if(L--)while(i--)x=P(L,x);return Q(x);}

#define Y(A,z,B,C,D,E,G,H,I,J,K,M,N,O,S,T,U,V,W)\
F(A,z,B)F(C,B,D)F(E,D,G)F(H,G,I)F(J,I,K)F(M,K,N)F(O,N,S)F(T,S,U)F(V,U,W)

Z(int L,int x)
{
    int i = x;

    if(L--)
        while(i--)
            x = Z(L,x);
    return x << x;
}

Y(a,Z,b,c,d,e,g,h,X,j,k,m,n,o,s,t,u,v,w)
Y(Aa,w,Ba,Ca,Da,Ea,Ga,Ha,Ia,Ja,Ka,Ma,Na,Oa,Sa,Ta,Ua,Va,Wa)
Y(Ab,Wa,Bb,Cb,Db,Eb,Gb,Hb,Ib,Jb,Kb,V,U,W,T,S,O,N,M)
F(A,M,B)
F(C,B,D)
F(E,D,G)
F(H,G,I)
F(J,I,K)

int main()
{
    return K(99999,9);
}
 
 
 
 
# pete-5.c #
 
int C = 999;

A(int S,int R,int P,int O,int N,int M,int L,int K,int J,int F,int E)
{
    int D = C;
    
    if(E--)
        while(D--)
            C = A(S,R,P,O,N,M,L,K,J,F,E);
    return 
          F-- ? A(S,R,P,O,N,M,L,K,J,F,C)
        : J-- ? A(S,R,P,O,N,M,L,K,J,C,C)
        : K-- ? A(S,R,P,O,N,M,L,K,C,C,C)
        : L-- ? A(S,R,P,O,N,M,L,C,C,C,C)
        : M-- ? A(S,R,P,O,N,M,C,C,C,C,C)
        : N-- ? A(S,R,P,O,N,C,C,C,C,C,C)
        : O-- ? A(S,R,P,O,C,C,C,C,C,C,C)
        : P-- ? A(S,R,P,C,C,C,C,C,C,C,C)
        : R-- ? A(S,R,C,C,C,C,C,C,C,C,C)
        : S-- ? A(S,C,C,C,C,C,C,C,C,C,C)
        : C * C;
}

#define Q ,C,C,C,C,C,C,C,C,C,C)
main()
{return A(A(A(A(A(A(A(A(A(A(A(A(A(A(A(A(C Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q;}
 
 
 
 
# pete-6.c #
 
#define M E H,h,g,f
#define L E G,p,o,n
#define K E w,v
#define J ,B,B
#define I J J
#define H G,p,o,n,m,l,k,j,i
#define G w,v,u,t,s,r,q
#define F I I
#define E --?A(
#define D ,B):
#define C ,int

int B = 9 << 9999;

A(int w C v C u C t C s C r C q C p C o C n C m C l
        C k C j C i C h C g C f C e C d C c C b C a)
{
    int y = B;

    if(a--)
        while(y--)
            B = A(H,h,g,f,e,d,c,b,a);
        return 
            b M,e,d,c,b D
            c M,e,d,c,B D
            d M,e,d J D
            e M,e J,B D
            f M I D
            g E H,h,g I,B D
            h E H,h I J D
            i E H I J,B D
            j L,m,l,k,j F D
            k L,m,l,k F,B D
            l L,m,l F J D
            m L,m F J,B D
            n L F I D
            o E G,p,o F I,B D
            p E G,p F I J D
            q E G F I J,B D
            r K,u,t,s,r F F D
            s K,u,t,s F F,B D
            t K,u,t F F J D
            u K,u F F J,B D
            v K F F I D
            w E w F F I,B D
            B * B;
}

main(){return A(B I F F J);}
 
 
 
 
# pete-7.c #
 
#define F (9<<(9<<(9<<(9<<
#define D F F F F
#define E ))))))))))))))))

#define N D D 99 E E 

int B = N;

f(int *a)
{   
    int C = B, b[N], n = N;
    
    while(n--)
        b[n] = a[n];
    n = N - 1;
    if(b[n]--)
        while(C--)
            B = f(b);   
    while(n-- && !(b[n + 1] = B, b[n]--))
        ;   
    return n == -1 ? B * B : f(b);
}

main()
{
    int a[N] = {N};     

    return f(a);
}
 
 
 
 
# pete-8.c #
 
#define Z (9<<(9<<
#define Y Z Z Z Z Z Z Z Z
#define W ))))))))))))))))

#define Q Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y
#define O W W W W W W W W W W W W W W W W W

#define P Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q
#define M O O O O O O O O O O O O O O O O O

#define L P P P P P P P P P P P P P P P P P
#define K M M M M M M M M M M M M M M M M M

#define H L L L L L L L L L L L L L L L L L
#define J K K K K K K K K K K K K K K K K K

#define A H H H H H H H H H H H H H H H H H
#define D J J J J J J J J J J J J J J J J J

#define X A A A A A A A A A A A A A A A A A 999 D D D D D D D D D D D D D D D D D

int B = X;

f(int* a)
{
    int C = B, b[X], n = X;
    
    while(n--)
        b[n] = a[n];
    if(b[n = X - 1]--)
        while(C--)
            B = f(b);
    while(n && !(b[n] = B, b[--n]--))
        ;
    return n ? f(b) : B * B;
}

main()
{
    int a[X] = {X};
    
    return f(a);
}
 
 
 
 
# pete-9.c #
 
#define Z (9<<(9<<
#define Y Z Z Z Z Z Z Z Z
#define W ))))))))))))))))

#define Q Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y Y
#define O W W W W W W W W W W W W W W W W W

#define P Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q Q
#define M O O O O O O O O O O O O O O O O O

#define L P P P P P P P P P P P P P P P P P
#define K M M M M M M M M M M M M M M M M M

#define H L L L L L L L L L L L L L L L L L
#define J K K K K K K K K K K K K K K K K K

#define A H H H H H H H H H H H H H H H H H
#define D J J J J J J J J J J J J J J J J J

#define X A A A A A A A A A A A A A A A A A 99\
          D D D D D D D D D D D D D D D D D

int B = X;

f(int* a)
{
    int C = B, b[X], n = X;
    
    while(n--)
        b[n] = a[n];
    if(b[n = X - 1]--)
        while(C--)
            B = f(b);
    while(n && !(b[n] = B, b[--n]--))
        ;
    return n ? f(b) : B * B;
}

main()
{
    int a[X] = {X};
    
    return f(a);
}
