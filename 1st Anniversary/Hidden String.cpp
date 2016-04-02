#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define SZY
// hack: one test case a time.
const string p = "anniversary";
const int p_len = p.size();
string s;
int s_len;
bool found(int s_index, int p_index, int step){
	int p_index_ = p_index;
	if(p_index == p_len)
		return true;
	if(s_index == s_len || step == 3)
		return false;
	int i;
	for(i=s_index; i<s_len; i++){
		if(s[i]!=p[p_index])
			continue;
		else{
			while(p_index < p_len && s[i] == p[p_index]){
				i++;
				p_index++;
			}
			break;
		}
	}
	return found(i, p_index, step+1) || found(i, p_index_, step);
}

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>s;
		s_len = s.size();
		cout<<(found(0, 0, 0) ? "YES" : "NO")<<endl;
	}
	return 0;
}