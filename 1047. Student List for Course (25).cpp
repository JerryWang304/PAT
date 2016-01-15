#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 2550;

struct node{
	vector<string> stu; 
}Course[maxn];
bool cmp(string a,string b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		string name;
		int c;
		cin>>name>>c;
		for(int j=0;j<c;j++){
			int course;
			cin>>course;
			Course[course].stu.push_back(name);
		}
	}
	for(int i=1;i<=k;i++){
		sort(Course[i].stu.begin(),Course[i].stu.end());
	}
	for(int i=1;i<=k;i++){
		cout<<i<<" "<<Course[i].stu.size()<<endl;
		for(int j=0;j<Course[i].stu.size();j++)
			cout<<Course[i].stu[j]<<endl;
	}

	return 0;
}
