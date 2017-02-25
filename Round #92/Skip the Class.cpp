#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100;
pair<string, int> course[MAXN];

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int T;
    cin>>T;
    while (T--) {
        int n;
        cin>>n;
        for (int i = 0; i < n; ++i)
            cin>>course[i].first>>course[i].second;
        sort(course, course+n);
        string last_string = "";
        int last_count = 0;
        int ans = 0;
        for (int i = n-1; i >= 0; --i) {
            if (course[i].first == last_string) {
                if (last_count == 1) {
                    continue;
                } else {
                    last_count += 1;
                    ans += course[i].second;
                }
            } else {
                last_count = 0;
                last_string = course[i].first;
                ans += course[i].second;
            }
        }
        cout<<ans<<endl;
    }
   
    return 0;
}