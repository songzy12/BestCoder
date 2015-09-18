#include<iostream>
using namespace std;
int main(){
	int n, m;
	while(cin >> n >> m){
		if (m%n)
			cout<<m%n-1<<endl;
		else
			cout<<n-1<<endl;
	}
}