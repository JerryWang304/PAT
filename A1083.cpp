#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100100;
struct node{
	string name;
	string id;
	int score;
}Node[maxn]; 
bool cmp(node a,node b){
	return a.score > b.score;
}
int main(){
	int n,min,max;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].name;
		cin>>Node[i].id;
		cin>>Node[i].score;
	}
	cin>>min>>max;
	bool flag=false;
	sort(Node,Node+n,cmp);
	for(int i=0;i<n;i++){
		if(Node[i].score>=min && Node[i].score<=max){
			flag=true;
			cout<<Node[i].name<<" "<<Node[i].id<<endl;
		}
	}
	if(flag==false)
	  cout<<"NONE\n";
	return 0;
}
