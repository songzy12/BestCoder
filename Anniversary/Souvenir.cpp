#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define SZY
// solve two to make it 200th
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		int n, m, p, q;
		cin>>n>>m>>p>>q;
		if(q >= m*p)
			cout<<n*p<<endl;
		else
			cout<<(n/m*q+min((n%m)*p, q))<<endl; // TLE!
	}
	return 0;
}