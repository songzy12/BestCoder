#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define DEBUG
using namespace std;
long long a[100000], b[100000];

bool cmp(int a, int b){
	return a>b;
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
		int n, m;
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			cin>>a[i];
		for(int i=0; i<m; ++i)
			cin>>b[i];
		sort(a, a+n, cmp); // sort
		sort(b, b+m);
		int len = min(m,n);
		long long ans = 0;
		for(int i=0; i<len; ++i){
			if(a[i]-b[i]>0)
				ans += a[i]-b[i];
			else
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}