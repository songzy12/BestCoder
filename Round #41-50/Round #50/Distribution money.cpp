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
/*
3
10000 10000 1
*/
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n, a[10000];
	while(cin>>n){
		memset(a, 0, sizeof a);
		int id;
		for(int i=0; i<n; ++i){
			cin>>id;
			a[id] ++;
		}
		for(id=0; id<10000; ++id)
			if(a[id]>n/2.0)
				break;
		cout<<(id<10000?id:-1)<<endl;
	}
	return 0;
}