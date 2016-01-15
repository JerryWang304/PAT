#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

struct node{

    int data;
    node *lchild,*rchild;
};
const int maxn = 38;
int pre[maxn],in[maxn],n;
int len_pre=0,len_in=0;
stack<int> s;
char str[5];

node* creat(int preL,int preR,int inL,int inR){
   if(preR<preL)
     return NULL;
   node *root = new node;
   root->data = pre[preL];
   int k=-1;
   for(k=inL;k<=inR;k++)
     if(in[k] == pre[preL])
       break;
   int num = k-inL;
   root->lchild = creat(preL+1,preL+num,inL,k-1);
   root->rchild = creat(preL+num+1,preR,k+1,inR);
   return root;
}
int x=0;
void post(node* root){
   if(root != NULL){
       post(root->lchild);
       post(root->rchild);
       printf("%d",root->data);
       x++;
       if(x<n)
         printf(" ");
   }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<2*n;i++){
        scanf("%s",str);
        if(strcmp(str,"Push") == 0){
            int temp;
            scanf("%d",&temp);
            s.push(temp);
            pre[len_pre++]=temp;
        }else{
            in[len_in++]=s.top();
            s.pop();
        }

    }
    node *root=creat(0,n-1,0,n-1);
    post(root);
    return 0;
}
