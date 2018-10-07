#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
    static char c; static int b;
    for (b=1,c=getchar();!isdigit(c);c=getchar())if (c=='-') b=-1;
    for (x=0;isdigit(c);c=getchar())x=x*10+c-48; x=x*b;
}
inline void read(char &c){
    for (c=getchar();c<'A'||c>'Z';c=getchar());
//    for (x=0;isdigit(c);c=getchar())x=x*10+c-48; x=x*b;
}
void write(int x){if (x<10) {putchar('0'+x); return;} write(x/10); putchar('0'+x%10);}
inline void writeln(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar('\n'); }
inline void writel(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar(' '); }
struct Rect{
    int type,x,y,d;
    void Read(){
        read(x); read(y); read(d);
    }
}tp[200007];
#define LL long long
#define N 3005
#define M 6020
LL sum1[N][N];
LL sum2[M][M];
int n,t;
#define code1(x) (x+1501)
#define code2(x) (x+3005)
#define pan(x,y) (t=x+y,x-=y,y=t)
void work(){
    for (int i = 1; i <= n; i++){
        Rect& r = tp[i];
        r.d >>= 1;
        if (r.type){
            sum1[code1(r.x - r.d)][code1(r.y - r.d)]++;
            sum1[code1(r.x - r.d)][code1(r.y + r.d)]--;
            sum1[code1(r.x + r.d)][code1(r.y - r.d)]--;
            sum1[code1(r.x + r.d)][code1(r.y + r.d)]++;
        } else {
            int x1 = r.x - r.d, y1 = r.y; pan(x1, y1);
            int x2 = r.x, y2 = r.y + r.d; pan(x2, y2);
            int x3 = r.x, y3 = r.y - r.d; pan(x3, y3);
            int x4 = r.x + r.d, y4 = r.y; pan(x4, y4);
            sum2[code2(x1)][code2(y1)]++;
            sum2[code2(x2)][code2(y2)]--;
            sum2[code2(x3)][code2(y3)]--;
            sum2[code2(x4)][code2(y4)]++;
        }
    }
    for (int i = 1; i < N; i++) sum1[0][i] += sum1[0][i - 1];
    for (int i = 1; i < N; i++){
        sum1[i][0] += sum1[i - 1][0];
        for (int j = 1; j < N; j++)
            sum1[i][j] += sum1[i - 1][j] + sum1[i][j - 1] - sum1[i - 1][j - 1];
    }
    for (int i = 1; i < M; i++){
        sum2[i][0] += sum2[i - 1][0];
        for (int j = 1; j < M; j++)
            sum2[i][j] += sum2[i - 1][j] + sum2[i][j - 1] - sum2[i - 1][j - 1];
    }
    int ans = 0;
    for (int i = 1; i < N; i++){
        for (int j = 1; j < N; j++){
            if (sum1[i][j]) ans += 4;
            else {
                int x = i - 1501;
                int y = j - 1501;
                pan(x, y);
                if (sum2[code2(x)][code2(y)]) ans++;
                if (sum2[code2(x)][code2(y + 1)]) ans++;
                if (sum2[code2(x - 1)][code2(y + 1)]) ans++;
                if (sum2[code2(x - 1)][code2(y)]) ans++;
            }
        }
    }
    printf("%.2f", (double)ans / 4);
} 
char C;
signed main () {
	freopen("skss.in","r",stdin);
	freopen("skss.out","w",stdout);
	read(n);
	for (int i=1;i<=n;i++) {
		read(C);
		tp[i].type=C=='A';
		tp[i].Read();
	}
	work();
}
