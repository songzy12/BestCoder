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
	int N, K, a[100]={0};
	while(cin>>N){
		memset(a, 0, sizeof a);
		int x;
		for(int i=0; i<N; ++i){
			cin>>x;
			a[x-1] ++;
		}
		cin>>K;
		int repeat = 0;
		for(int i=0; i<100; ++i)
			if(a[i])
				repeat += a[i] - 1;
		cout<<(K <= repeat ? N - repeat: N - K)<<endl;
	}
	return 0;
}