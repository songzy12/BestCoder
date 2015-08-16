#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 100005;
int n , m , pre[N] , mcnt;
struct edge {
    int x , next;
}e[N << 1];
bool f[N];
int a[N] , s[N] , S;
LL res;
pair<int , int> Find(int x , int fa , int cnt) {
    s[x] = 1; int m = 0;
    pair<int , int> res = make_pair(1 << 30 , -1);
    for (int i = pre[x] ; ~i ; i = e[i].next)
	// ~i means i!=-1
        if (!f[e[i].x] && e[i].x != fa) {
		    res = min(res , Find(e[i].x , x , cnt));
			// res is minimum m
            m = max(s[e[i].x] , m);
            s[x] += s[e[i].x];
        }
    m = max(m , cnt - s[x]);
	// m is maximum size of sub-tree
    return min(res , make_pair(m , x));
}
void Getdis(int x , int fa , int mn , int mx , vector<pair<int , int> >& V) {
    mn = min(mn , a[x]);
    mx = max(mx , a[x]);
	// mn, mx is min, max down the path
    ++ S;
    if (mx - mn <= m)
        V.push_back(make_pair(mn , mx)); // max-min <= m
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y] && y != fa)
            Getdis(y , x , mn , mx , V);
    }
}
int d[N] , D , c[N] , q[N];
LL cal(vector< pair<int , int> >& V) {
    sort(V.begin() , V.end());
    int w = V.size();
    LL sum = 0;
    D = 0;
    for (int i = 0 ; i < w ; ++ i)
        d[++ D] = V[i].second;
    sort(d + 1 , d + D + 1);
    D = unique(d + 1 , d + D + 1) - d - 1;// remove adjacent same ones
    for (int i = w - 1 ; i >= 0 ; -- i) {
        int r = max(V[i].first + m , V[i].second);
        int l = upper_bound(d + 1 , d + D + 1 , r) - d - 1;
        for (int j = l ; j > 0 ; j -= j & -j)
            sum += c[j];
        int k = lower_bound(d + 1 , d + D + 1 , V[i].second) - d;
        for (int j = k ; j <= D ; j += j & -j)
            ++ c[j];
        q[i] = k;
    }
    for (int i = 0 ; i < w ; ++ i)
        for (int j = q[i] ; j <= D ; j += j & -j)
            -- c[j];
    return sum;
}

void divide(int x , int cnt) {
    x = Find(x , 0 , cnt).second;
	// x is the centroid
    f[x] = 1;
    vector< pair<int , int> > Vec;
    Vec.push_back(make_pair(a[x] , a[x]));
	// a[i] is the weight of point i
    for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y]) {           
            vector< pair<int , int> > V;
            S = 0;
            Getdis(y , x , a[x] , a[x] , V);
            s[y] = S;
            res -= cal(V);
            Vec.insert(Vec.end() , V.begin() , V.end());
			// insert
        }
    }
    res += cal(Vec);
	for (int i = pre[x] ; ~i ; i = e[i].next) {
        int y = e[i].x;
        if (!f[y])
            divide(y , s[y]); 
		// s[y] size of sub-tree y
    }
}

void work() {
    scanf("%d%d" , &n , &m);
    memset(pre , -1 , sizeof(pre));
    mcnt = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
        //a[i] = rand();
    }
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        //x = i + 1 , y = rand() % i + 1;
        scanf("%d%d" , &x , &y);
        e[mcnt] = (edge) {x , pre[y]} , pre[y] = mcnt ++;
		// pre[y] stores last edge count with node y
		// if pre[y] = mcnt, the last edge is e[mcnt]
        e[mcnt] = (edge) {y , pre[x]}; // init
		pre[x] = mcnt ++;
    }
    memset(f , 0 , sizeof(f));
    res = 0;
    divide(1 , n);
    cout << res + res << endl;// (u, v) and (v, u)
}


int main() {

freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
	
    /*int __size__ = 256 << 20; // 256MB
    char *__p__ = (char*)malloc(__size__) + __size__;
    __asm__("movl %0, %%esp\n" :: "r"(__p__));  */

    int T;
    scanf("%d" , &T);
    while (T --)
        work();
    return 0;
}