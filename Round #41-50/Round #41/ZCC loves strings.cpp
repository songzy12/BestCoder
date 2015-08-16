#include<iostream>
#include<string>
#include<cmath>
#include<map>
using namespace std;

int gcd(int a, int b){
	return b?gcd(b,a%b):a;//gcd can be simple like this
}

map<long long, int> m;
void solve(){
	int N;
	cin>>N;
	int A=0, B=0;
	m.clear();
	string s;
	long long temp;// use a long long to indicate a string
	int ans = 0;
	for(int i=0; i<N; i++){
		temp = 0;
		cin>>s;
		if(s.size()%2)
			A++;
		else	
			B++;
		for(int i=0; s[i]; i++){
			temp += temp*123 + s[i];
		}
		ans += m[temp];//m[temp] is initially 0
		m[temp]++;
	}
	ans += A*B;// strings with different length
	int total = N*(N-1)/2;
	int g = gcd(ans, total);
	cout<<ans/g<<"/"<<total/g<<endl;
}

/*int A[20000];
string B[20000];
void solve(){
	int N;
	cin>>N;
	int win = 0;
	for(int i=0; i<N; i++){
		cin>>B[i];
		A[i] = B[i].size() % 2;
		for(int j=0; j<i; j++)
			if(B[i]==B[j] || A[i]!=A[j])
				win+=1;
	}
	int total = N*(N-1)/2;
	int g = gcd(win, total);
	cout<<win/g<<"/"<<total/g<<endl;
}*/

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
		solve();
	return 0;
}