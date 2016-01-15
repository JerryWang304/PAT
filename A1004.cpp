#include<iostream>
#include<queue>
using namespace std;
const int maxn=120;
struct node{
	int num;//序号
	int level;
	queue<node> child;  
}Node[maxn];//存入非叶子节点 


void p(node n){
	cout<<"num: "<<n.num<<endl;
	cout<<"level: "<<n.level<<endl;
	while(!n.child.empty()){
		node temp = n.child.front();
		p(temp);
		n.child.pop();
	} 
}

int main(){
	int n,m;
	cin>>n>>m;
 
	//非叶子节点 
	int max=-1;
	for(int i=1;i<=m;i++){
		int id,k;
		cin>>id>>k;
		Node[i].num=id;
		if(id==1) 
		   Node[i].level=1;
		if(Node[i].level>max)
		   max=Node[i].level;//max=最终的层数 
		for(int j=0;j<k;j++){
			node temp;
			int x;
			cin>>x;
			temp.num=x;
			temp.level=Node[i].level+1;
			if(temp.level>max)
			  max=temp.level;
			Node[x].num=x;
			Node[x].level=Node[i].level+1;
			Node[i].child.push(Node[x]);
		}

	}
	if(n==1){
		cout<<1;
		return 0;
	}//没这句，测试点2过不了	
	//test
//	p(Node[1]);
//	p(Node[2]);
//	p(Node[3]);
//	cout<<"max="<<max<<endl;
	int num[maxn]={0};//num[i]=x;表示第i层有x个叶子节点 
	queue<node> q;
	while(!q.empty())
	 q.pop();
	q.push(Node[1]);
	while(!q.empty()){
		node temp=q.front();
//		cout<<"temp.num="<<temp.num<<endl;
//		cout<<"temp.level="<<temp.level<<endl;
//		cout<<"temp.child.size()="<<temp.child.size()<<endl;
		if(temp.child.empty())
		   num[temp.level]++;
		//cout<<"num["<<temp.level<<"]:"<<num[temp.level]<<endl;
		q.pop();
		while(!temp.child.empty()){
			node t=temp.child.front();
			temp.child.pop();
			q.push(Node[t.num]);//之前是q.push(t);导致好几个测试点过不了 
		}
	}
	
	for(int i=1;i<=max;i++)
	 if(i<max)
	   cout<<num[i]<<" ";
	 else 
	   cout<<num[i];
	return 0;
	
}
/*
input->
6 3
01 2 02 03
02 1 04
03 2 05 06
output->
0 0 3
*/ 
