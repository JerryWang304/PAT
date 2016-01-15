#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1020;
struct node{
	int id;
	int level;
	vector<node> child;
}Node[maxn];

bool vis[maxn]={false};

int n,L,num_forward=0;
queue<int> q;
void BFS(int s){
	while(!q.empty())
	 q.pop();
	if(!vis[s])
	  q.push(s);

	while(!q.empty()){

		int front=q.front();
		vis[front]=true;
		q.pop();
		if(Node[front].level>L) return ;
		if(Node[front].level<=L && Node[front].level > 0)
	      num_forward++;
	    //if(Node[front].level > L) return ;
    	for(int i=0;i<Node[front].child.size();i++){
	    	int now=Node[front].child[i].id;
	    	Node[now].level=Node[front].level+1;

	    	if(!vis[now])
			  q.push(now);
	   }
	}
}
int main(){
	cin>>n>>L;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=0;j<num;j++){
			int temp;
			cin>>temp;
			Node[i].id=i;
			Node[temp].child.push_back(Node[i]); 
		}
	}
	int k;
	cin>>k;
	
	for(int i=0;i<k;i++){
		int q;
		cin>>q;
		fill(vis,vis+maxn,false);
		for(int j=1;j<=n;j++)
		  Node[j].level=0;
		//以q为起点，更新层数 
		num_forward=0;
		BFS(q);
		cout<<num_forward<<endl;
	}
}

