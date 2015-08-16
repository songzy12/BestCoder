#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define DEBUG
using namespace std;

long long A[1000];
long long compute(int n){
	long long maxSum, thisSum;// can not initialize maxSum to be 0
	for(int j=0; j<n; ++j){
		thisSum += A[j];
		if(!j)
			maxSum = thisSum;
		if(thisSum > maxSum)
			maxSum = thisSum;
		else if (thisSum < 0)
			thisSum = 0;
	}
	return maxSum;
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
		int n, P;
		cin>>n>>P;
		for(int i=0; i<n; ++i)
			cin>>A[i];
		long long Ans;
		for(int i=0; i<n; ++i){
			long long temp = A[i];
			A[i] = P;
			long long ans = compute(n);
			if(!i)
				Ans = ans;
			else
				Ans = max(Ans, ans);
			A[i] = temp;
		}
		cout<<Ans<<endl;
	}
	return 0;
}