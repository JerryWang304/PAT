#include<map>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
map<string,vector<int> > m;
const int maxn = 3000;
int course[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	
	for(int i=0;i<k;i++){
		int a;//a表示课程号 
		int b;//人数 
		cin>>a>>b;
		
		for(int j=0;j<b;j++){
			string name;
			cin>>name;
			m[name].push_back(a);
		}
	}
	//要查询的学生的姓名
	for(int i=0;i<n;i++){
		int length=0;
		string name;
		cin>>name;
		cout<<name<<" "<<m[name].size();
		if(m[name].size()>0) cout<<" ";
		vector<int> v=m[name];
		for(int j=0;j<v.size();j++){
			course[length++]=v[j];
		}
		sort(course,course+length);
		for(int j=0;j<length;j++)
		  if(j==0) 
		     cout<<course[j];
		  else 
		     cout<<" "<<course[j];
		if(i<n-1) cout<<endl;
	} 
	return 0;
}
/*
11 5
4 7
BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
1 4
ANN0 BOB5 JAY9 LOR6
2 7
ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
3 1
BOB5
5 9
AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9
Sample Output:
ZOE1 2 4 5
ANN0 3 1 2 5
BOB5 5 1 2 3 4 5
JOE4 1 2
JAY9 4 1 2 4 5
FRA8 3 2 4 5
DON2 2 4 5
AMY7 1 5
KAT3 3 2 4 5
LOR6 4 1 2 4 5
NON9 0

*/
