#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define SZY

int graph[1001][1001];
int line[1000000][2];
int tri[1000000][3];
int tot, ftot;

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	
	while(cin>>n>>m){
		for(int i=0; i<n; ++i){
			int x, y;
			cin>>x>>y;
		}
		memset(graph, 0, sizeof graph); // reset
		for(int i=0; i<m; ++i){
			int u, v;
			cin>>u>>v;
			if(u > v)
				swap(u, v); // swap, min, max
			line[i][0] = u;
			line[i][1] = v;
			graph[u][v] = 1;
			graph[v][u] = 1;
		}
		if(m == 0){
			cout<<1<<" "<<n<<endl;
			continue; 
		}
		tot = 0;
		for(int i = 0; i < m; i++)
			for(int j = 1; j < line[i][0]; j++)
				if(graph[j][line[i][0]] && graph[j][line[i][1]]){
					tri[tot][0] = j; // ascending order
					tri[tot][1] = line[i][0];
					tri[tot][2] = line[i][1];
					tot ++; // tot used to count
				}
		if (tot == 0){
			cout<<2<<" "<<m<<endl;
			continue; // if no continue, then will cout "3 0"
		}
		ftot = 0;
		for(int i = 0; i < tot; i++)
			for(int j = 1; j < tri[i][0]; j++)
				if(graph[j][tri[i][0]] && graph[j][tri[i][1]] && graph[j][tri[i][2]]){
					ftot++;
					break; // since cannot be more than once
				}
		if(ftot == 0)
			cout<<3<<" "<<tot<<endl;
		else
			cout<<4<<" "<<ftot<<endl;
	}	
	return 0;
}