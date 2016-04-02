#include<iostream>
using namespace std;
const int mod = 1e9+7;
long long table[1000001];
int main(){
	table[1] = 1;
	table[2] = 2;
	for(int i=3; i<1000001; i++)
		table[i]=(table[i-1]+(i-1)*table[i-2])%mod; //another way around
	int T;
	cin>>T;
	for(int j=1; j<=T; j++){
		cout<<"Case #"<<j<<":"<<endl;
		int N;
		cin>>N;
		cout<<table[N]<<endl;
		/*long long result = 1;
		long long t = 1;
		for(int i=1; N-2*i>= 0; i++){
			t = t*(N-2*(i-1))*(N-2*(i-1)-1)/(2*i); // *= 0
			// cout<<"t: "<<t<<endl;
			t %= mod;
			result += t;
			result %= mod;
		}
		cout<<result<<endl;*/
	}
	return 0;
}