// 每当选定的温度达到一个区间x的左端点时，答案加上 a_x-c_x
// 每当选定温度超过x的右端点时，答案会加上 b_x-a_x​​ 
// 我们在x的左端点处加上a_x-c_x
// 在x的右端点处加上b_x-a_x
// 然后某个位置的前缀和就是选择这个位置作为最终温度的答案了。

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 150005
#define ll long long
using namespace std;

struct note{
    int y;
    double x;
}a[maxn];

int T,n,tot;

ll ans;

ll pri;

bool cmp(note i,note j){
    return i.x<j.x;
}

int main(){
    scanf("%d",&T);
    while (T--) {
        ans=0;
        tot=0;
        scanf("%d",&n);
        fo(i,1,n) {
            int l,r,x,y,z;
            scanf("%d%d%d%d%d",&l,&r,&x,&y,&z);
            ans+=z;
            ++tot;
            a[tot].x=l;
            a[tot].y=x-z;
            ++tot;
            a[tot].x=r+0.5;
            a[tot].y=y-x;
        }
        sort(a+1,a+tot+1,cmp);
        pri=ans;
        fo(i,1,tot) {
            ans+=a[i].y;
            if (i<tot && a[i].x==a[i+1].x) continue;
            pri=max(ans,pri);
        }
        pri=max(ans,pri);
        printf("%I64d\n",pri);
    }
    return 0;
}
