#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define SZY

int color[100001];
vector<int> graph[100001];
int tBlack, tWhite;
bool dfs(int node, int color);
int main(){
	ios::sync_with_stdio(false);
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	int n, m;
	int nBlack, nWhite;
	while(T--){
		nBlack = nWhite = 0;
		cin>>n>>m;
		memset(color, -1, sizeof color);
		for(int i=1; i<=n; ++i)
			graph[i].clear();
		int u, v;
		for(int i=1; i<=m; ++i){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		if(n < 2) {
			cout<<"Poor wyh"<<endl; // if not, then "n 0".
			continue;
		}
		if(m == 0) {
			cout<<n-1<<" "<<1<<endl;// if not, then "n 0".
			continue;
		}
		
		bool flag = true;
		for(int i=1; i<=n; i++){
			if(color[i] == -1){
				tBlack = tWhite = 0;
				if(!dfs(i, 0)){
					flag = false;
					break;
				}
				nBlack += max(tBlack, tWhite);
				nWhite += min(tBlack, tWhite);
			}
		}
		if (flag)
			cout<<nBlack <<" "<<nWhite<<endl;
		else
			cout<<"Poor wyh"<<endl;
	}
	return 0;
}

bool dfs(int node, int c){
	//cout<<node<<endl;
	int sz = graph[node].size();
	color[node] = c;
	c ? tBlack ++ : tWhite ++;
	for (int i=0; i<sz; ++i){
		int cur = graph[node][i];
		if(color[cur]==-1){
			if(!dfs(cur, 1-c))
				return false;
		}else{
			if(color[cur] != 1-c)
				return false;
		}
	}
	return true;
}