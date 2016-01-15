#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;
map<int,set<string> > m;

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		string name;
		int c;
		cin>>name;
		cin>>c;
		for(int j=0;j<c;j++){
			int course;
			cin>>course;
			m[course].insert(name);
		}
	}
	for(int i=1;i<=k;i++){
		cout<<i<<" "<<m[i].size()<<endl;
		for(set<string>::iterator it=m[i].begin(); it != m[i].end();it++){
			cout<<*it<<endl;
		}
	}
	return 0;
} 
