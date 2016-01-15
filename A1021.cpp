#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 10010;
int father[maxn];
int G[maxn][maxn]={0};//0表示不连通
vector<int> g[maxn];//用矩阵的话，测试点3会超时
bool vis[maxn]={false};
int n;
int findfather(int x){
    while(x != father[x])
     x=father[x];
    return x;
}
bool cmp(int a,int b){
    return a>b;
}
void Union(int a,int b){
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa != fb)
     father[fa]=fb;
}
int num[maxn]={0};//num[i]=x;表示以i为根节点出发的深度为x
int MAX_level=-1;

void DFS(int now,int level){
    vis[now]=true;
    if(level>MAX_level)
      MAX_level=level;
    for(int i=0;i<g[now].size();i++){
        if(!vis[g[now][i]])
            DFS(g[now][i],level+1);
    }
}


int main(){

    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      father[i]=i;
    int a,b;
    for(int i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        Union(a,b);
        //G[a][b]=G[b][a]=1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int count=0;//¼¯ºÏ¸öÊý
    for(int i=1;i<=n;i++){
        if(father[i]==i)
          count++;
    }
    if(count>=2){
        printf("Error: %d components",count);
        return 0;
    }
    for(int i=1;i<=n;i++){//每个节点都作为根节点试试
        fill(vis,vis+maxn,false);
        MAX_level=-1;
        DFS(i,1);
        num[i]=MAX_level;
    }
    MAX_level=-1;
    for(int i=1;i<=n;i++){
        if(num[i]>MAX_level)
         MAX_level=num[i];
    }
    int len=0;
    int ans[maxn]={0};
    for(int i=1;i<=n;i++){
        if(num[i]==MAX_level)
          ans[len++]=i;
    }
    sort(ans,ans+len);
    for(int i=0;i<len;i++)
      if(i<len-1) printf("%d\n",ans[i]);
      else printf("%d",ans[i]);
    return 0;
}
/*
5
1 3
1 4
2 5
3 4
*/
