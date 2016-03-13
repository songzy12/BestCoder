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

int a[9];
bool used[10];

int middle(int x, int y) {
    if (x > y)
        swap(x, y);
    switch(x) {
        case 1: {
            switch(y) {
                case 3: return 2;
                case 7: return 4;
                case 9: return 5;
                default: return 0;
            }
        }
        case 2: {
            switch(y) {
                case 8: return 5;
                default: return 0;
            }
        }
        case 3: {
            switch(y) {
                case 7: return 5;
                case 9: return 6;
                default: return 0;
            }
        }
        case 4: {
            switch(y) {
                case 6: return 5;
                default: return 0;
            }
        }
        case 7: {
            switch(y) {
                case 9: return 8;
                default: return 0;
            }
        }
        default: return 0;
    }
    
}

/*
1 2 3
4 5 6
7 8 9
*/
bool valid(int k) {
    memset(used, false, sizeof used);
    if (k < 4) 
        return false;
    for (int i = 0; i < k; ++i) {
        if (a[i] < 1 || a[i] > 9) // scope!
            return false;
        if (used[a[i]])
            return false;
        used[a[i]] = true;
        if (i == 0)
            continue;
        
        int temp = middle(a[i], a[i-1]);
        if (temp != 0 && !used[temp])
            return false;
    }
    return true;
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
        int k;
        cin>>k;
        for (int i = 0; i < k; ++i)
            cin>>a[i];
        cout<<(valid(k) ? "valid" : "invalid")<<endl;
    }
	return 0;
}