#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


const int maxn = 4000;
int n,m,ans;
struct node{
    int w;
    vector<int> child;
}Node[maxn];
bool cmp(int a,int b){
     return Node[a].w > Node[b].w;
}

int sum=0;
int path[maxn]={0};//maxn设置太小会出现段错误
void DFS(int s,int level,int sum){
    if(sum>ans) return ;
    if(sum==ans && Node[s].child.size()==0){
        for(int j=0;j<level;j++){
            if(j==0) printf("%d",Node[path[j]].w);
            else printf(" %d",Node[path[j]].w);
        }
         printf("\n");
    }
    if(sum<ans){
        for(int i=0;i<Node[s].child.size();i++){
            path[level]=Node[s].child[i];
            int chi=Node[s].child[i];
            DFS(chi,level+1,sum+Node[chi].w);
        }
    }

}

int main(){
    scanf("%d%d%d",&n,&m,&ans);
    for(int i=0;i<n;i++)
      scanf("%d",&Node[i].w);
    for(int i=0;i<m;i++){
        int id,k;
        scanf("%d%d",&id,&k);
        for(int j=0;j<k;j++){
            int temp;
            scanf("%d",&temp);
            Node[id].child.push_back(temp);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);//将权重从大到小排序
    }
    DFS(0,1,Node[0].w);
    return 0;
}

