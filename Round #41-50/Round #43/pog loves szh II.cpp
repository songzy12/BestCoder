#include<iostream>
#include<cstdio>
#include<algorithm>
#define SZY
using namespace std;

long long a[100000]; //data type again, long long
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, p;
	while(cin>>n>>p){
		for(int i=0; i<n; i++){
			cin>>a[i];
			a[i] %= p;
		}
		sort(a, a+n); // this is so stupid
		int ANS = (a[n-1] + a[n-2]) % p;
		int now = n-1;
		for(int i=0; i<now; i++){
			while(a[i] + a[now] >= p)
				now --;
			if(i >= now)
				break; // break timely.
			int temp = (a[i] + a[now]) % p;
			if(temp > ANS)
				ANS = temp;
		}
		cout<<ANS<<endl;
	}
	return 0;
}