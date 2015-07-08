#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>
#define SZY
using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

static const int mod = 1e9 + 7;
LL per_inver[110];
int arr[110];
bool vis[110];
LL sum[110];
LL f[110];
int tree[110];

int lowbit(int x) {
    return x & (-x);
}

void add(int x, int n) {
    for (int i = x; i <= n; i += lowbit(i)) {
        ++tree[i];
    }
}

int getsum(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += tree[i];
    }
    return ans;
}

int main() {
#ifdef SZY
	freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
#endif
    per_inver[0] = 0;
    per_inver[1] = 0;
    f[0] = 1;
    for (int i = 1; i <= 100; ++i) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
    LL jiechen = 1;
    for (int i = 2; i <= 100; ++i) {
        LL last = per_inver[i - 1];
        jiechen *= (i - 1);
        jiechen %= mod;
        per_inver[i] = 0;
        for (int j = 0; j < i; ++j) {
            per_inver[i] += last;
            per_inver[i] %= mod;
            last += jiechen;
            last %= mod;
        }
    }
	/*for(int i=1; i<=100; i++)
		cout<<"inv: "<<i<<" "<<per_inver[i]<<endl;*/
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1;i <= n; ++i) {
            scanf("%d", &arr[i]);
        }
        memset(tree, 0, sizeof(tree));
        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            add(arr[i], n);
            LL cur = i - getsum(arr[i]);
            cur %= mod;
            sum[i] = sum[i - 1] + cur;
            sum[i] %= mod;
        }
        LL ans = 0;
        memset(vis, 0, sizeof(vis));
		
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < arr[i]; ++j) { //这一位开始小，前面的都相同，枚举没出现过的
                LL pre = sum[i - 1]; //前面固定的逆序对
                if (!vis[j]) {
                    LL cur = 0, u = 0;
                    for (int k = 1; k < j; ++k) {
                        if (!vis[k]) {
                            ++u;
                        }
                    }
                    for (int k = j + 1; k <= n; ++k) {
                        if (vis[k]) {
                            ++cur;
                        }
                    }
                    int v = 0;
                    for (int k = 1; k < i; ++k) {
                        for (int l = i; l <= n; ++l) {
                            if (!vis[arr[l]] && arr[l] != j) {
                                if (arr[k] > arr[l]) {
                                    ++v;
                                }
                            }
                        }
                    }
                    ans += per_inver[n - i] + (cur + u + v + pre) * f[n - i];
                    ans %= mod;
                }
            }
			//cout<<i<<" "<<ans<<endl;
            vis[arr[i]] = 1;
        }
		
        printf("%lld\n", ans);
    }
    return 0;
}