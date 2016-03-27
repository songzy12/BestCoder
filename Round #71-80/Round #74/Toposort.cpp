#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <string>
#define PB push_back
#define FT first
#define SD second
#define MP make_pair
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int>  P;
const int N = 1e5 + 10,MOD = 7+1e9;
int n, m, k;
int tol, head[N], du[N];
struct edge
{
    int to, next;
}e[2 * N + 10];
void init()
{
    tol = 0;
    memset(head, -1, sizeof head);
    memset(du, 0, sizeof du);
}
void addedge(int u, int v)
{
    e[tol].to = v, e[tol].next = head[u], head[u] = tol++;
}
int Min[4 * N];
void build(int rt, int L, int R)
{
    if(L == R) {
        Min[rt] = du[L];
        return ;
    }
    int mid = (L + R) >> 1;
    build(rt << 1, L, mid);
    build(rt << 1 | 1, mid + 1, R);
    Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
}
void update(int rt, int L, int R, int pos, int val)
{
    if(pos <= L && pos >= R) {
        Min[rt] = val;
        return ;
    }
    int mid = (L + R) >> 1;
    if(pos <= mid) update(rt << 1, L, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, R, pos, val);
    Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
}
int read(int rt, int L, int R, int l, int r)
{
    if(l <= L && R <= r) {
        return Min[rt];
    }
    int mid = (L + R) >> 1;
    if(r <= mid) return read(rt << 1, L, mid, l, r);
    else if(l > mid) return read(rt << 1 | 1, mid + 1, R, l, r);
    else {
        return min(read(rt << 1, L, mid, l, mid), read(rt << 1 | 1, mid + 1, R, mid + 1, r));
    }
}
int getID()
{
    int L = 1, R = n;
    while(L <= R) {
        int mid = (L + R) >> 1;
        if(read(1, 1, n, L, mid) <= k) {
            R = mid - 1;
        }
        else L = mid + 1;
    }
    return L > n ? -1 : L;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T --) {
        init();
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0;i < m;i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u, v);
            du[v] ++;
        }
        build(1, 1, n);
        int cnt = 0;
        LL ans = 0;
        while(1) 
        {
            int id = getID();
            if(id == -1) break;
            k -= du[id];
            ans = (ans + 1LL * (++cnt) * id % MOD) % MOD;
            du[id] = 0;
            update(1, 1, n, id, INF);
            for(int i = head[id];i != -1;i = e[i].next) {
                if(du[e[i].to] == 0) continue;
                du[e[i].to] --;
                update(1, 1, n, e[i].to, du[e[i].to]);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}