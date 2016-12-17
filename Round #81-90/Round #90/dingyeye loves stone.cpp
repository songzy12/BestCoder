#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100005;
int n;
int fa[maxn];
int a[maxn];
int depth[maxn];

int Solve() {
    // even depth layer does not matter
    // odd depth layer is nim game, isolated by even depth layer
    // think about simple example
    cin>>n;
    int ans = 0;
    depth[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin>>fa[i];
        depth[i] = depth[fa[i]] + 1; // fa[i] < i
    }
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
        if (depth[i] % 2)
            ans ^= a[i];
    }
    return ans;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        cout<<(Solve()?"win":"lose")<<endl;
    }        
}