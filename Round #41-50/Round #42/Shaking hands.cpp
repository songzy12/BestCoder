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
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	
	while(cin>>n){
		int ans = n<<1;
		int t; 
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j){
				cin>>t;
				if(t)
					ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}