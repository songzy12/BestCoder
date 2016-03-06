#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
using namespace std;

const int mod = 1e9 + 7;
int a[3], b[3];
int compute(int s, int t) {
    int res = t - s;
    
}

int main(){    
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    while(T--) {
        int n, m;
        cin>>n>>m;
        for(int i = 0; i < 3; ++i) {
            cin>>a[i]>>b[i];
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            int s, t;
            cin>>s>>t;
            ans += i * compute(s, t);
            ans %= mod;
        }
    }
	return 0;
}