#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<pair<int, int>, int> st;
#define x first.first
#define y first.second
#define z second
#define mst(x,y, z) make_pair(make_pair(x,y),z)
#define d(u) dis[u.x][u.y][u.z]
#define p(u) q.push(make_pair(-d(u),u)) 
// to make it a descending priority_queue

int n, m, k;
int map[50][50];
int x1, y1, x2, y2;
double dis[50][50][50];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void solve() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf(" %c", &map[i][j]);
        }
    }
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int l = 0; l < k; ++l) {
                dis[i][j][l] = 1e8;
            }
        }
    }
    priority_queue<pair<double, st> > q;
    st s = mst(x1 - 1, y1 - 1, 0);
    d(s) = 0;
    p(s);
    while (q.size()) {
        pair<double, st> top = q.top();
        q.pop();
        st u = top.second;
        if (-d(u) == top.first) {
		// we may push a point several times
            for (int d = 0; d < 4; d++) {
                st v = mst(u.x + dx[d], u.y + dy[d], u.z + 1);
                if (0 <= v.x && v.x < n && 0 <= v.y && v.y < m && map[v.x][v.y] != '#' && v.z < k) {
				// consume one HP each time
                    if (d(v) > d(u) + (double) abs(map[v.x][v.y] - map[u.x][u.y]) / (k - u.z)) {
                        d(v) = d(u) + (double) abs(map[v.x][v.y] - map[u.x][u.y]) / (k - u.z);
                        p(v);
                    }
                }
            }
        }
    }
    double ans = 1e8;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dis[x2 - 1][y2 - 1][i]); // start from x2, y2
    }
    if (ans == 1e8) {
        puts("No Answer");
    } else {
        printf("%.2f\n", (double) ans);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        solve();
    }
}