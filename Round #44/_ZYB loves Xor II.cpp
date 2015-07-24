#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long x[101000],y[101000];
vector<long long>A[2];
int n;
long long solve(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%I64d",&x[i]);
    for (int i=1;i<=n;i++) scanf("%I64d",&y[i]);
    long long num=0;
    for (int now=0;now<=61;now++){
        A[0].clear(); A[1].clear();
        for (int i=1;i<=n;i++) A[(x[i]>>now)&1].push_back(x[i]);
        int head=0;
        for (int i=0;i<A[0].size();i++) x[++head]=A[0][i];
        for (int i=0;i<A[1].size();i++) x[++head]=A[1][i];
        A[0].clear(); A[1].clear();
        for (int i=1;i<=n;i++) A[(y[i]>>now)&1].push_back(y[i]);
        head=0;
        for (int i=0;i<A[0].size();i++) y[++head]=A[0][i];
        for (int i=0;i<A[1].size();i++) y[++head]=A[1][i];
        long long tot=(1ll<<(now+1))-1,lim=1ll<<now,lim2=(1ll<<now+1),ans=0;
        int a=1,b=1,c=1;
        for (int i=n;i;i--){
            while (a<=n&&(x[i]&tot)+(y[a]&tot)<lim) a++;
            while (b<=n&&(x[i]&tot)+(y[b]&tot)<lim2) b++;
            while (c<=n&&(x[i]&tot)+(y[c]&tot)<lim+lim2) c++;
            ans+=n-(c-1)+(b-1)-(a-1);
        }
    //    cout<<now<<" "<<ans<<endl;
        if (ans&1) num+=(1ll<<now);
    }
    return num;
}
int main(){
    int t; scanf("%d",&t);
    for (int i=1;i<=t;i++) printf("Case #%d: %I64d\n",i,solve());
    return 0;
}