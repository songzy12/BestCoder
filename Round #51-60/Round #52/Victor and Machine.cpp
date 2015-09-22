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
#define DEBUG
using namespace std;
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int x,y,w,n;
	while(cin>>x>>y>>w>>n){
		int balls = x/w + 1, res = y + x%w;
		cout<<(n/balls*(x+y) + (n%balls?(n%balls-1)*w:-res))<<endl;
	}
	return 0;
}