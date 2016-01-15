#include<iostream>
#include<vector>
using namespace std;

typedef struct node
{
	int data;
	node *left;
	node *right;
}node;

const int N=1050;

int a[N];
//插入
void insert(node* &root,int x)
{
	if(root==NULL)
	 {
	 	root = new node;
	 	root->data=x;
	 	root->left=NULL;
	 	root->right=NULL;
	 }
	 else if(x >= root->data)
	      insert(root->right,x);
	 else insert(root->left,x);
}
//构造BST
node* create(int a[],int n)
{
	node* root = new node;
	root->data=a[0];
	root->left=NULL;
	root->right=NULL;
	for(int i=1;i<n;i++)
	 insert(root,a[i]);
	return root;
}
//先序遍历
void preOrder(node *root,vector<int> &p)
{
	if(root==NULL)
	 return;
	p.push_back(root->data);
	preOrder(root->left,p);
	preOrder(root->right,p);
}
//mirror的先序遍历
void preOrderMirror(node *root,vector<int> &p)
{
	if(root==NULL) return;
	p.push_back(root->data);
	preOrderMirror(root->right,p);
	preOrderMirror(root->left,p);
}
//mirror的后续遍历
void postOrderMirror(node *root,vector<int> &p)
{
	if(root==NULL) return;
	postOrderMirror(root->right,p);
	postOrderMirror(root->left,p);
	p.push_back(root->data);
}

//后续遍历
void postOrder(node *root,vector<int> &p)
{
	if(root==NULL)
	 return;
	postOrder(root->left,p);
	postOrder(root->right,p);
	p.push_back(root->data);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	node* root=create(a,n);
	vector<int> pre;
	preOrder(root,pre);
	vector<int> preMirror;
	preOrderMirror(root,preMirror);
	bool flag1=true,flag2=true;

	for(int i=0;i<n;i++)
	 {
	   if(a[i] != pre[i] )
	    flag1=false;

	   if(a[i] != preMirror[i] )
	    flag2=false;
     }


	if(flag1)
	{
		cout<<"YES"<<endl;
		vector<int> post;
		postOrder(root,post);
		for(int i=0;i<post.size();i++)
		{
			if(i<post.size()-1)
			 cout<<post[i]<<" ";
			else cout<<post[i];
		}

	}
	else if(flag2)
	{
		cout<<"YES"<<endl;
		vector<int> post;
		postOrderMirror(root,post);
		for(int i=0;i<post.size();i++)
		{
			if(i<post.size()-1)
			 cout<<post[i]<<" ";
			else cout<<post[i];
		}
	}

	else cout<<"NO";
	return 0;
}













