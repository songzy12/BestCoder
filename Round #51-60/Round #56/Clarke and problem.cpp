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
long long a[1000], ans;


int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		ans = 0;
		int n, p;
		cin>>n>>p;
		for(int i=0; i<n; ++i)
			cin>>a[i];
	}
	return 0;
}