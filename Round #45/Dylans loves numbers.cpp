#include<iostream>
#include<cstdio>
#define SZY
using namespace std;

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		long long N;
		cin >> N;
		bool in = false;
		int count = 0;
		while(N){
			if((N & 1) && !in){
				in = true;
				count += 1;
			}
			if(!(N & 1) && in)
				in = false;
			N >>= 1;
		}
		cout<<count<<endl;
	}
	return 0;
}