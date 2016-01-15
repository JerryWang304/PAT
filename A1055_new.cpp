#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 100100;

struct node{
	string name;
	int age;
	int money;
}Node[maxn],valid[maxn];

bool cmp(node a,node b){
	if(a.money != b.money)
	  return a.money>b.money;
	else if(a.age != b.age)
	  return a.age < b.age;
	return a.name < b.name;
}

int n,k;
int A[maxn]={0};//A[i]=x表示年龄为i有x人 
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>Node[i].name;
		cin>>Node[i].age;
		cin>>Node[i].money;
	}
	sort(Node,Node+n,cmp);
	//剪纸->生成有效数组
	int num_valid=0;
	for(int i=0;i<n;i++){
		if(A[Node[i].age]<101){
			A[Node[i].age]++;
			valid[num_valid++]=Node[i];
		}
	}
	
	for(int i=1;i<=k;i++){
		int count;
		int min_age;
		int max_age;
		cin>>count>>min_age>>max_age;
		int line=0;
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=0;j<num_valid;j++){
			if(line<count){
				if(valid[j].age>=min_age && valid[j].age<=max_age){
					cout<<valid[j].name<<" "<<valid[j].age<<" "<<valid[j].money<<endl;
					line++;
				}
			}else if(line>=count) break; 
		}
		if(line==0)
		 cout<<"None"<<endl;
	}
	return 0;
}










