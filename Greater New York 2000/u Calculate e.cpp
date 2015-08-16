#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
#define SZY
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int fact[10];
	fact[0] = 1;
	for(int i=1; i<10; ++i)
		fact[i] = fact[i-1]*i;
	double ans = 0;
	cout<<"n e"<<endl;
	cout<<"- -----------"<<endl;
	for(int i=0; i<10; ++i){
		ans += 1.0/fact[i];
		if(i<3)
			cout<<i<<" "<<ans<<endl;
		else
			cout<<i<<" "<<setiosflags(ios::fixed)<<setprecision(9)<<ans<<endl;
		
	}
	return 0;
}