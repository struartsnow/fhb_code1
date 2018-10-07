#include<bits/stdc++.h>
#define LL long long
#define N  204007

using namespace std;
int n,a[N],now,p,pos[N],id[N]; LL seg;
template <class T>
inline void read(T &x){
    static char c;
    for (c=getchar();!isdigit(c);c=getchar());
    for (x=0;isdigit(c);c=getchar())x=x*10+c-48;
}
void write(int x){if (x<10) {putchar('0'+x); return;} write(x/10); putchar('0'+x%10);}
inline void writeln(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar('\n'); }
inline void writel(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar(' '); }
void sol(int *a,LL otk){
	for (int i=1;i<=n;i++) a[i]=0;
	seg=n;
	while (seg&&otk>=seg-1) {
		seg--; a[n-seg]=seg+1; otk-=seg;
	}
	if (otk) {
	  a[n-otk]=seg; 
	} now=0;
	for (int i=1;i<=n;i++) if (!a[i]) a[i]=++now;
}
int ans,w[N],anw;
LL r,top,ST;
int dos(LL otk) {
	if (otk>1ll*n*(n-1)/2) return -111111111;
	sol(a,otk);
	ans=0;
	for (int i=2;i<=n;i++) 
	  if (w[a[i]]-1.0*ans/(i-1)*n>1e-7) ans++;
	return ans;
}
void out(LL otk) {
	sol(a,otk);
	for (int i=1;i<=n;i++)  writel(pos[a[i]]); puts("");
//	for (int i=1;i<n;i++)  {if (a[i]!=a[i+1]+1) {cerr<<"sb "<<i<<endl;exit(0);}}//writel(a[i]); puts("");
	cerr<<(dos(otk))<<endl;
}
signed main () {
	freopen("cs.in","r",stdin);
	freopen("cs.out","w",stdout);
	read(n); read(p);
//	out(1);
//    for (int i=0;i<=n*(n-1)/2;i++) 
//     out(i);
	for (int i=1;i<=n;i++) read(w[i]),pos[i]=i;
	sort(pos+1,pos+n+1,[&](int _x,int _y){return w[_x]<w[_y];});
//	for (int i=1;i<=n;i++) id[pos[i]]=i;
	sort(w+1,w+n+1);
	anw=dos(0);
	if (p>=anw) {out(0); return 0;}
//	l=0; r=n*(n-1)/2;
    r=1ll<<50; ST=0;
	while (r) {
		if (dos(ST+r)>p) 
		  ST+=r;
		r>>=1; 
	}
	top=dos(ST)-p<p-dos(ST+1)?ST:ST+1;
//	out(top-1);
	out(top);
//	out(top+1);
	return 0; 
}
