#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node{
	int data;
	struct node* next;
}Node;

void show(Node *head){
	if(head == NULL)
	  cout<<"空!";
	else{
		Node *p = head;
		while(p!=NULL){
			cout<<p->data<<" ";
			p=p->next;
		}
	}
	cout<<endl;
} 


void insert(Node* &head,int x){
	
	Node* t = new Node;
	t->data = x;
	
	if(head == NULL){
		head = new Node;
		head->data = x;
		head->next = NULL;
       
	}else{
		t->next = head->next;
		head->next = t;
	}
}
//删除值为x的结点 (非递归写法)
void Delete(Node* &head,int x){
	
	Node* p =head->next,*q=head;
	while(p!=NULL){
		if(p->data == x){
			Node *t = p;
			q->next = p->next;
			p=p->next;
			delete t;
		}
		q=p;
		p=p->next;
	}
	
}
//递归写法（不对） 
void Delete2(Node* &prior,Node* &now,int x){
	if(now == NULL)
	   return;
	if(now->data == x){
		Node *t = now;
		now = t->next;
		prior->next = now;
		delete t;
	}else{
		Delete2(now,now->next,x);
	}
} 

int main(){
	Node* head=NULL;
	insert(head,-1);
	for(int i=1;i<20;i++){
		int now = rand()%10;
		insert(head,now);
	}
	insert(head,3);
	show(head->next);
	Delete2(head,head->next,7);
	//Delete(head,7);
	show(head->next);
}
