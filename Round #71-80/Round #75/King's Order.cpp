#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<list>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
#include<iostream>
#include<cstdio>
using namespace std;


const int MOD = 1000000007;
const int MAXN = 2000;

long long cache[MAXN + 5];

// repeat at most three times
// again, scope!
long long compute(int n) {
    if (cache[n] != -1)
        return cache[n];
    long long count = 0;
    // first not the same with second
    count += 25 * compute(n - 1);
    count %= MOD;
    // first same with second, not the same with third
    count += 25 * compute(n - 2);
    count %= MOD;
    // first same with second, third, not the same with forth
    count += 25 * compute(n - 3);
    count %= MOD;
    cache[n] = count;
    return count;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    
    for (int i = 0; i <= MAXN; ++i)
        cache[i] = -1;
    cache[0] = 1;
    for (int i = 1; i <= 3; i++)
        cache[i] = 26 * cache[i-1];
    
    while (T--) {
        int n;
        cin>>n;
        cout<<compute(n)<<endl;
    }
	return 0;
}