#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
int n;
double p,r;
const int maxn = 100100;
struct node{
    vector<int> child;
    int level;
}Node[maxn];
int root;
queue<int> q;
void BFS(int s){
    q.push(s);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<Node[front].child.size();i++){
            int chi=Node[front].child[i];
            q.push(chi);
            Node[chi].level=Node[front].level+1;
        }
    }
}

int main(){
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        int now;
        scanf("%d",&now);
        if(now==-1){
            root=i;
        }else{
            Node[now].child.push_back(i);
        }
    }
    //printf("root= %d",root);
    BFS(root);
    int high_lev=-1;
    for(int i=0;i<n;i++){
        if(Node[i].level>high_lev)
          high_lev=Node[i].level;
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(Node[i].level==high_lev)
         count++;
    }
    double ans=p*pow((1+r/100),high_lev);
    printf("%.2lf %d",ans,count);
    return 0;
}
