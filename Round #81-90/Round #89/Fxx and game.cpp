#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define maxn 1000005
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

ll ans;

int d[maxn];

int X,k,t;

int f[maxn];

int T;

int main(){
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d",&X,&k,&t);
        mem(f,63);
        int head=1,tail=0;
        f[1]=0;
        d[++tail]=1;
        fo(i,2,X) {
            if (i % k==0) f[i]=f[i / k]+1;
            while (head<=tail && d[head]+t<i) head++;
            if (head<=tail) f[i]=min(f[i],f[d[head]]+1);
            d[++tail]=i;
            while (head<tail && f[d[tail-1]]>f[d[tail]]) d[tail-1]=d[tail],tail--;
        }
        cout<<f[X]<<endl;
    }
    return 0;
}

/* the `/` and `-` operation may interlap
 * need dp
 */
 
 /*
    单调队列，望文生义，就是指队列中的元素是单调的。如：{a1,a2,a3,a4……an}满足a1<=a2<=a3……<=an,a序列便是单调递增序列。同理递减队列也是存在的。
    单调队列的出现可以简化问题，队首元素便是最大（小）值，这样，选取最大（小）值的复杂度便为o（1），由于队列的性质，每个元素入队一次，出队一次，维护队列的复杂度均摊下来便是o（1）。

    如何维护单调队列呢，以单调递增序列为例：

    1、如果队列的长度一定，先判断队首元素是否在规定范围内，如果超范围则增长队首。    2、每次加入元素时和队尾比较，如果当前元素小于队尾且队列非空，则减小尾指针，队尾元素依次出队，直到满足队列的调性为止

    要特别注意头指针和尾指针的应用。
  */