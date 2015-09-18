#include<iostream>
#include<cmath>
using namespace std;
#define PI 3.1415926535898 
int main(){
	int T;
	cin>>T;
	for(int t=0; t<T; t++){
		cout<<"Case #"<<t+1<<":"<<endl;
		int n;
		double a, r;
		cin>>n>>a>>r;
		double temp = a/2.0/(tan(PI/n)); // notice / and //
		if(temp >= r)
			cout<<"Give me a kiss!"<<endl;
		else
			cout<<"I want to kiss you!"<<endl;
	}
}