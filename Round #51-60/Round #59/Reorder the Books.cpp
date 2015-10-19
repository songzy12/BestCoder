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
using namespace std;
int a[20], b[20], ans, n;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 1; i <= n; ++i){
			cin>>a[i];
			b[a[i]] = i;
		}
		int i;
		for(i = n ; i > 1 && b[i] > b[i-1]; i--); // algorithm
		cout<<i-1<<endl;
	}
	return 0;
}