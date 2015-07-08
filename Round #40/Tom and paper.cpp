#include<iostream>
#include<cmath>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int temp = sqrt(n);
	int i;
	for(i=temp; i>0; i--){
		if(n%i==0)
			break;
	}
	cout<< 2*(i+n/i)<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
		solve();
	return 0;
}