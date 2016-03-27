#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<stdlib.h>

using namespace std;

#define ll long long
#define maxn 3000005
#define maxm 500010

int t,n;
int f[maxn],v[maxn],num[maxn];

int main()
{
    scanf("%d",&t);
    long long mod=3221225473;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&f[i]);
            v[i]=0;
            num[i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            if(!v[i]){
                //求循环节长度
                int l=0;
                int k=i;
                while(!v[k]){
                    l++;
                    v[k]=1;
                    k=f[k];
                }
                //质因子分解
                for(int j=2;j*j<=l;j++)
                {
                    int nn=0;
                    while(l%j==0) {nn++;l/=j;}
                    num[j]=max(num[j],nn);
                }
                if(l>1) 
                    // l is prime
                    num[l]=max(1,num[l]);
            }
        }
        
        ll res=1;
        for(int i=2;i<=n;i++)
        {
            while(num[i]--) 
                res=(res*i) % mod;
        }
        printf("%I64d\n",res);
    }
    return 0;
}