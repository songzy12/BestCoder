#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int Mod = 1000000007;

const int oo = 0x3f3f3f3f;

const int maxn = 50, maxm = 7;

int n, m;

int f[1 << maxm][1 << maxm];

inline void prepare()
{
    memset(f, 0, sizeof f);
    REP(i, 0, 1 << m)
        REP(j, 0, 1 << m)
        {
            f[i][j] = 1;
            REP(k, 0, m - 1)
            {
                bool a[2][2];
                a[0][0] = (i >> k) & 1;
                a[0][1] = (i >> (k + 1)) & 1;
                a[1][0] = (j >> k) & 1;
                a[1][1] = (j >> (k + 1)) & 1;
                if (a[0][0] + a[0][1] + a[1][1] + a[1][0] == 2)
                {
                    if (a[0][0] && a[1][1]) f[i][j] = 0;
                    if (a[0][1] && a[1][0]) f[i][j] = 0;
                }
            }
        }
}

inline void mul(int a[1 << maxm][1 << maxm], int b[1 << maxm][1 << maxm])
{
    static int ans[1 << maxm][1 << maxm];
    memset(ans, 0, sizeof ans);
    REP(i, 0, 1 << m)
        REP(j, 0, 1 << m)
            REP(k, 0, 1 << m)
                (ans[i][k] += (LL)a[i][j] * b[j][k] % Mod) %= Mod;
    
	REP(i, 0, 1 << m)
        REP(j, 0, 1 << m)
            a[i][j] = ans[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (~scanf("%d%d", &n, &m))
    {
        prepare();
        static int g[1 << maxm][1 << maxm];
        memset(g, 0, sizeof g);
        REP(i, 0, 1 << m) g[i][i] = 1;
		//fast power
        for ( ; n; n >>= 1, mul(f, f)) if (n & 1) mul(g, f); 
        int ans = 0;
        REP(i, 0, 1 << m) (ans += g[0][i]) %= Mod;
        (ans += Mod) %= Mod;
        printf("%d\n", ans);
    }
    return 0;
}