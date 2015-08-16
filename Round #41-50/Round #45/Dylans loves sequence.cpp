#include<iostream>
#include<cstdio>
#include<cstring>
#define SZY
using namespace std;
int a[1000];
int inv[1000][1000];

int compute(int L, int R){
	if(inv[L][R] != -1)
		return inv[L][R];
	if(L >= R)
		return inv[L][R] = 0;
	int res = compute(L+1, R);
	for(int i = L+1; i <= R; i++)
		if(a[L] > a[i])
			res ++;
	return inv[L][R] = res;
}

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int N, Q;
	cin>>N>>Q;
	for(int i = 0; i < N; i++)
		cin>>a[i];
	memset(inv, -1, sizeof(inv));
	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			compute(i, j);
			
	for(int q = 0; q < Q; q++){
		int L, R;
		cin>>L>>R;
		cout<<compute(L-1, R-1)<<endl; // off by one!
	}
	return 0;
}