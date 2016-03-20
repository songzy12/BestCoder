#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>

using namespace std;

const int MAXN = 300;
int a[MAXN + 5];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i) {
            cin>>a[i];
        }
        sort(a, a + n);
        int count = 0;
        int cur = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] > a[i - 1]) {
                count += i;
                cur = i;
            } else {
                count += cur;
            }
        }
        printf("%.6f\n", count * 1.0 / (n * (n-1)));
    }
	return 0;
}