#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#define rep(i, l, r) for(int i=l; i<=r; i++)
#define down(i, l, r) for(int i=l; i>=r; i--)
#define travel(x) for(edge *p=fir[x]; p; p=p->n)
#define clr(x, c) memset(x, c, sizeof(x))
#define maxn 100009
#define Q 1000000007
#define inf 0x7fffffff
#define ll long long
#define ull unsigned long long
using namespace std;
int a[maxn], b[maxn], al, bl, k[maxn][16], m[maxn];
int cal(int *a, int l)
{
    rep(i, 0, 15) m[i]=0; int now=0;
    while (l)
    {
        rep(i, 0, a[l]-1) rep(j, 0, 15) m[j^now^i]=(m[j^now^i]+k[l-1][j])%Q;
        now^=a[l];
        l--;
    }
    now=0;
    rep(i, 0, 15) now=(1LL*now+1LL*i*m[i])%Q;
    return now;
}
void Init()
{
    rep(i, 0, 9) k[1][i]=1; k[0][0]=1;
    rep(i, 2, 100002) 
    {
        rep(o, 1, 9) rep(j, 0, 15) k[i][j^o]=(k[i][j^o]+k[i-1][j])%Q;
        rep(j, 0, 15) k[i][j]=(k[i][j]+k[i-1][j])%Q;
    }
}
int main()
{
    Init();
    int t, tt=0; 
	cin>>t;
	while (tt++<t)
    {
        char ch=0; al=bl=0; clr(a,0); clr(b,0);
        while (!isdigit(ch)) ch=getchar();
        while (isdigit(ch)) a[++al]=ch-'0', ch=getchar();
        rep(i, 1, al/2) swap(a[i], a[al-i+1]);
        while (!isdigit(ch)) ch=getchar();
        while (isdigit(ch)) b[++bl]=ch-'0', ch=getchar();
        rep(i, 1, bl/2) swap(b[i], b[bl-i+1]);
        
        int now=1; b[1]++;
        while (b[now]>9) b[now]-=10, now++, b[now]++;
        if (now>bl) bl=now;
        
        printf("Case #%d: %d\n", tt, (cal(b,bl)-cal(a,al)+Q)%Q);
    }
    return 0;
}