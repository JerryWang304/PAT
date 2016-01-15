//用cin cout 最后一组超时 
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100002;

struct node{
	//string id;
	char id[10];
	//string name;
	char name[10];
	int grade;
}Node[maxn]; 

int n;
int c;

bool cmp1(node a,node b){
	//return a.id < b.id;
	return strcmp(a.id,b.id)<0;
}

bool cmp2(node a,node b){
	if(strcmp(a.name,b.name) != 0)
	  return strcmp(a.name,b.name)<0;
	else
	  return strcmp(a.id,b.id)<0;
}

bool cmp3(node a,node b){
	if(a.grade != b.grade)
	   return a.grade < b.grade;
	else
	   return strcmp(a.id,b.id)<0;
}

int main(){
	//cin>>n>>c;
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++){
//		cin>>Node[i].id;
//		cin>>Node[i].name;
//		cin>>Node[i].grade;
        scanf("%s",Node[i].id);
        scanf("%s",Node[i].name);
        scanf("%d",&Node[i].grade);
	}
	if(c==1){
		sort(Node,Node+n,cmp1);
	}else if(c==2){
		sort(Node,Node+n,cmp2);
	}else if(c==3){
		sort(Node,Node+n,cmp3);
	}
	for(int i=0;i<n;i++)
	  //cout<<Node[i].id<<" "<<Node[i].name<<" "<<Node[i].grade<<endl;
	  printf("%s %s %d\n",Node[i].id,Node[i].name,Node[i].grade);
	return 0;
}
