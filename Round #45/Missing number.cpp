#include<iostream>
#include<cstring>
using namespace std;
bool in[1003];

int main(){
	int T;
	cin>>T;
	for(int t = 1; t <= T; t++){
		memset(in, false, sizeof in);
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			int t;
			cin>>t;
			in[t] = true;
		}
		bool first = true;
		for(int i = 1; i <= n + 2; i++){
			if(in[i])
				continue;
			cout<<i;
			if(first){
				cout<<" ";
				first = false;
			}
			else
				cout<<endl;
		}
	}
}