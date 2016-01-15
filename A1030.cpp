#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 600;
int g[maxn][maxn],cost[maxn][maxn];
const int INF = 1e9;
int n,m,s,dis;
bool vis[maxn]={false};
int d[maxn];
vector<int> pre[maxn];
vector<int> temp,path;
int minCost=INF;
void Dijkstra(int start){
	fill(d,d+maxn,INF);
	d[start]=0;

	for(int i=0;i<maxn;i++){
		pre[i].push_back(i);
	}
	for(int i=0;i<n;i++){
		int u=-1,MIN = INF;
		for(int j=0;j<n;j++){
			if(!vis[j] && d[j]<MIN){
				u=j;
				MIN = d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(!vis[v] && g[u][v] != INF){
				if(d[v] > d[u] + g[u][v]){
					d[v] = d[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[v] == d[u] + g[u][v]){
					pre[v].push_back(u);
				}
			}
		}
	}
	
}

void DFS(int now){

	if(now == s){
		temp.push_back(now);
		int costTemp=0;
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],id2=temp[i-1];
			costTemp+=cost[id][id2];
		}
		if(costTemp<minCost){
			path=temp;
			minCost = costTemp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(now);
	for(int i=0;i<pre[now].size();i++)
	  DFS(pre[now][i]);
	temp.pop_back();
}

int main(){
	fill(g[0],g[0]+maxn*maxn,INF);
	cin>>n>>m>>s>>dis;
	for(int i=0;i<m;i++){
		int a,b,length,c;
		cin>>a>>b>>length>>c;
		g[a][b]=length;
		g[b][a]=length;
		cost[a][b]=c;
		cost[b][a]=c;
	}
	Dijkstra(s);
	DFS(dis);
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i]<<" ";
	}
	cout<<d[dis]<<" "<<minCost;
	return 0;
}
