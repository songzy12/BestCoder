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
using namespace std;
const int MAXN = 100000;
int A[MAXN], B[MAXN];

int compute(int n){
	int ans = 0, tempSum = 0, minSum = 0;
	for(int i=0; i<n; ++i){
		tempSum += B[i]; // last number B[i]
		ans = max(ans, tempSum - minSum);
		minSum = min(minSum, tempSum);
	}
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		int sum = 0;
		for(int i=0; i<n; ++i){
			cin>>A[i];
			sum += A[i];
			B[i] = (A[i] * 1890 + 143) % 10007 - A[i];
		}	
		cout<< sum + compute(n) << endl;
	}
	return 0;
}