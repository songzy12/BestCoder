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

bool isPrime(int n){
	for(int i=2; i<=int(sqrt(n)); ++i)
		if(n%i==0)
			return false;
	return true;
}
	
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n==4)
			cout<<2<<endl;
		else if(isPrime(n))
			cout<<n-1<<endl;
		else 
			cout<<0<<endl;
	}
	return 0;
}