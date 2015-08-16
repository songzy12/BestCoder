#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define DEBUG
using namespace std;
int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int lcm(int a, int b){
	return a*b/gcd(a,b);
}
int main(){
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	for(int n=1; n<50; n++){
		long long ans = 0;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				for(int k=1; k<=n; ++k){
					for(int l=1; l<=n; ++l){
						ans += lcm(gcd(i,j), gcd(k,l));
					}
				}
			}
		}
		cout<<n<<" "<<ans<<endl;
	}
	return 0;
}