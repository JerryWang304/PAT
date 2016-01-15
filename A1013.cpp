#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxn = 10000;

bool vis[maxn];

vector<int> G[maxn];

int current;//当前要删除的点 

int result[maxn];

void dfs(int i){
	if(i == current)
	  return ;
	vis[i]=true;
	
	for(int j=0;j<G[i].size();j++){
		if(vis[G[i][j]] == false)
		 dfs(G[i][j]);
	}
	
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a); 
	}
	
	
	
	for(int i=0;i<k;i++){
		cin>>current;
	//	memset(vis,false,sizeof(vis));
	    fill(vis,vis+maxn,false);	
		for(int j=1;j<=n;j++){
			if(j != current && vis[j]==false){
				dfs(j);
				result[i]++;
			}
		}
		
	}
	for(int i=0;i<k;i++)
	 cout<<result[i]-1<<endl;
	
	return 0;
	
}


 
