#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100010;
struct node{
	char name[9];
	int age;
	int money;
}Node[maxn];
typedef struct node N;
bool cmp(node a,node b){
	if(a.money != b.money){
		return a.money > b.money;
	}else if(a.age != b.age){
		return a.age < b.age;
	}
	return strcmp(a.name,b.name)<0;
}

bool cmp_age(node a,node b){
	return a.age < b.age;
}

int n,k;
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
        cin>>Node[i].name;
        cin>>Node[i].age;
        cin>>Node[i].money;
	}
	sort(Node,Node+n,cmp_age);
	for(int i=1;i<=k;i++){
		int count=0;
		int min_age=0,max_age=0;
		//scanf("%d %d %d",&count,&min_age,&max_age);
		cin>>count>>min_age>>max_age;
		cout<<"Case #"<<i<<":"<<endl;
		int length=0;
		N temp[maxn];
		for(int j=0;j<n;j++){
			if(Node[j].age >= min_age && Node[j].age <= max_age)
			  temp[length++]=Node[j];
			if(Node[j].age > max_age)
			  break;
		}
		if(length==0){
			    cout<<"None"<<endl;
		}else{
			sort(temp,temp+length,cmp);
			for(int j=0;j<count;j++){
				  cout<<temp[j].name<<" "<<temp[j].age<<" "<<temp[j].money<<endl;
			}
		}
	}
	return 0;
}
