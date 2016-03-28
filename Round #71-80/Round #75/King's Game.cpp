#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

/*
f[i][j]: i people left, starting from j.
f[1][j] = 0;
f[i][j] = (f[i-1][j+1] + j) mod i
f[n][1] + 1 (shift the index to [1, n])
*/

const int N = 5050;
int n,m;
int dp[N];
int ans[N];
int getint()
{
    int res=0;
    char ch=getchar();
    while(ch<'0' || ch>'9')
        ch=getchar();
    while('0'<=ch && ch<='9')
    {
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res;
}
void Init()
{
    int i,j;
    for(i=1;i<N;i++)
        dp[i]=1;
    ans[1]=1;
    for(i=2;i<=5000;i++)
    {
        for(j=1;j+i-1<N;j++)
        {
            int a=(j-1)%i+1;
            int b=i-a;
            int c=dp[j+1];
            if(c<=b)
                dp[j]=a+c;
            else
                dp[j]=c-b;
        }
        ans[i]=dp[1];
    }
}
void f()
{
    printf("%d\n",ans[n]);
}
int main()
{
    Init();
    int T=getint();
    while((scanf("%d",&n))!=EOF)
        f();
    return 0;
}