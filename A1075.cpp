//最后一个测试点过不了 
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=10010;
const int max_p=100100;
int p[max_p];//每道题的分数

struct node{
	int id;
	int p_id;
	int score;
	int grade[6];
	int total;
	int rank;
	int ps;//完美解答的题数 
	bool flag;//false则不输出 
	node(){
		total=0;
		ps=0;
		flag=false;
		for(int i=0;i<6;i++)
		  grade[i]=-2;//-2表示没提交，-1表示没有编译通过 
	}
}Node[maxn];//Node[i]的i也表示 id

int n;//用户总数 
int k;//题目总数
int m;//提交总数

bool cmp_rank(node a,node b){
	return a.total>b.total;
}

bool cmp(node a,node b){
	if(a.rank != b.rank)
	  return a.rank < b.rank;
	else if(a.ps != b.ps)
	  return a.ps > b.ps;
	return a.id < b.id;
}
 
int main(){
	cin>>n>>k>>m;
	for(int i=1;i<=k;i++)
	  cin>>p[i];
	int id,p_id,score;
	for(int i=1;i<=m;i++){
		cin>>id>>p_id>>score;
		Node[id].id=id;
		if(score>=0)
		  Node[id].flag=true;
		  
		if(score>Node[id].grade[p_id])
		  Node[id].grade[p_id]=score;
		if(score==p[p_id])
		  Node[id].ps++;
	}
	//计算总分
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=5;j++){
	       if(Node[i].grade[j]>=0){
	         sum+=Node[i].grade[j];
	        }
		}
		Node[i].total=sum;
	} 
	//计算排名
	sort(Node+1,Node+n+1,cmp_rank); 
	Node[1].rank=1;
	for(int i=2;i<=n;i++){
		if(Node[i].total == Node[i-1].total)
		  Node[i].rank=Node[i-1].rank;
		else
		  Node[i].rank=i;
	}
	sort(Node+1,Node+n+1,cmp);
	for(int i=1;i<=n;i++){
        if(Node[i].flag){
        	printf("%d %05d %d",Node[i].rank,Node[i].id,Node[i].total);
		    for(int j=1;j<=k;j++){
			  if(Node[i].grade[j]==-2)
			    cout<<" -";
			   else if(Node[i].grade[j]==-1)
			    cout<<" 0";
		       else 
			    cout<<" "<<Node[i].grade[j];
			  if(j==k)
			     cout<<endl;
		    }
        }
	}
	return 0;
} 


