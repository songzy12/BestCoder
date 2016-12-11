#include <iostream>
#include <cstdio>
using namespace std; 

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif   
    int n;
    cin>>n;
    for (int t = 0; t < n; ++t) {
        string s;
        cin>>s;
        int res = 0;
        for (int i = 1; i < s.length() + 1; ++i) {
            // j | i, k = j * j / i
            int r = 1;
            while (r * r * i < s.length() + 1) {
                int j = i * r;
                int k = r * r * i; // j * j / i;
                if (s[i-1] == 'y' && s[j-1] == 'r' && s[k-1] == 'x' ||
                    s[k-1] == 'y' && s[j-1] == 'r' && s[i-1] == 'x') 
                    // geometric is two way
                    res++;
                r++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}