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
#define DEBUG
using namespace std;

struct Node{
	long long  x, y, z; //long long
}node[4];

bool cmp(Node node0, Node node1){
	if(node0.x!=node1.x)
		return node0.x < node1.x;
	if(node0.y!=node1.y)
		return node0.y < node1.y;
	return node0.z < node1.z;
}

int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=1; t<=T; ++t){
		cout<<"Case #"<<t;
		for(int i=0; i<4; ++i)
			cin>>node[i].x>>node[i].y>>node[i].z;
		
		/*long long dist[6];
		int index = 0;
		for(int i=0; i<4; ++i)
			for(int j=i+1; j<4; ++j)
				dist[index++] = (node[i].x-node[j].x)*(node[i].x-node[j].x)+\
								(node[i].y-node[j].y)*(node[i].y-node[j].y)+\
								(node[i].z-node[j].z)*(node[i].z-node[j].z);
		sort(dist, dist+index);
		if(dist[0] == dist[3] && dist[4] == dist[5] && dist[4] == 2*dist[0])
			cout<<": Yes"<<endl; // Yes
		else
			cout<<": No"<<endl;*/
		sort(node, node+4, cmp); // sort
		if((node[0].x+node[3].x == node[1].x+node[2].x &&
		  node[0].y+node[3].y == node[1].y+node[2].y &&
		  node[0].z+node[3].z == node[1].z+node[2].z)&&
		  ((node[0].x-node[1].x)*(node[0].x-node[1].x)+\
		  (node[0].y-node[1].y)*(node[0].y-node[1].y)+\
		  (node[0].z-node[1].z)*(node[0].z-node[1].z) == 
		  (node[0].x-node[2].x)*(node[0].x-node[2].x)+\
		  (node[0].y-node[2].y)*(node[0].y-node[2].y)+\
		  (node[0].z-node[2].z)*(node[0].z-node[2].z))&&
		  ((node[0].x-node[1].x)*(node[0].x-node[2].x) + \
		  (node[0].y-node[1].y)*(node[0].y-node[2].y) + \
		  (node[0].z-node[1].z)*(node[0].z-node[2].z) == 0))
			cout<<": Yes"<<endl; 
		else
			cout<<": No"<<endl; 
	}
	return 0;
}