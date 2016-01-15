#include<iostream>
#include<queue>
using namespace std;

typedef struct node
{
    int data;
    node* lChild;
    node* rChild;
}Node;

const int num=50;

int pre[num],post[num],in[num],n;
//根据后序序列[postL,postR]和中序序列[inL,inR]构造二叉树
Node* create(int postL,int postR,int inL,int inR)
{
    if(postL > postR)
     return NULL;

    Node *root=new Node;
    root->data=post[postR];
    int i;
    for(i=inL;i<=inR;i++)
      if(in[i] == post[postR])
       break;


    root->lChild=create(postL,postL+i-inL-1,inL,i-1);
    root->rChild=create(postL+i-inL,postR-1,i+1,inR);

    return root;
}

//根据先序遍历[preL,preR]和中序[inL,inR]遍历
Node* create2(int preL,int preR,int inL,int inR)
{
    if(preL > preR)
     return NULL;
    int i;
    for(i=inL;i<=inR;i++)
     if(pre[preL] == in[i])
      break;
    int nrofLeft=i-inL;
    Node *root=new Node;
    root->data=pre[preL];
    root->lChild=create2(preL+1,preL+nrofLeft,inL,inL+i-1);
    root->rChild=create2(preL+nrofLeft+1,preR,inL+i+1,inR);
    return root;
}

//层序遍历
int count=0;
void BFS(Node *root)
{
    queue<node*> q;
    while(!q.empty())
     q.pop();

    q.push(root);
    while(!q.empty())
    {
        Node* ThisNode=new Node;
        ThisNode=q.front();
        count++;
        q.pop();
        cout<<ThisNode->data;
        if(count<n) cout<<" ";
        if(ThisNode->lChild) q.push(ThisNode->lChild);
        if(ThisNode->rChild) q.push(ThisNode->rChild);
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>post[i];
    for(int i=0;i<n;i++)
      cin>>in[i];
    Node *root=create(0,n-1,0,n-1);
    BFS(root);
    return 0;
}
