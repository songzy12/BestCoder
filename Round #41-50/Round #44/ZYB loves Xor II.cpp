#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

typedef unsigned long long ll;
const int maxn=(int)1e5+5;
int n;
ll a[maxn],b[maxn],c[maxn];

void merge (ll *p,ll mod) {   //在给定的mod下归并排序
	int i,j,k,m;
	for(i=1;i<=n;i++) {
		c[i]=p[i];
		if(p[i]>=mod)
			break;
	}
	m=j=i;
	for(i=j;i<=n;i++)
		c[i]=p[i]%mod;
    // c[i] is p[i] % mod
	i=1;
    // for boundary
    c[n+1]=mod<<1;
	for(k=1;k<=n;k++) {
		if(c[i]<c[j]&&i<m) 
            p[k]=c[i++];
		else p[k]=c[j++];
	}
}

ll bigthan (ll m) {             //大于m的数对对数
	int i,j=n;
    ll ans=0;
	for (i=1;i<=n;i++) {
		while ((a[i]+b[j])>=m&&j>0) 
            j--;
        // for a[i], b[j+1] to b[n] is suitable
		ans+=n-j;
	}
	return ans;
}

bool get (ll mod) {               //考虑mod位是否为1
    // sort a and b, after elements module (mod<<1)
	merge (a,mod<<1); 
	merge (b,mod<<1);
    // [X and (1<<i​​)>0]=[X >= (1<<i​​)]−[X >= (1<<(i+1)​​)]+[X >= (3*(1<<i)​​)]
	ll ans = bigthan(mod) + bigthan(3*mod) - bigthan(mod<<1);
    // xor of position mod = 1 <=> number of 1 at position mod is odd
	if ( ans%2 ) 
        return true;
	return false;
}

int main () 
{
//	freopen("aa.txt","r",stdin);
	int cas,T,i;
    ll mod,ans;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++) {
		scanf("%d",&n);
		for(i=1;i<=n;i++) 
            scanf("%I64d",a+i);
		for(i=1;i<=n;i++) 
            scanf("%I64d",b+i);
		sort(a+1,a+n+1);
        sort(b+1,b+n+1);
		ans=0;
        mod=(ll)1<<61;
		while(mod) {
			if (get(mod)) 
				ans+=mod;
			mod=mod>>1;
		}
		cout<<"Case #"<<cas<<": "<<ans<<endl;
	}
}