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
	ios::sync_with_stdio(false);
	int m, n;
	while(cin>>n>>m){
		bool connected = false;
		int u, v;
		for(int i=0; i<m; ++i){
			cin>>u>>v;
			if(u==1 && v==n || u==n && v==1)
				connected = true;
		}
		cout<<1<<" "<<(connected?n*(n-1)/2:1)<<endl;
	}
	return 0;
}