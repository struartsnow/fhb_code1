#include<bits/stdc++.h>
#define Mid (l+r>>1)
#define Ls no<<1,l,Mid
#define Rs no<<1|1,Mid+1,r
using namespace std;
void build(int no,int l,int r) {
	if (l==r) {
		key[no]=-p[l]; return;
	}
	build(Ls),build(Rs);
	key[no]=Min(key[no<<1],key[no<<1|1]);
}
signed main () {
	read(n);
	for (int i=1;i<=n;i++) read(p[i]);
	build(1,1,n);
	for (int )
	read(q);
	for (int i=1;i<=p;i++) read(q[i].fi),read(q[i].se),id[i]=i;
	sort(id+1,id+p+1,[&](int _x,int _y){return q[_x]<q[_y];});
	sort(q+1,q+n+1);
	
}
