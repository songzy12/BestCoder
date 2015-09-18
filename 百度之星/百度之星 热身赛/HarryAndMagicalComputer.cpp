#include<iostream>
#include<vector>
#include<cstring>
// ^Z: EOF
using namespace std;
int mat[100][100];
int row[100];
int main(){
	int n, m;
	while(cin>>n>>m){
		int a, b;
		memset(mat, 0, sizeof(mat));
		memset(row, 0, sizeof(row));
		for(int i=0; i<m; i++){
			cin>>a>>b;
			if(mat[a-1][b-1]!=1){ // for repetition
				mat[a-1][b-1]=1;
				row[a-1]+=1;
			}
		}
		while (true){
			int i;
			int count = 0;
			for(i=0; i<n; i++){
				if(row[i]==-1)
					continue;
				if(row[i]==0)
					break;
				else
					count ++;
			}
			if(i!=n){
				row[i]=-1;
				for(int j=0; j<n; j++)
					if(mat[j][i]==1){
						mat[j][i] = 0; 
						row[j] --; // one condition satisfied
					}
			}
			else{
				if(count == 0)
					cout<<"YES"<<endl;
				else 
					cout<<"NO"<<endl;
				break;
			}
		}
	}
	return 0;
}