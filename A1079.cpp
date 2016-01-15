#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 100100;
int n;
double p,r;
struct node{
    int level;
    vector<int> child;
    int sum;
}Node[maxn];
queue<int> q;
void BFS(int s){
    q.push(s);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<Node[front].child.size();i++){
             int chi = Node[front].child[i];
             q.push(chi);
             Node[chi].level=Node[front].level+1;
        }
    }
}
double ans=0;
void DFS(int index,int depth){
    if(Node[index].child.size() == 0){
        ans+=Node[index].sum*p*pow((1+r/100),depth);
        return ;
    }
    for(int i=0;i<Node[index].child.size();i++)
      DFS(Node[index].child[i],depth+1);
}
double count(){
    double s=0;
    for(int i=0;i<n;i++){
        if(Node[i].child.size() == 0){
            int sum=Node[i].sum;
            s+=sum*p*pow((1+r/100),Node[i].level);
        }
    }
    return s;
}

int main(){

    scanf("%d%lf%lf",&n,&p,&r);
    for(int i=0;i<n;i++){
        int temp,pro;
        scanf("%d",&temp);
        if(temp==0){
            scanf("%d",&pro);
            Node[i].sum=pro;
        }else{
            for(int j=0;j<temp;j++){

                scanf("%d",&pro);
                Node[i].child.push_back(pro);
            }
        }
    }
    BFS(0);
    double sum = count();
    //printf("%.1lf",sum);
    DFS(0,0);
    printf("%.1lf",ans);
    return 0;
}
