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

const int oo = 0x3f3f3f3f; // 0011 1111 ...

const int maxn = 10000;

int T;
int n;
int A[maxn + 5], B[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", A + i);
        REP(i, 0, n) scanf("%d", B + i);
        double l = 0, r = 1000;
        while (l < r - 1e-8) 
        {
            double mid = (l + r) / 2;
            double L = 0, R = 0;
            REP(i, 0, n)
            {
                double tmp1 = B[i] * B[i] * A[i];
                if (mid < A[i])
                {
                    double tmp = (A[i] - mid) / A[i];
                    double tmp2 = tmp1 * tmp * tmp * tmp;
                    double tmp3 = tmp1 - tmp2;
                    R += tmp2;
                    L += tmp3;
                }
                else L += tmp1;
            }
            if (L < R) l = mid; // L is the lower part
            else r = mid;
        }
        printf("%d\n", int(l + 1e-8)); // why l+1e-8?
    }
    return 0;
}