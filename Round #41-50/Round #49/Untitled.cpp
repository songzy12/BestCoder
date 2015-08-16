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
int b[20];
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int n, a;
		cin>>n>>a;
		for(int i=0; i<n; ++i)
			cin>>b[i];
		sort(b, b+n);
		int i, j, Len = n+1;
		for(i=0; i<n; i++){
			int temp = a;
			for(j=i; j>=0; j--){
				temp %= b[j]; 
				if(temp == 0){
				// to check timely
					int len = i-j+1;
					Len = min(Len, len);
				}
			}
		}
		cout<< (Len<=n?Len:-1) <<endl;
	}
	return 0;
}