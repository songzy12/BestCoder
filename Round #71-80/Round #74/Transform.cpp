#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int d[300000],n,m,x[20];
queue<int> Q;
const int mo = 1e9+7;
void firget()
{
    memset(d,0xff,sizeof d); 
    d[0]=0;
    Q.push(0);
    while (!Q.empty())
    {
        int k1 = Q.front(); Q.pop();
        for (int i = 0;i <= 16;i ++){
            int k2 = (k1 ^ (1<<i));
            if (d[k2] == -1){
                d[k2] = d[k1] + 1; 
                Q.push(k2);
            }
        }
        for (int i = 1;i <= n;i ++){
            int k2 = (k1 ^ x[i]);
            if (d[k2] == -1){
                d[k2] = d[k1] + 1; 
                Q.push(k2);
            }
        }
    }
}
int main()
{
    int t; scanf("%d",&t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1;i <= n;i ++) 
            scanf("%d",&x[i]);
        firget(); 
        int ans = 0, now = 0;
        while(m --){
            now ++;
            int s,t; 
            scanf("%d%d", &s, &t);
            ans = (ans + 1ll * now * d[s^t]) % mo;
        }
        printf("%d\n",ans);
    }
    return 0;
}