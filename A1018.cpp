#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 1000;
int G[maxn][maxn];
const int INF = 1e9;

int weight[maxn];
int MAX,n,p,m;
bool vis[maxn]={false};
int d[maxn];
int minNeed=INF,minRemain=INF;
vector<int> pre[maxn];
vector<int> path,temp;

void Dijkstra(int s){

    for(int i=0;i<=n;i++){
    	pre[i].push_back(i);
	}
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<=n;j++){
			if(!vis[j] && d[j] < MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(!vis[v] && G[u][v]!=INF){
				if(G[u][v]+d[u] < d[v]){
					d[v] = G[u][v]+d[u];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(G[u][v]+d[u] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
//DFS遍历上一步形成的路径，从终点开始 
void DFS(int v){
	if(v==0){
		temp.push_back(v);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id] > 0){
				remain+=weight[id];
			}else{
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}else{
					need+=abs(weight[id]) - remain;
					remain=0;
				}
			}
		}
		if(need < minNeed){
			minNeed = need;
			minRemain=remain;
			path=temp;
		}else if(need == minNeed && remain < minRemain){
			minRemain = remain;
			path = temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	  DFS(pre[v][i]);
	temp.pop_back();
}


int main(){
	cin>>MAX>>n>>p>>m;
	for(int i=1;i<=n;i++){
	    cin>>weight[i];
	    weight[i] -=MAX/2;
	}

	int a,b,t;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		cin>>a>>b>>t;
		G[a][b]=t;
		G[b][a]=t;
	}
	Dijkstra(0);
	DFS(p);
	cout<<minNeed<<" ";
	for(int i=path.size()-1;i>=0;i--){
		cout<<path[i];
		if(i>0) cout<<"->";
		
	}
	cout<<" "<<minRemain;
	return 0;
}
