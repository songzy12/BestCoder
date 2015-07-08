#include<iostream>
#include<cstdio>
#include<algorithm>
#define SZY
using namespace std;
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
		cout<<"Case #"<<t+1<<": ";
		int ans = 0;
		int A, B;
		cin>>A>>B;
		int temp;
		temp = (250-A)*1000/250 - 50*B;
		ans += temp > 1000*0.4 ? temp : 1000*0.4;
		cin>>A>>B;
		temp = (250-A)*1500/250 - 50*B;
		ans += temp > 1500*0.4 ? temp : 1500*0.4;
		cin>>A>>B;
		temp = (250-A)*2000/250 - 50*B;
		ans += temp > 2000*0.4 ? temp : 2000*0.4;
		cin>>A>>B;
		temp = (250-A)*2500/250 - 50*B;
		ans += temp > 2500*0.4 ? temp : 2500*0.4;
		cout<<ans<<endl;
	}
	return 0;
}