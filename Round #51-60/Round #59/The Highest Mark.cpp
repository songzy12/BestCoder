#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <deque>
#include <map>
#include <algorithm>
#include <vector>
#include <iostream>
#define pii pair<int,int>
#define back que[rear-1]
#define INF 0x3f3f3f3f
#define LL long long
#define ULL unsigned long long
using namespace std;
const double PI  = acos(-1.0);
const int N=1010;
struct node
{
    int a, b, c;
    double rate;
}seq[N];

int n, time, dp[N*3];
// greedy
int cmp(node a,node b)
{
    int t2=a.c+b.c;
    return b.b*b.c+a.b*t2>=a.b*a.c+b.b*t2;
}
// dp
int cal()
{
    sort(seq+1,seq+n+1, cmp);
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=1; i<=n; i++)
        for(int j=time; j>=seq[i].c; j--)
        {
            if( dp[j-seq[i].c]<0 )   continue;
            int v=seq[i].a - j*seq[i].b;
            dp[j]=max( dp[j], dp[j-seq[i].c]+v );
        }
    int ans=0;
    for(int i=time; i>=0; i--)
        ans=max(ans, dp[i]);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&time);
        for(int i=1; i<=n; i++)
            scanf("%d%d%d", &seq[i].a,&seq[i].b,&seq[i].c);
        cout<<cal()<<endl;
    }
    return 0;
}