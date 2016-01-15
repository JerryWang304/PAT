#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1200;
//vector<int> g[maxn]; //g[i]保存i的粉丝 
queue<int> g[maxn];
struct node{
	int id;
	int level;
}Node[maxn]; 

int n,L;
bool vis[maxn]={false};
int num_forward=0;//被转发的次数 
void DFS(int s,int level){
	if(level>L)
	  return ;
	vis[s]=true;
	num_forward++;
	for(int i=0;i<g[s].size();i++){
		int now=g[s][i];
		if(!vis[now])
		  DFS(now,level+1);
	}
	
}
//设置层数 
void BFS(int s,int level){
	if(!vis[s]){
		q.push(s);
	}
	while(!q.empty()){
		int front = q.front();
		a.pop();
		
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
			g[temp].push_back(i);
		}
	}
	int k,q;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>q;
		num_forward=0;
		fill(vis,vis+maxn,false);
		DFS(q,0);
		cout<<num_forward-1<<endl;
	}
	
}

