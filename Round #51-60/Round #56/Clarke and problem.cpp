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
const int mod = 1e9+7;
long long a[1001], p;
int dp[1001][1000];
int compute(int i, int j){
	if(dp[i][j] != -1)
		return dp[i][j];
	if(i == 0)
		return dp[i][j] = j == 0 ? 1 : 0;
	return dp[i][j] = (compute(i-1, (p+j-a[i-1])%p) + compute(i-1, j))%mod; // a[i-1] not a[i], off by one
}

int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		memset(dp, -1, sizeof dp);
		int n;
		cin>>n>>p;
		for(int i=0; i<n; ++i)
			cin>>a[i];
		for(int i=0; i<n; ++i)
			a[i] %= p;
		cout<<compute(n, 0)<<endl;
	}
	return 0;
}