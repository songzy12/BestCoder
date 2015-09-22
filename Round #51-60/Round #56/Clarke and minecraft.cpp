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
int num[500];
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		memset(num, 0, sizeof num);
		int n;
		cin>>n;
		while(n--){
			int a, b;
			cin>>a>>b;
			num[a-1] += b;
		}
		int ans = 0;
		for(int i=0; i<500; ++i)
			ans += num[i]/64 + (num[i]%64 > 0);
		cout<<ans/36+(ans%36>0)<<endl;
	}
	
	return 0;
}