//���һ�����Ե������ 
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=10010;
const int max_p=100100;
int p[max_p];//ÿ����ķ���

struct node{
	int id;
	int p_id;
	int score;
	int grade[6];
	int total;
	int rank;
	int ps;//������������ 
	bool flag;//false����� 
	node(){
		total=0;
		ps=0;
		flag=false;
		for(int i=0;i<6;i++)
		  grade[i]=-2;//-2��ʾû�ύ��-1��ʾû�б���ͨ�� 
	}
}Node[maxn];//Node[i]��iҲ��ʾ id

int n;//�û����� 
int k;//��Ŀ����
int m;//�ύ����

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
	//�����ܷ�
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=5;j++){
	       if(Node[i].grade[j]>=0){
	         sum+=Node[i].grade[j];
	        }
		}
		Node[i].total=sum;
	} 
	//��������
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


