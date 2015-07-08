#include<iostream>
#include<cstdio>
using namespace std;
#define SZY
const int mod = 998244353;

int a[100001];
int inv[100001];

inline int power(int x,int y) { 
	int sum=1; 
	for (;y;y>>=1){ 
		if (y&1) 
			sum=1ll*sum*x%mod; // just like *1.0
		x=1ll*x*x%mod; // fast power
	} 
	return sum; 
}

int binom(int top, int bottom){
	int res = 1;
	for(int i = top, j = 0; j < bottom; j++)
		res = (1ll * res * (i-j)) % mod;
	for(int j = 1; j <= bottom; j++)
		res = (1ll * res * inv[j]) % mod;
	return res;
}

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	for (int i=0; i<=100001; ++i) // ++i, not i++
		inv[i] = power(i,mod-2);
	for(int t = 1; t <= T; t++){
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		
		int result = 0;
		for(int j = 0; j <= n-1; j++)
			result = (result + binom(n, j)) % mod;
		for(int i = 1; i <= n; i++){
			int top = a[i]*(a[i]-1)/2;
			int temp = 0;
			for(int j = 0; j <= a[i]-1; j++)
				temp = (temp + binom(top, j)) % mod;
			result = (1ll * temp * result) % mod;
		}
		// the underwater railway can be all preserved.
		cout<<result<<endl;
	}
	return 0;
}