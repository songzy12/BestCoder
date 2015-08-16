#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
using namespace std;
#define SZY

int main(){
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int h = 360*12000/(60*60*12);
	int m = 360*12000/(60*60);
	int x;
	while(cin>>x){
		for(int h1 = 0; h1 < 12; h1++)
			for(int m1 = 0; m1 < 60; m1++)
				for(int s1 = 0; s1 < 60; s1+=10){
					int time = h1*60*60 + m1*60 + s1;
					int dif = abs(time*h - (time % 3600)*m);
					if (dif == x || 360*12000 - dif == x){ // failed system test, inferior angle
						cout<<setw(2)<<setfill('0')<<h1<<":"<<setw(2)<<setfill('0')<<m1<<":"<<setw(2)<<setfill('0')<<s1<<endl;
					}
				}
	}
	return 0;
}