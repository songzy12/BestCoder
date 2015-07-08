#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int a[4][13];
//brute force
//11, 12, 13, 1, 2 is not
int compute(){
	int max = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<10; j++){
			int temp = 0;
			for(int k=0; k<5; k++){
				if(a[i][(j+k)%13]==1)
					temp+=1;
			}
			if(temp>max)
				max=temp;
		}
	}
	return max;
}

void solve(){
	char s;
	int n;
	memset(a, 0, sizeof(a));
	for(int i=0; i<5; i++){
		cin>>s>>n;
		if(s=='A')
			a[0][n-1]=1;
		else if(s=='B')
			a[1][n-1]=1;
		else if(s=='C')
			a[2][n-1]=1;
		else if(s=='D')
			a[3][n-1]=1;
	}
	int max = compute();
	cout<<5-max<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0; t<T; t++)
		solve();
	return 0;
}