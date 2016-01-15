#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100;
struct node{
    int data;
    int height;
    node* lchild;
    node* rchild;
}*root,*null;
int n;
node* newnode(int x){
    node* t= new node;
    t->data=x;
    t->height=1;
    t->lchild = null;
    t->rchild = null;
    return t;
}

void getHeight(node *root){
    root->height= max(root->lchild->height,root->rchild->height)+1;
}

void R(node* &root){
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    getHeight(root);
    getHeight(temp);
    root=temp;
}
void L(node* &root){
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    getHeight(root);
    getHeight(temp);
    root=temp;
}
void insert(node* &root,int x){
    if(root==null){
        root=newnode(x);
        return ;
    }
    if(x<root->data){
        insert(root->lchild,x);
        getHeight(root);
        if(root->lchild->height - root->rchild->height == 2){
            //LL
            if(root->lchild->lchild->height - root->lchild->rchild->height == 1)
               R(root);
            //LR
            else if(root->lchild->lchild->height - root->lchild->rchild->height == -1){
                L(root->lchild);
                R(root);
            }
         }

    }else{
            insert(root->rchild,x);
            getHeight(root);
            if(root->lchild->height - root->rchild->height == -2){
                 //RL
              if(root->rchild->lchild->height - root->rchild->rchild->height == 1){
                 R(root->rchild);
                 L(root);
                 //RR
               }else if(root->rchild->lchild->height - root->rchild->rchild->height == -1)
                 L(root);
            }
        }
}

int main(){
    null=new node;
    null->height=0;
    root=null;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        insert(root,temp);
    }
    cout<<root->data;
    return 0;
}
