#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int maxn=100005;
int d[maxn];
int deep[maxn];
int dp[maxn][21];
int tree[maxn];
int st[maxn],ed[maxn];
vector<int>g[maxn];
int n,q;
int o;

void dfs(int rt,int f,int sh)
{
    st[rt]=++o;
    deep[rt]=sh;
    if(f==-1)
        dp[rt][0]=rt;
    else
        dp[rt][0]=f;
    for(int i=1;i<=20;i++){
        dp[rt][i]=dp[dp[rt][i-1]][i-1];
    }
    for(int i=0;i<g[rt].size();i++){
        if(g[rt][i]==f)
            continue;
        dfs(g[rt][i],rt,sh+1);
    }
    ed[rt]=o+1;
}

int lca(int a,int b)
{
    int deep1=deep[a];
    int deep2=deep[b];
    if(deep1<deep2){
        swap(deep1,deep2);
        swap(a,b);
    }
    int y=deep1-deep2;
    for(int i=0;i<=20;i++){
        if(y&(1<<i)){
            a=dp[a][i];
        }
    }
    if(a==b)
        return a;
    for(int i=20;i>=0;i--){
        if(dp[a][i]==dp[b][i])
            continue;
        a=dp[a][i];
        b=dp[b][i];
    }
    return dp[a][0];
}

int lowbit(int x)
{
    return x&(-x);
}

void update(int a,int x)
{
    while(a<=o){
        tree[a]^=x;
        // lowbit?
        a+=lowbit(a);
    }
}

int query(int x)
{
    int ans=0;
    while(x>0){
        ans^=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--){
        o=0;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&d[i]);
            // for weight 0
            d[i]++;
        }
        dfs(1,-1,0);
        memset(tree,0,sizeof(tree));
        // st, ed is the index of i when expanded
        // tree[a] 
        for(int i=1;i<=n;i++){
            update(st[i],d[i]);
            update(ed[i],d[i]);
        }
        int c;
        for(int i=0;i<q;i++){
            scanf("%d%d%d",&c,&a,&b);
            if(c==0){
                // erase the old value
                update(st[a],d[a]);
                update(ed[a],d[a]);
                d[a]=b+1;
                // set the new value
                update(st[a],d[a]);
                update(ed[a],d[a]);
            }
            else{
                int ans=query(st[a])^query(st[b])^d[lca(a,b)];
                if(ans==0)
                    printf("-1\n");
                else
                    printf("%d\n",ans-1);
            }
        }
    }
    return 0;
}