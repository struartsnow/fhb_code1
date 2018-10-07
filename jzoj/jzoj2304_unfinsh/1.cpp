#include<bits/stdc++.h>
#define Mid (l+r>>1)
#define Ls no<<1,l,Mid
#define Rs no<<1|1,Mid+1,r
#define N 700007
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int Mi1[N],Ma1[N],a[N],Mi2[N],Ma2[N],pos[N];
bool operator == (const pii & A,const pii & B){
	return A.fi==B.fi&&A.se==B.se;
}
map<pii,pii> Map;
void build(int no,int l,int r) {
	if (l==r) {
		Mi1[no]=a[l]; Ma1[no]=a[r];
		Mi2[no]=pos[l]; Ma2[no]=pos[r];
		return;
	}
	build(Ls); build(Rs);
	Mi1[no]=Min(Mi1[no<<1],Mi1[no<<1|1]);
	Mi2[no]=Min(Mi2[no<<1],Mi2[no<<1|1]);
	Ma1[no]=Max(Ma1[no<<1],Ma1[no<<1|1]);
	Ma2[no]=Max(Ma2[no<<1],Ma2[no<<1|1]);
}
#define inf 1e9
int I1,I2,A1,A2,tot;
pii p[N];
#define sight(x) ('0'<=x&&x<='9')
template <class T>
inline void read(T &x){
    static char c;
    for (c=getchar();!sight(c);c=getchar());
    for (x=0;sight(c);c=getchar())x=x*10+c-48;
}
void write(int x){if (x<10) {putchar('0'+x); return;} write(x/10); putchar('0'+x%10);}
inline void writeln(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar('\n'); }
inline void writel(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar(' '); }
void quinit(){
	I1=inf; I2=inf; A1=-inf; A2=-inf;
}
void que(int no,int l,int r,int L,int R) {
	if (L<=l&&r<=R) {
		I1=Min(I1,Mi1[no]); I2=Min(I2,Mi2[no]);
		A1=Max(A1,Ma1[no]); A2=Max(A2,Ma2[no]); return;
	}
	if (L<=Mid) que(Ls,L,R);
	if (R> Mid) que(Rs,L,R);
}
int n,q,x,y,X,Y;
signed main () {
	freopen("5.in","r",stdin);
	freopen("ffs.out","w",stdout);
	read(n); 
	for (int i=1;i<=n;i++) read(a[i]),pos[a[i]]=i;
	build(1,1,n);
	read(q);
	while (q--) {
		read(x); read(y); p[tot=0]=pii(x,y);
		while (quinit(),que(1,1,n,x,y),A1-I1!=y-x) {
			if (Map.count(pii(x,y))) x=Map[pii(x,y)].fi,y=Map[pii(x,y)].se;
			X=I1,Y=A1,quinit(),que(1,1,n,X,Y);
			x=I2,y=A2;
			p[++tot]=pii(x,y);
		}
		writel(x),writeln(y);
		for (int i=0;i<tot;i++) Map[p[i]]=pii(x,y);
	} 
	return 0;
}
