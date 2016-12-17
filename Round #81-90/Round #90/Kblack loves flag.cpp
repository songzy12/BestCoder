#include <iostream>
#include <cstring>
using namespace std;

const int _K=50268147,_B=6082187,_P=100000007; 
int _X; 
inline int get_rand(int _l,int _r){ 
    _X=((long long)_K*_X+_B)%_P; 
    return _X%(_r-_l+1)+_l; 
} 

int n,m,k,seed; 

int x[1000001],y[1000001]; 
void Init() {
    scanf("%d%d%d%d",&n,&m,&k,&seed); 
    _X=seed; 
    for (int i=1;i<=k;++i) 
        x[i]=get_rand(1,n), y[i]=get_rand(1,m); 
}

void solve() {
    bool line[1000001], row[1000001];
    memset(line,false,sizeof line);
    memset(row,false,sizeof row);
    for (int i=1;i<=k;++i) {
        row[x[i]] = true;
        line[y[i]] = true;
    }
    int cn=0, cm=0;
    for (int i = 1; i <= n; ++i) {
        if (!row[i])
            ++cn;
    }
    for (int i = 1; i<= m; ++i) {
        if (!line[i])
            ++cm;
    }
    cout<<cn<<" "<<cm<<endl;
}

int main() {
    int T;
    cin>>T;
    while(T--) {
        Init();
        solve();
    }        
}