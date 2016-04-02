#include<cstdio>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<long long, int> m;
long long ip[1000];
int main(){
	int T;
	cin>>T;
	int M, N;
	for(int t=1; t<=T; t++){
		memset(ip, 0, sizeof(ip));
		cout<<"Case #"<<t<<":"<<endl;
		cin>>N>>M;
		int m0, m1, m2, m3;
		for(int i=0; i<N; i++){
			scanf("%d.%d.%d.%d",&m0,&m1,&m2,&m3);
			ip[i]=m3+256*(m2 + 256*(m1+256*m0));
		}
		for(int i=0; i<M; i++){
			m.clear();
			scanf("%d.%d.%d.%d",&m0,&m1,&m2,&m3);
			long long temp = m3+256*(m2 + 256*(m1+256*m0));
			for(int j=0; j<N; j++){
				m[temp & ip[j]]++;
			}
			cout<<m.size()<<endl;
		}
	}
}