#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdio>
#define SZY
using namespace std;
long long fight[10000];
// long long 
// upper_bound(fight, fihgt + n, now), binary search
// int i;
// if(p == i) break;
int main(){
	ios::sync_with_stdio(false);
#ifdef SZY
    freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int T;
	//scanf("%d", &T);
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout<<"Case #"<<t<<":"<<endl;
		long long n, m, k;
		cin>>n>>m>>k;
		int i;
		for(i=0; i<n; i++)
			cin>>fight[i];
		sort(fight, fight+n);
		i = upper_bound(fight, fight + n, m) - fight;
		if(i==0){
			cout<<"madan!"<<endl;
			continue;
		}
		long long init = fight[i-1];
		while(i!=n && k!=0){
			int p = upper_bound(fight, fight + n, init + k) - fight; // No int!
			if(p == i)
				break; // this is also important.
			i = p;
			init = fight[i-1];
			k--;
			// cout<<i<<" "<<init<<" "<<k<<endl;
		}
		if(init >= fight[n-1])
			cout<<"why am I so diao?"<<endl;
		else
			cout<<"madan!"<<endl;
	}
	return 0;
 }