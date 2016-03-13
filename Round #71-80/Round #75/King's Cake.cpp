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
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T;
    cin>>T;
    while(T--) {
        int n, m;
        cin>>n>>m;
        int count = 0;
        while (n != m) {
            if (n < m)
                swap(n, m);
            // n >= m
            n -= m;
            count++;
        }
        count++;
        cout<<count<<endl;
    }
	return 0;
}