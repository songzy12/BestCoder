#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<iomanip>
#define x first
#define y second
#define pii pair<int, int>
using namespace std;
struct Student{
	string name;
	string sex;
	int round1;
	int round2;
	double total;
}student[100];

bool cmp(Student s1, Student s2){
	return s1.total > s2.total;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int T, m, n;
	cin>>T;
	while(T--){
		cout<<"The member list of Shandong team is as follows:"<<endl;
		cin>>n>>m;
		int max1 = 0, max2 = 0;
		for(int i = 0; i < n; ++i){
			cin>>student[i].name>>student[i].sex>>student[i].round1>>student[i].round2;
			if(student[i].round1 > max1)
				max1 = student[i].round1;
			if(student[i].round2 > max2)
				max2 = student[i].round2;
		}
		for(int i = 0; i < n; ++i)
			student[i].total = student[i].round1*300*0.3/max1 + student[i].round2*300*0.7/max2;
		sort(student, student+n, cmp);
		bool found = false;
		int i = 0;
		while(i < m-1){
			cout<<student[i].name<<endl;
			if(student[i].sex[0] == 'f')
				found = true;
			i++;
		}
		if(found)
			cout<<student[i].name<<endl;
		else{
			while(i < n && student[i].sex[0] != 'f')
				i ++;
			cout<<student[i].name<<endl; // presentation error.
		}
	}
	return 0;
}