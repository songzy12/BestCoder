#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,n,m,q,i,j,k,l1,l2,r1,r2,opt;
int a[505][505],c[505][505];

void C(int x,int y,int z)
{
    for(int i=x;i<=n;i+=i&-i)
    for(int j=y;j<=m;j+=j&-j)
    a[i][j]^=z;
}

int Q(int x,int y)
{
    int z=0;
    for(int i=x;i;i-=i&-i)
    for(int j=y;j;j-=j&-j)
    z^=a[i][j];
    return z;
}

int main()
{
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            scanf("%d",&c[i][j]);
            a[i][j]=0;
        }
        for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        C(i,j,c[i][j]);
        for(;q;--q)
        {
            scanf("%d",&opt);
            if(opt==1)
            {
                scanf("%d%d%d%d",&l1,&l2,&r1,&r2);
                if(Q(r1,r2)^Q(l1-1,r2)^Q(r1,l2-1)^Q(l1-1,l2-1))printf("Yes\n");
                else printf("No\n");
            }
            else
            {
                scanf("%d%d%d",&i,&j,&k);
                C(i,j,k^c[i][j]);
                c[i][j]=k;
            }
        }
    }
}