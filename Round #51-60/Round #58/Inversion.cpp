#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include<cmath>
#include<climits>
#include<vector>
#include<cfloat>
#include<queue>
#include<cctype>
#include<cstdlib>
#include<cassert>
#define LL long long
using namespace std;
const int N=1e5+10;
int a[N],b[N],c[N];
int n,m;

int lowbit(int x)
{
    return x&(-x);
}

void update(int *b,int i,int val)
{
    while(i<=n)
    {
        b[i]+=val;
        i+=lowbit(i);
    }
}

int sum(int *b,int i)
{
    int ret=0;
    while(i>0)
    {
        ret+=b[i];
        i-=lowbit(i);
    }
    return ret;
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
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(c,0,sizeof(c));
        memset(b,0,sizeof(b));
        
        LL tmp=0;
        for(int i=n;i>m;i--)
        {
            // another imaginary array, with element t[a[i]] = 1
            // sum(c, a[i]-1) is the number of elements smaller than a[i]
            // so far, we have a[i], ..., a[n] inserted
            // tmp is the number of inversion of a[i], ..., a[n]
            tmp+=sum(c,a[i]-1);
            // we add 1 at index a[i] of the imaginary array
            update(c,a[i],1);
        }
        
        // tmp is inversion of a[m+1], ..., a[n]
        // L is now a[1], ..., a[m]
        LL ans=tmp;
        for(int i=m+1;i<=n;i++)
        {
            // for L, remove head, add tail
            
            // the inversion brought by a[i] 
            tmp-=sum(c,a[i]-1);
            update(c,a[i],-1);
            // the inversion brought by a[i-m]
            tmp+=sum(c,a[i-m]-1);
            
            tmp-=sum(b,n)-sum(b,a[i]);
            tmp+=sum(b,n)-sum(b,a[i-m]);
            // i - m -1 
            assert(sum(b,n) == i-m-1);
            update(b,a[i-m],1);
            
            ans=min(ans,tmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}


/*
g​_i​​表示在i前面比a_i​​大的数的个数, f_i​​表示在i后面比a_i​​小的数的个数,

逆序对减少的个数 = 这段区间中g_​i​​的和 + 这段区间f_i​​的和 - 这段区间的逆序对个数

树状数组
*/