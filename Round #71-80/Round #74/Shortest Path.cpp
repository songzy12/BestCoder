#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
int T,n,m,dis[6][6],a[6],x,y;
long long ans;
int main()
{
    scanf("%d",&T);
    int mmod=1e9+7;
    while(T--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
        for (int i=0;i<6;i++)
            for (int j=0;j<6;j++)
                dis[i][j]=abs(a[i]-a[j]);

        dis[0][1]=1;dis[1][0]=1;
        dis[2][3]=1;dis[3][2]=1;
        dis[4][5]=1;dis[5][4]=1;

        for (int k=0;k<6;k++)
            for (int i=0;i<6;i++)
                for (int j=0;j<6;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);

        for (int k=1;k<=m;k++)
        {
            scanf("%d%d",&x,&y);
            // directly
            int mm=abs(x-y);
            // x to some i, i to some j, j to y
            for (int i=0;i<6;i++)
                for (int j=0;j<6;j++)
                    mm=min(mm,abs(a[i]-x)+abs(a[j]-y)+dis[i][j]);
            mm %= mmod;
            ans=(ans+(long long )mm*(long long )k)%mmod;
        }
        printf("%I64d\n",ans);
    //  cout<<ans<<endl;
    }
}