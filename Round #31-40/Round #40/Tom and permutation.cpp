#include<iostream>
#include<cstring>
#include<cstdio>
#define SZY
using namespace std;

long long p = 1e9+7; // just all long long
long long fac[101]; // since int * int is int
int a[101];
long long inv[101];
bool used[101];
bool used_[101];
long long pre[101];
long long factor(int n){
	if(fac[n]!=-1)
		return fac[n];
	if(n==0){
		fac[n]=1;
		return fac[n];
	}
	long long temp = n*factor(n-1);
	temp %= p;
	//cout<<"fact: "<<n<<" "<<factor(n-1)<<" "<<temp<<endl;
	fac[n] = temp;
	return fac[n];
}

long long inverse(int n){
	if(inv[n]!=-1)
		return inv[n];
	if(n==1){
		inv[n]=0;
		return inv[n];
	}
	long long temp1 = (n-1)*n/2 * factor(n-1); // mod, div != div, mod
	temp1 %= p;
	long long temp2 = n*inverse(n-1);
	temp2 %= p;
	inv[n]= (temp1 + temp2) % p;
	// cout<<"inv: "<<n<<" "<<inv[n]<<endl;
	return inv[n];
}

int main(){
	
	ios::sync_with_stdio(false);
#ifdef SZY
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif 
	memset(inv, -1, sizeof(inv));
	memset(fac, -1, sizeof(fac));
	int n;
	a[0]=1;
	while(cin>>n){
		memset(used_, false, sizeof(used_));
		memset(used, false, sizeof(used));
		memset(pre, 0, sizeof(pre));
		for(int i=1; i<=n; i++)
			cin>>a[i];
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++)
				if(a[i]>j && !used_[j])
					pre[i]++;
			used_[a[i]]=true; // a[i] rather than i!
		}
		for(int i=1; i<=n; i++)
			pre[i]+=pre[i-1];
		/*for(int i=1; i<=n; i++)
			cout<<pre[i]<<" ";
		cout<<endl;*/
		long long result = 0;
		for(int i=1; i<=n; i++){
			long long temp = pre[i-1];
			for(int j=1; j<a[i]; j++){
				if(used[j])
					continue;
				long long temp1 = temp; // each time temp remains
				for(int k=1; k<=n; k++)
					if(!used[k] && j>k)
						temp1++;
				temp1 = (temp1*factor(n-i)) % p;
				result = (result + temp1 + inverse(n-i)) % p;
			}
			//cout<<i<<" "<<result<<endl;
			used[a[i]]=true;
		}
		cout<<result<<endl;
	}
	return 0;
}