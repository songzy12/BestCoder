#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define PII pair<int,int>
#define VPII vector<PII>
typedef long long LL;
using namespace std;
const int MOD = 998244353;
const int SIZE = 1010;
int tran[SIZE][8];
PII bfs[SIZE*SIZE];
int tt,used[SIZE][SIZE];
int two[SIZE];
VPII e[SIZE][SIZE];
struct Union_Find{
    int d[SIZE*SIZE],num[SIZE*SIZE];
    void init(int n){
        REP(i,n)d[i]=i,num[i]=1;
    }
    int find(int x){
        return (x!=d[x])?(d[x]=find(d[x])):x;
    }
    bool uu(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return 0;
        if(num[x]<=num[y]){
            num[y]+=num[x];
            d[x]=y;
        }
        else{
            num[x]+=num[y];
            d[y]=x;
        }
        return 1;
    }
}U;
// all (i,j) YJC set or not
// find equivalent set P_i
int main(){
    two[0]=1;
    REPP(i,1,SIZE)two[i]=two[i-1]*2%MOD;
    int n,m;
    while(RII(n,m)==2){
        tt++;
        REPP(i,1,n+1){
            REP(j,m)RI(tran[i][j]);
        }
        U.init((n+1)*(n+1));
        REP(i,n+1)REP(j,n+1)e[i][j].clear();
        REP(y1,n+1)REP(x1,y1){
            REP(i,m){
                int x2=tran[x1][i];
                int y2=tran[y1][i];
                if(x2>y2)swap(x2,y2);
                e[x2][y2].PB(MP(x1,y1));
            }
        }
        int ll=0,rr=0;
        REPP(i,1,n+1){
            used[0][i]++;
            bfs[rr++]=MP(0,i);
        }
        while(ll<rr){
            int x=bfs[ll].F;
            int y=bfs[ll].S;
            REP(i,SZ(e[x][y])){
                int x2=e[x][y][i].F;
                int y2=e[x][y][i].S;
                if(used[x2][y2]!=tt){
                    used[x2][y2]=tt;
                    bfs[rr++]=MP(x2,y2);
                }
            }
            ll++;
        }
        REPP(y,1,n+1)REPP(x,1,y){
            if(used[x][y]!=tt)U.uu(x,y);
        }
        LL an=two[n]-n-1;
        REPP(i,1,n+1){
            if(U.find(i)==i){
                if(U.num[i]>1){
                    an-=two[U.num[i]]-U.num[i]-1;
                }
            }
        }
        an%=MOD;
        if(an<0)an+=MOD;
        cout<<an<<endl;
    }
    return 0;
}