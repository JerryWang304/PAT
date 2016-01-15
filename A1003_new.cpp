#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 1020;
const int INF=100000000;
int G[maxn][maxn];
int weight[maxn];

int d[maxn];
int num[maxn]={0};
int w[maxn]={0};
bool vis[maxn]={false};
int n,m;

void Dijkstra(int s){
	
	fill(d,d+maxn,INF);
	d[s]=0;
	num[s]=1;
	w[s]=weight[s]; 
	
	
	for(int i=0;i<n;i++){
		
		int u=-1,min=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false && d[j]<min){
				u=j;
				min=d[j];
			}
			
		}
		
		if(u==-1) return ;
		
		vis[u]=true;
		
		for(int z=0;z<n;z++){
			if(vis[z]==false && G[u][z] != INF){
				if(G[u][z]+d[u] < d[z]){
					d[z]=G[u][z]+d[u];
					w[z]=w[u]+weight[z];
					num[z]=num[u];
				}else if(G[u][z]+d[u] == d[z]){
					num[z]+=num[u];
					if(w[u]+weight[z] > w[z])
					 w[z]=w[u]+weight[z];
				}
			}
		}
			
	}
}
	int main(){
		int c1,c2;
		cin>>n>>m>>c1>>c2;
		fill(G[0],G[0]+maxn*maxn,INF);
		for(int i=0;i<n;i++)
		 cin>>weight[i];
		for(int i=0;i<m;i++){
			int a,b,c;
			cin>>a>>b>>c;
			G[a][b]=c;
			G[b][a]=c;
		}
		Dijkstra(c1);
		cout<<num[c2]<<" "<<w[c2];
		return 0;
	}
	

