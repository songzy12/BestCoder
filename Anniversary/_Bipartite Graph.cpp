#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
#define SZY
vector<int> edge[10001];
int color[10001];
int visited[10001];
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	while(T--){
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; ++i)
			edge[i].clear();
		memset(color, 0, sizeof color);
		memset(visited, false, sizeof visited);
		int u, v;
		for(int i=1; i<=m; ++i){
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		queue<int> q;
		color[1] = -1;
		q.push(1);
		while(!q.empty()){
			int temp = q.front();
			q.pop();
			visited[temp] = true;
			for(int i=0; i<edge[temp].size(); ++i){
				int ele = edge[temp][i];
				if(visited[ele])
					continue;
				color[ele] = color[temp] == -1 ? 1:-1;
				q.push(ele);
			}
		}
		// there may be more than 1 connection area
		int n1=0, n2=0, n3=0;
		for(int i=1; i<=n; ++i){
			if(color[i] == -1)
				n1++;
			else if(color[i] == 0)
				n3++;
			else
				n2++;
		}
		int n1_ = min(n1, n2);
		int n2_ = max(n1, n2);
		if(n1_ + n3<= n2_)
			cout<<(n1_+n3)*n2_-m<<endl;
		else{
			int temp = (n1_+n3-n2_)/2;
			cout<<(n2_+temp)*(n1_+n3-temp)-m<<endl;
		}
	}
	return 0;
}