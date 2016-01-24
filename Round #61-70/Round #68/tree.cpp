#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
using namespace std;

const int MAXN = 100005;
int group[MAXN], id[MAXN], n;

int find(int p){
	if(p == id[p])
		return p;
	return id[p] = find(id[p]); // to the top
}

void read_graph(){
	int u_, v_, w_;
	for(int i = 0; i < n-1; ++i){
		cin >> u_ >> v_ >> w_;
		if(!w_){
			int u_id = find(u_);
			int v_id = find(v_);
			id[max(u_id, v_id)] = min(u_id, v_id);
			group[min(u_id, v_id)] += group[max(u_id, v_id)];
		}
	}
}

int compute(){
	int res = 0;
	for(int i=1; i<=n; ++i)
		res ^= group[find(i)];
	return res;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1; i<=n; ++i){
			id[i] = i;
			group[i] = 1;
		}
		read_graph();
		cout<<compute()<<endl;
	}
	return 0;
}