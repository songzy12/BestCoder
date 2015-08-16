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
60
*/
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	long long a[61]={0,1,2,3};
	cout<<"0 1 2 3 ";
	for(int i=4; i<61; ++i){
		a[i] = a[i-1] + a[i-3] + 1;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int n;
	while(cin>>n)
		cout<<a[n]<<endl;
	return 0;
}