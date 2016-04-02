#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
char s[100000]; // access violation 
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	getchar();
	int K;
	for(int t=1; t<=T; t++){
		cout<<"Case #"<<t<<":"<<endl;
		gets(s);
		scanf("%d", &K);
		getchar();
		int n = strlen(s);
		for(int i=0; i<n/K; i++){
			for(int j=0; j<n-n/K*K; j++){
				cout<<s[i + j*(n/K+1)];
			}
			for(int j=n-n/K*K; j<K; j++){
				cout<<s[i + (n/K+1)*(n-n/K*K) + (j-(n-n/K*K))*(n/K)];
			}
		}
		for(int j=0; j<n-n/K*K; j++){
			cout<<s[n/K + j*(n/K +1)];
		}
		cout<<endl;
	}
	return 0;
}