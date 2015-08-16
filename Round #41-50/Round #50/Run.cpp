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
/*
4
2 1
1 3
4 2
3 4
*/
using namespace std;
pair<int, int> node[20];

bool square(int i, int j, int k, int l){
	int x1 = node[i].x, y1 = node[i].y;
	int x2 = node[j].x, y2 = node[j].y;
	int x3 = node[k].x, y3 = node[k].y;
	int x4 = node[l].x, y4 = node[l].y;
	
	if(x1+x4!=x2+x3 || y1+y4!=y2+y3)
		return false;
	if((x3-x1)*(x2-x1)+(y3-y1)*(y2-y1)!=0)
		return false;
	if((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) != (x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))
		return false;
	/*cout<<x1<<" "<<y1<<endl;
	cout<<x2<<" "<<y2<<endl;
	cout<<x3<<" "<<y3<<endl;
	cout<<x4<<" "<<y4<<endl;
	cout<<endl;*/
	return true;
}

bool cmp(pair<int, int> node0, pair<int, int> node1){
	if(node0.x != node1.x)
		return node0.x < node1.x;
	return node0.y < node1.y;
}

int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n, p, q;
	while(cin>>n){
		for(int i=0; i<n; ++i){
			cin>>p>>q;
			node[i] = make_pair(p,q);
		}
		sort(node, node+n, cmp);
		int res = 0;
		for(int i=0; i<n-3; ++i)
			for(int j=i+1; j<n-2; ++j)
				for(int k=j+1; k<n-1; ++k)
					for(int l=k+1; l<n; ++l)
						if(square(i,j,k,l))
							res++;
		cout<<res<<endl;
	}
	return 0;
}