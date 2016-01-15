#include<iostream>
#include<vector> 
#include<algorithm>
using namespace std;
const int INF = 1000000000;
const int maxn = 520;
int g[maxn][maxn];

int n,m,c1,c2;
int weight[maxn];
int d[maxn];
bool vis[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		//找到距离s最近的点 
		for(int j=0;j<n;j++){
			if(!vis[j] && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return ;
		vis[u]=true;
		for(int z=0;z<n;z++){
			if(!vis[z] && g[u][z] != 0){
				if(d[u] + g[u][z] < d[z]){
					d[z] = d[u]+ g[u][z];
				}
			}
		} 
	}
}

int main(){
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
	  cin>>weight[i];
	for(int i=0;i<m;i++){
		int a,b,length;
		cin>>a>>b>>length;
		g[a][b]=length;
		g[b][a]=length;
	}
}
