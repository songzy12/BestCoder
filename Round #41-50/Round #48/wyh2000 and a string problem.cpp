#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define SZY
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		int len = s.size();
		int step = 0;
		for(int i=0; i<len; i++){
			if(step == 0){
				if(s[i] == 'w' || i>0 && s[i] == 'v' && s[i-1] == 'v')
					step ++;
			}else if(step == 1){
				if(s[i] == 'y')
					step ++;
			}else if(step == 2){
				if(s[i] == 'h'){
					step  ++;
					break;
				}
			}
		}
		if(step == 3){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}