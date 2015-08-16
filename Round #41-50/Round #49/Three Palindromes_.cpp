#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define DEBUG
// TLE, MLE, need to modify algorithm
int p[2][20000];
using namespace std;
bool compute(string s){
	int n = s.size();
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
        for(int i=0;i<n;i++)
        {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            int L=i-p[z][i], R=i+p[z][i]-!z;
            while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
            if(R>r) l=L,r=R;
        }
	for(int i=0; i<2; ++i){
		for(int j=0; j<n; ++j)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}
	for(int i=0; i<n-2; ++i){
		for(int j= i+2; j<n; j++){
			int len1 = i+1, len2 = j-i-1, len3 = n-j;
			bool bool1 = false, bool2 = false, bool3 = false;
			if(len1 == 1 || p[len1%2][len1/2] == len1/2)
				bool1 = true;
			if(!bool1)
				continue;
			if(len2 == 1 || p[len2%2][i+1+len2/2] == len2/2)
				bool2 = true;
			if(!bool2)
				continue;
			if(len3 == 1 || p[len3%2][j+len3/2] == len3/2)
				bool3 = true;
			if(!bool3)
				continue;
			return true;
		}
	}
	return false;
}

int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		string s;
		cin>>s;
		cout<<(compute(s) ? "YES" : "NO")<<endl;
	}
	return 0;
}