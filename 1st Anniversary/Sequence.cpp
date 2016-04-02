#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define SZY
const int MAXN = 18258; 
const int MAXM = 1e9;
int dic[MAXN+1];
//map<int, int> dic; // map will TLE
int calc(int n){
	switch(n%6){
		case 0: return 6;
		case 3: return 3;
		case 4: return 4;
		case 5: return 5;
		case 1: 
			if(*lower_bound(dic+1, dic+MAXN+1, n) == n)
				return 1;
			return 7;
			//return dic[n]?1:7;
		case 2: 
			int b = 1, e = MAXN;
			while(b<=e){
				if(dic[b]+dic[e] == n)
					return 2;
				if(dic[b]+dic[e] < n)
					b++;
				else
					e--;
			}
			return 8;
			/*map<int, int>::iterator it;
			for(it = dic.begin(); it!=dic.end(); ++it)
				if(dic[it->second] && dic[n-it->second])
					return 2;
			return 8;*/
	}
}

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	for(int i=0; i<=MAXN; ++i)
		//dic[3*i*(i-1) + 1] = 1;
		dic[i] = 3*i*(i-1) + 1;
	int T;
	cin>>T;
	while(T--){
		int m;
		cin>>m;
		cout<<calc(m)<<endl;
	}
	return 0;
}