//成绩相同的排名也相同 
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2010;
struct node{
	int id;
	bool isIn;
	int c;
	int m;
	int e;
	int a;
	int c_rank;
	int m_rank;
	int e_rank;
	int a_rank;
	int high;
	char H;
}Node[maxn],C[maxn],M[maxn],E[maxn],A[maxn];

const int maxnn=999999+3;//忘了id最大可以达到9999999，原来定义的result[max]太小，数组越界了 
struct re{
	bool isIn;
	int high;
	char H; 
}result[maxnn];

bool cmpC(node a,node b){

	  return a.c>b.c;
}

bool cmpM(node a,node b){

	  return a.m > b.m;
}

bool cmpE(node a,node b){
	
	  return a.e>b.e;
}

bool cmpA(node a,node b){

	  return a.a>b.a;
}


int main(){
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<maxnn;i++){
		result[i].isIn=false;
	}
	
	for(int i=0;i<n;i++){
		
		cin>>Node[i].id;
		cin>>Node[i].c;
		cin>>Node[i].m;
		cin>>Node[i].e; 
		int sum=(Node[i].c+Node[i].m+Node[i].e);
		double av=sum/3.0;
		int t=(int)(av*10)%10;
		if(t>=5)
		  Node[i].a=(int)(av)+1;
		else
		  Node[i].a=(int)(av);
		//cout<<Node[i].a<<endl;
		Node[i].isIn=true;
		
	}
	//读入查找的Id
	int num[maxn];
	for(int i=0;i<m;i++){
		cin>>num[i];
	}

	//c排序 
	sort(Node,Node+maxn,cmpC);
	for(int i=0;i<n;i++){
		Node[i].c_rank=i+1;
	}
	//修正排名
	for(int i=1;i<n;i++){
		if(Node[i].c == Node[i-1].c)
		  Node[i].c_rank = Node[i-1].c_rank;
		else
		  Node[i].c_rank = i+1; 
	} 
	
	//M排序 
	sort(Node,Node+maxn,cmpM);
	for(int i=0;i<n;i++){
		Node[i].m_rank=i+1;
	}
	
	//修正排名
	for(int i=1;i<n;i++){
		if(Node[i].m == Node[i-1].m)
		  Node[i].m_rank = Node[i-1].m_rank;
		else
		  Node[i].m_rank = i+1; 
	} 
	
	//E排序 
	sort(Node,Node+maxn,cmpE);
	for(int i=0;i<n;i++){
		Node[i].e_rank=i+1;
	}
	
	//修正排名
	for(int i=1;i<n;i++){
		if(Node[i].e == Node[i-1].e)
		  Node[i].e_rank = Node[i-1].e_rank;
		else
		  Node[i].e_rank = i+1; 
	} 
	
	//A排序 
	sort(Node,Node+maxn,cmpA);
	for(int i=0;i<n;i++){
		Node[i].a_rank=i+1;
		//cout<<Node[i].a_rank<<endl;
		
	}
	
    //修正排名
	for(int i=1;i<n;i++){
		if(Node[i].a == Node[i-1].a)
		  Node[i].a_rank = Node[i-1].a_rank;
		else
		  Node[i].a_rank = i+1; 
	} 
	
	
	//得到最高的排名及科目
	for(int i=0;i<n;i++){
		int t1=min(Node[i].m_rank,Node[i].e_rank);
		int t2=min(Node[i].c_rank,Node[i].a_rank);
		int temp=min(t1,t2);
		Node[i].high=temp;
		if(Node[i].a_rank==temp)
		 Node[i].H='A';
		else if(Node[i].c_rank==temp)
		 Node[i].H='C';
		else if(Node[i].m_rank==temp)
		 Node[i].H='M';
		else if(Node[i].e_rank==temp)
		 Node[i].H='E';
		 //cout<<temp<<endl;
	} 
	int ID;
	for(int i=0;i<n;i++){
		ID=Node[i].id;
		result[ID].high=Node[i].high;
		result[ID].H=Node[i].H;
		result[ID].isIn=true;

	}
	for(int i=0;i<m;i++){
		int x=num[i];
		if(result[x].isIn==false)
		  cout<<"N/A"<<endl;
		else{
			cout<<result[x].high<<" "<<result[x].H<<endl;
		}
	}
	return 0;
}
