#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
#define DEBUG
using namespace std;

const int N = 1e5+5, p = 1e9+7;
int a[N], b[N], num[N];

int pow(int a, int n){
	int ans = 1, z = a;
	while(n){
		if(n&1)
			ans = (long long)ans * z % p;
		z = (long long)z * z % p;
		n >>= 1;
	}
	return ans;
}

int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T, n;
	cin>>T;
	while(T--){
		int ans = 0;
		cin>>n;
		for(int i = 1; i <= n; ++i){
			cin>>a[i];
			b[i] = a[i];
			ans = (ans + (long long)a[i] * pow(2, n - 1) % p) % p;
		}
		sort(b + 1, b + 1 + n);
		int m = unique(b + 1, b + 1 + n) - b - 1; // unique
		for(int i = 1; i <= m; ++i)
			num[i] = 0;
		for(int i = 1; i <= n; ++i){
			int x = a[i];
			a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b; // a[i] is now the index of a[i] in b
			int res = (long long)num[a[i]] * pow(2, n-i) % p;
			ans = (ans - (long long)res * x % p + p) % p; // subtract the repeated ones
			num[a[i]] = (num[a[i]] + pow(2, i-1)) % p; // add the current one
		}
		cout<<ans<<endl;
	}
	return 0;
}