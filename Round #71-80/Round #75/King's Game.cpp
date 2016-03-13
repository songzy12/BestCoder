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

const int MAXN = 5000;
bool out_[MAXN + 5];

int compute(int n) {
    memset(out_, false, sizeof out_);
    int index = 0;
    for (int goal = 1; goal < n; goal++) {
        int met = 0;
        // goal of current round
        while (met < goal) {
            index ++;
            if (index == n + 1)
                index = 1;
            while (out_[index]) {
                index ++;
                if (index == n + 1)
                    index = 1;
            }
            met++;
            // index now is met
        }
        out_[index] = true;
    }
    
    for (int i = 1; i <= n; ++i)
        if (!out_[i])
            return i;
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
        cout<<compute(n)<<endl;
    }
	return 0;
}