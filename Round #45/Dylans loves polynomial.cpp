#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define SZY

int x[3001];
int y[3001];
int f[3001][3001];
int inv[250001]; // Euler Theorem, a^-1 = a^{p-2} (mod p)
const int mod = int(1e9+7); // cannot 1e9+7 only

inline int power(int x,int y) { 
	int sum=1; 
	for (;y;y>>=1){ 
		if (y&1) 
			sum=1ll*sum*x%mod; // just like *1.0
		x=1ll*x*x%mod; // fast power
	} 
	return sum; 
}

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N;
	cin>>N;
	for (int i=0; i<=250000; ++i) // ++i, not i++
		inv[i] = power(i,mod-2);
	for(int n = 1; n <= N; n++)
		cin>>x[n]>>y[n];
	for(int delta = 0; delta <= N-1; delta ++)
		for(int i = 1; i <= N - delta; i++) // access violation
			if(delta == 0)
				f[i][i+delta] = y[i] % mod;
			else
				f[i][i+delta] = (1ll * (f[i+1][i+delta] - f[i][i+delta-1] + mod) * 
				(inv[abs(x[i+delta]-x[i])]*(x[i+delta]-x[i] > 0 ? 1 : -1) + mod)) % 
				mod; // notice where to put + mod
	/*for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++)
			cout<<f[i][j]<<" ";
		cout<<endl;
	}*/
	int Q;
	cin>>Q;
	for(int q = 0; q < Q; q++){
		int L, R, v;
		cin>>L>>R>>v;
		if(L>R){
			int t = L;
			L = R;
			R = t;
		}
		long long result = 0;
		long long mult = 1;
		for(int d = 0; d <= R-L; d++){
			if (d > 0)
				mult = (1ll * mult * (v - x[L+d-1] + mod)) % mod; // maybe v - x[L+d-1] < 0
			int temp = (1ll * f[L][L+d] * mult) % mod;
			// cout<<"temp: "<<temp<<endl;
			result = (result + temp) % mod;
		}
		cout<<result<<endl;
	}
	return 0;
}