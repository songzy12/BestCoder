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
int a[2000000]
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=0; i<n; ++i)
			cin>>a[i];
	}
	return 0;
}