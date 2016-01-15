#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000;
const int INF=100000000;
int n,m,c1,c2;
int length[maxn][maxn];//g[x][y],x��y֮��ĳ��� 
int weight[maxn];//res[i]������i�ļ��ȶӵĸ��� 
int d[maxn];//d[i]��ʾs->i��̾��룬s��ʾ���
int w[maxn];//w[i]��ʾs->i����Ȩ��sΪ���
int num[maxn];//num[s]��ʾ��s�������յ����̾�������
bool vis[maxn]={false};//�����Ƿ��ѱ����� 

void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	//vis[s]=true;�������ֻ�ܹ�һ�����Ե�orz 
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
