#include <algorithm>
#include <string.h>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mod = 1e9 + 7;
const int maxn = 100010;
int sum[maxn], T, n;
LL haha[maxn];
int main() {
    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out_.txt", "w", stdout);
#endif
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            scanf("%d", &sum[i]);
            haha[i] = 0;
            if (i + sum[i] > n) ok = false;
        }
        sum[n] = 0;
        haha[n + 1] = 0;
        LL ans = 0;
        for (int i = n; i > 1; --i) {
            if (sum[i - 1] > 0) haha[i] = 1;
            else haha[i] = 0;
            if (sum[i - 1] && sum[i - 1] != sum[i] + 1) ok = false;
        }
        if (!ok) {
            printf("0\n");
        }
        else {
            haha[n] = 26LL;
            for (int i = n - 1; i >= 1; --i) {
                if (sum[i] == 0) {
                    haha[i] = (haha[i + 1] * 25LL) % mod;
                }
                else haha[i] = (haha[i + sum[i]]) % mod;
            }
            printf("%I64d\n", haha[1]);
        }
    }
    return 0;
}