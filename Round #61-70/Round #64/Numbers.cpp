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
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	string N; // N \in (0, 10^30), string not int 
	while(cin>>N){
		int len = N.size();
		if((N[len-1]-'0') % 2 == 0 || (N[len-1]-'0') == 5){
			cout<<"YES"<<endl;
			continue;
		}
		int sum = 0;
		for(int i=0; i<len; ++i)
			sum += N[i]-'0';
		if(sum % 3 == 0){
			cout<<"YES"<<endl;
			continue;
		}
		cout<<"NO"<<endl;
	}
	return 0;
}