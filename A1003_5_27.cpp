#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1000;
const int INF = 1e9;
int d[maxn];
int num[maxn];
int w[maxn];
int G[maxn][maxn];

int weight[maxn];
int n,m,c1,c2;
bool vis[maxn]={false};
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	num[s]=1;
	w[s]=weight[s];
	for(int i=0;i<n;i++){
		
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!vis[j] && d[j]< MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(!vis[v] && G[u][v] != INF){
				if(d[u]+G[u][v] < d[v]){
					d[v] = d[u] + G[u][v];
					num[v] = num[u];
					w[v] = w[u] + weight[v];
				}else if(d[u] + G[u][v] == d[v]){
					num[v]+=num[u];
					if(w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
				}
			}
		}
		
	}
}


int main(){
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
	  cin>>weight[i];
	//³õÊ¼»¯Í¼
	fill(G[0],G[0]+maxn*maxn,INF); 
	for(int i=0;i<m;i++){
		int a,b,len;
		cin>>a>>b>>len;
		G[a][b]=len;
		G[b][a]=len;
	}
	Dijkstra(c1);
	cout<<num[c2]<<" "<<w[c2];
	return 0;
}
