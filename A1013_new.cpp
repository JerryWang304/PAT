#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1200;
vector<int> g[maxn];
int n,m,k;
bool vis[maxn]={false};
int current;
void DFS(int s){
	
	if(s==current) return;
	vis[s]=true;
	for(int i=0;i<g[s].size();i++)
	   if(!vis[g[s][i]])
	     DFS(g[s][i]);
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//printf("%d\n",g[2].size());
	int num[maxn]={0};
	for(int i=0;i<k;i++){
		scanf("%d",&current);
		fill(vis,vis+maxn,false);
		for(int j=1;j<=n;j++){
			if(j != current && vis[j]==false){
				DFS(j);
				num[i]++;
			}	
		}
	}
	for(int i=0;i<k;i++)
	 printf("%d\n",num[i]-1);
	return 0;
}
