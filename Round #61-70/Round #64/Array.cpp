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
const int MAXE = 56;
long long power[MAXE];
long long compute(long long M){
	int i = 0;
	while(power[i] - 1 < M) i++;
	if(M - (power[i] - 1) == 0)
		return i * power[i-1];
	i--;
	long long res = i * power[i-1]; // long long not int
	long long left = M - (power[i] - 1);
	return res + left + compute(left-1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	long long M;
	power[0] = 1;
	for(int i = 1; i < MAXE; ++i)
		power[i] = power[i-1] * 2;
	while(T--){
		cin>>M;
		cout<<compute(M)<<endl;
	}
	return 0;
}