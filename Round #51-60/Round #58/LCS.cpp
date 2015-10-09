#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
#define DEBUG
using namespace std;
int a[2000001], b[2000001], index[2000001];
bool used[2000001];
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T, n;
	cin>>T;
	while(T--){
		cin>>n;
		// memset(used, false, sizeof used);
		// only init the useful one
		for(int i=1; i<=n; ++i)
			used[i] = false;
		for(int i=1; i<=n; ++i)
			cin>>a[i];
		for(int i=1; i<=n; ++i)
			cin>>b[i];
		for(int i=1; i<=n; ++i)
			index[a[i]] = b[i]; // rather than index[a[i]] = i
		int ans = n, t;
		// find out all the rings
		for(int i=1; i<=n; ++i){
			// a, b are both permutations
			if(!used[i]){
				if(index[i] == i)
					continue; // length 1
				t = i;
				while(!used[t]){
					used[t] = true;
					t = index[t];
				}
				ans --;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}