#include<iostream>
#include<cstdio>
using namespace std;
#define SZY

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	return 0;
}