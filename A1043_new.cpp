#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node* rchild;
    node* lchild;
};

void insert(node* &root,int x){
    if(root==NULL){
        root = new node;//之前写成node* root = new node，错了。。。
        root->lchild = NULL;
        root->rchild = NULL;
        root->data = x;

    }else if(x>=root->data){
         insert(root->rchild,x);
    }
    else{
        insert(root->lchild,x);
    }
}
vector<int> pre;
void preOrder(node* root){
    if(root==NULL)
     return;
    pre.push_back(root->data);
    preOrder(root->lchild);
    preOrder(root->rchild);
}
vector<int> pre_Mirror;
void preOrderMirror(node* root){
    if(root==NULL) return;
    pre_Mirror.push_back(root->data);
    preOrderMirror(root->rchild);
    preOrderMirror(root->lchild);
}
vector<int> post;
void postOrder(node* root){
    if(root==NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post.push_back(root->data);
}
vector<int> postMirror;
void postOrderMirror(node* root){
    if(root==NULL) return;
    postOrderMirror(root->rchild);

    postOrderMirror(root->lchild);

    postMirror.push_back(root->data);
}
const int maxn  = 2000;
int a[maxn],n;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>a[i];
    node *root = new node;
    root->data=a[0];
    root->lchild=NULL;
    root->rchild=NULL;
    for(int i=1;i<n;i++){
        insert(root,a[i]);
    }
    preOrder(root);
    preOrderMirror(root);
    postOrder(root);
    postOrderMirror(root);
    bool AisPre=true;
    for(int i=0;i<n;i++)
      if(a[i]!=pre[i]){
          AisPre = false;
          break;
      }
    if(AisPre){
        cout<<"YES"<<endl;
        for(int i=0;i<post.size();i++){
            if(i==0) cout<<post[i];
            else cout<<" "<<post[i];
        }
        return 0;
    }
    bool AisPreMirror = true;
    for(int i=0;i<n;i++){
        if(a[i]!=pre_Mirror[i]){
            AisPreMirror=false;
            break;
        }
    }
    if(AisPreMirror){
        cout<<"YES"<<endl;
        for(int i=0;i<postMirror.size();i++){
            if(i==0) cout<<postMirror[i];
            else cout<<" "<<postMirror[i];
        }
        return 0;
    }
    if(!AisPre && !AisPreMirror)
      cout<<"NO";
    return 0;
}
