#include<iostream>
#include<cstdio>
#include<string>
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
		string s;
		cin>>s;
		int len = s.size();
		string l = "", r = "";
		for(int i=0; i<len; i++){
			if (i%2==0)
				l = l + s[i];
			else
				r = s[i] + r;
		}
		cout<<l<<endl<<r<<endl;
	}
	return 0;
}