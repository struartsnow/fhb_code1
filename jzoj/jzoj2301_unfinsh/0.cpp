#include<bits/stdc++.h>
using namespace std;
#define N 200007
struct Node{
	int siz,a[N];
	void init(int n){
		siz=n;
		for (int i=1;i<=n;i++) a[i]=i;
	}
	void res() {
		static Node xxoo;
		xxoo=*this;
		for (int i=1;i<=siz;i++) a[xxoo.a[i]]=i;
	}
}C,anw;
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
Node operator * (const Node x,const Node y){
     Node anw;
	 anw.siz=x.siz;
	 for (int i=1;i<=x.siz;i++) anw.a[i]=y.a[x.a[i]];
	 return anw; 
}
long long m,y;
int n,q,a[N],b[N],st,pos[N],top,ang[N],ans[N];
signed main () {
	freopen("sim.in","r",stdin);
	read(n); read(q); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=0;i<q;i++) read(b[i]);
    for (int i=1;i<=n;i++) pos[a[i]]=i;
	C.init(n); m--;
	for (int i=1;i<q;i++)  swap(C.a[b[i-1]],C.a[b[i]]);
	swap(C.a[b[0]],C.a[b[q-1]]);
	C.res();
	for (anw.init(n),y=m/q;y;y>>=1,C=C*C) 
	   if (y&1) anw=anw*C;
	C=anw;
	C.res();
	m%=q;  
	for (int i=1;i<=m;i++) swap(C.a[b[i-1]],C.a[b[i]]);
	C.res();
	swap(pos[a[1]],pos[b[0]]);
	for (int i=1;i<=n;i++) ang[C.a[i]]=pos[i];
	for (int i=1;i<=n;i++) ans[ang[i]]=i;
	for (int i=1;i<=n;i++) writel(ans[i]);
}
