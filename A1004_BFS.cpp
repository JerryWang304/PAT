#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int maxn=120;

vector<int> G[maxn];
int leaf[maxn]={0};
int max_h=0;
int h[maxn]={0};//h[i]表示i节点的层号 
void BFS(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int id=q.front();
		q.pop();
		max_h=max(max_h,h[id]);
		if(G[id].size()==0)
		  leaf[h[id]]++;
		  
		for(int i=0;i<G[id].size();i++){
			h[G[id][i]]=h[id]+1;
			q.push(G[id][i]);
		}
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int parent,k;
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			int child;
			cin>>child;
			G[parent].push_back(child);
		}
	} 
	h[1]=1;
	BFS();
	cout<<leaf[1];
	for(int i=2;i<=max_h;i++)
	  cout<<" "<<leaf[i];
	return 0;
}
