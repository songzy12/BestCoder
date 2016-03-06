#include<iostream>
#include<cstdio>
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
using namespace std;

const long long mod = 1e9+7; // not 10e9+7 !
const int maxn = 1e5; 
int a[maxn];

/*long long solve(int n) {  
    int last, current;
    cin>>last;
    long long ans = 26;
    for (int i = 1; i < n - 1; ++i) {
        cin>>current;
        if (last != 0) {
            if (current != last - 1)
                return 0; // surplus elements left unread!!!
        } else {
            ans = (ans * 25) % mod;
        }
        last = current;
    }
    if (last > 1) 
        return 0;
    if (last == 0) {
        ans = (ans * 25) % mod;
    }
    return ans;
}*/

long long solve(int n) {
    for (int i = 0; i < n - 1; ++i)
        cin>>a[i];
    long long ans = 26;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i - 1] != 0) {
            if (a[i] != a[i - 1] - 1)
                return 0;
        } else {
            ans = (ans * 25) % mod;
        }
    }
    if (a[n - 2] > 1)
        return 0;
    if (a[n - 2] == 0)
        ans = (ans * 25) % mod;
    return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
	return 0;
}