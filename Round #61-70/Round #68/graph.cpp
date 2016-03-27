#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <string>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define MAXN (50+10)
#define MAXM (500000)
#define Ri(a) scanf("%d", &a)
#define Rl(a) scanf("%lld", &a)
#define Rf(a) scanf("%lf", &a)
#define Rs(a) scanf("%s", a)
#define Pi(a) printf("%d\n", (a))
#define Pf(a) printf("%.2lf\n", (a))
#define Pl(a) printf("%lld\n", (a))
#define Ps(a) printf("%s\n", (a))
#define W(a) while(a--)
#define CLR(a, b) memset(a, (b), sizeof(a))
#define MOD 1000000007
#define LL long long
#define lson o<<1, l, mid
#define rson o<<1|1, mid+1, r
#define ll o<<1
#define rr o<<1|1
#define PI acos(-1.0)
using namespace std;
struct MATRIX{
    struct Matrix{
        LL a[MAXN][MAXN];
        int r, c;
    };
    Matrix ori, res;
    Matrix multi(Matrix x, Matrix y)
    {
        Matrix z; CLR(z.a, 0);
        z.r = x.r; z.c = y.c;
        for(int i = 1; i <= x.r; i++)
        {
            for(int k = 1; k <= x.c; k++)
            {
                if(x.a[i][k] == 0) continue;
                for(int j = 1; j <= y.c; j++)
                    z.a[i][j] = (z.a[i][j] + x.a[i][k] * y.a[k][j] % MOD) % MOD;
            }
        }
        return z;
    }
    Matrix Pow(Matrix z, int n)
    {
        Matrix x; x.r = z.r; x.c = z.c;
        for(int i = 1; i <= x.r; i++)
            for(int j = 1; j <= x.c; j++)
                x.a[i][j] = z.a[i][j];
        Matrix y; y.r = y.c = z.r;
        CLR(y.a, 0);
        for(int i = 1; i <= y.r; i++)
            y.a[i][i] = 1;
        while(n)
        {
            if(n & 1)
                y = multi(y, x);
            x = multi(x, x);
            n >>= 1;
        }
        return y;
    }
};
MATRIX solve;
void exgcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if(!b) {d = a, x = 1, y = 0;}
    else
    {
        exgcd(b, a%b, d, y, x);
        y -= x * (a / b);
    }
}
LL inv(LL a)
{
    LL d, x, y;
    exgcd(a, MOD, d, x, y);
    return (x + MOD) % MOD;
}
int degree[MAXN];
bool Map[MAXN][MAXN];
int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M) != EOF)
    {
        CLR(degree, 0); CLR(Map, false);
        for(int i = 0; i < M; i++)
        {
            int a, b;
            Ri(a); Ri(b);
            Map[a][b] = true;
            degree[a]++;
        }
        for(int i = 1; i <= N; i++)
        {
            LL P = inv((LL)degree[i]);
            for(int j = 1; j <= N; j++)
                if(Map[i][j])
                    solve.ori.a[i][j] = P;
        }
        solve.ori.r = solve.ori.c = N;
        int Q; Ri(Q);
        W(Q)
        {
            int u, k;
            Ri(u); Ri(k);
            solve.res = solve.Pow(solve.ori, k);
            for(int i = 1; i <= N; i++)
                printf("%I64d ", solve.res.a[u][i]);
            printf("\n");
        }
    }
    return 0;
}