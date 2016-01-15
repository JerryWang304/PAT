#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100100;
struct node{
	int add;
	int data;
	int next;
	bool flag;
}Node[maxn];

bool cmp(node a,node b){
	if(a.flag==false || b.flag==false){
		return a.flag > b.flag;
	}else
	    return a.data < b.data;
}

int main(){
	int n,head;
	scanf("%d %d",&n,&head);
	for(int i=0;i<n;i++){
		int address,data,next;
		scanf("%d%d%d",&address,&data,&next);
		Node[address].add=address;
		Node[address].data=data;
		Node[address].next=next;
	}
	int p=head;
	int count=0;
	while(p!=-1){
		Node[p].flag=true;
		count++;
		p=Node[p].next;
	}
	sort(Node,Node+maxn,cmp);
	for(int i=0;i<count-1;i++){
		Node[i].next=Node[i+1].add;
	}
	Node[count-1].next=-1;
	if(count==0){//最后一个测试点的坑 
		printf("0 -1");
		return 0;
	}
	if(Node[0].add != -1)
	  printf("%d %05d\n",count,Node[0].add);
	else
	  printf("%d -1\n",count);
	for(int i=0;i<count;i++){
		if(i!=count-1)
		  printf("%05d %d %05d\n",Node[i].add,Node[i].data,Node[i].next);
		else
		  printf("%05d %d -1",Node[i].add,Node[i].data);
	}
	return 0;
}
