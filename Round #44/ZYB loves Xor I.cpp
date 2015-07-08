#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define SZY
using namespace std;
int MOD = 998244353;
int A[50000];
int B[50000];
long long ans;
//trie 
void compute(int bit, int *A, int *B, int i, int j){
	if(i==j)
		return ;
	int pre = i, post = j;
	int count = 0;
	for(int k=i; k<=j; k++){
		if((1<<bit) > A[k]){
			count++;
		}
		if((A[k] & (1<<bit))==0){
			B[pre++] = A[k];
		}
		else{
			B[post--] = A[k]; //off by one!
		}
	}
	//cout<<endl<<"count: "<<count<<endl;
	if(count == j-i+1)
		return ;
		
	ans += (1<<bit)*(pre-i)*(j-post); //off by one!
	//cout<<i<<" "<<j<<" "<<ans<<" "<<(1<<bit)<<" "<<pre-i<<" "<<j-post<<endl;
	ans %= MOD;
	compute(bit+1, B, A, i, pre-1);
	compute(bit+1, B, A, post+1, j);
}
int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int T;
	cin>>T;
	for(int t = 1; t<=T; t++){
		ans = 0;
		cout<<"Case #"<<t<<": ";
		int n;
		cin>>n;
		int x;
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		compute(0, A, B, 0, n-1);
		ans *= 2;
		ans %= MOD;
		cout<<ans<<endl;
	}
	return 0;
}