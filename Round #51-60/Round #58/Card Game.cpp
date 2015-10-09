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
int a[500], b[500];
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T, m, n;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			cin>>a[i];
		for(int i=0; i<n; ++i)
			cin>>b[i];
		sort(a, a+n);
		sort(b, b+n);
		int sum_a = 0, sum_b = 0;
		for(int i=0; i<m; ++i)
			sum_a += a[i];
		for(int j=n-1; j>n-m-1; j--)
			sum_b += b[j];
		cout<<(sum_a > sum_b ?"YES":"NO")<<endl;
	}
	return 0;
}