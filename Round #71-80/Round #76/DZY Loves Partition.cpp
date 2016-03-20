#include<iostream>
#include<algorithm>
#include<list>
#include<map>
#include<vector>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>

using namespace std;

const int mod = 1e9+7;



long long compute(long long n, long long k) {
    if (k * (k + 1) > 2 * n)
        return -1;
    long long mid = n / k; // or mid + 1
    long long ans = -1;
    
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	
    int t;
    cin>>t;
    while (t--) {
        long long n, k;
        cin>>n>>k;
        cout<<compute(n, k)<<endl;
    }
	return 0;
}