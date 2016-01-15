#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000;
const int INF=100000000;
int n,m,c1,c2;
int length[maxn][maxn];//g[x][y],x与y之间的长度 
int weight[maxn];//res[i]，城市i的急救队的个数 
int d[maxn];//d[i]表示s->i最短距离，s表示起点
int w[maxn];//w[i]表示s->i最大点权，s为起点
int num[maxn];//num[s]表示从s出发到终点的最短距离条数
bool vis[maxn]={false};//顶点是否已被访问 

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	//vis[s]=true;加了这句只能过一个测试点orz 
	for(int i=0;i<n;i++){
		int u=-1,min=INF;
		
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j] < min){
				u=j;
				min=d[j];
			}
		} 
		if(u==-1) 
		   return;		
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false && length[u][v] != INF){
				if(d[u]+length[u][v]<d[v]){
					d[v]=d[u]+length[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}else if(d[u]+length[u][v] == d[v]){
					if(w[u]+weight[v]>w[u])
					   w[v]=w[u]+weight[v];
					num[v]+=num[u];
				}
			}
		}	
	}
}

int main(){
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
	  cin>>weight[i];
	fill(length[0],length[0]+maxn*maxn,INF);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		length[a][b]=c;
		length[b][a]=c;
	}
	Dijkstra(c1);
	cout<<num[c2]<<" "<<w[c2];
	return 0;
} 
