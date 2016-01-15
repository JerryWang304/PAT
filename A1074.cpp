//这题目之前做过了。第二次做，感觉还是难啊。意思很容易懂，但就是写不出代码来 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100100;
struct node{
	int add;
	int data;
	int next;
	int order;//用来排序 
}Node[maxn];

bool cmp(node a,node b){
	if(a.order == 0 || b.order == 0){
		return a.order > b.order;
	}else
	  return a.order < b.order;
}

int main(){
	
	int head,n,k;
	cin>>head>>n>>k;
	//n行数据
	for(int i=0;i<n;i++){
		int address,data,next;
		cin>>address>>data>>next;
		Node[address].add = address;
		Node[address].data = data;
		Node[address].next = next; 
	} 
	int count=0;//记录有效节点的个数
	int p=head;
	while(p != -1){
		count++;
		Node[p].order=count;
		p=Node[p].next;
	} 
	//cout<<"count="<<count<<endl;
	sort(Node,Node+maxn,cmp);//把count个有效节点移到数组最前部分，这样就不是离散的了 
	//前count个节点是有效节点
	//如果可以分成整数块 
	if(count%k == 0){
		int group=count/k;//组数
		for(int i=0;i<group;i++){
			//每组内有k个元素待翻转
			int j;
			for(j=(i+1)*k-1;j>k*i;j--){
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[j-1].add<<endl;
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[j-1].add);
			} 
			//每组最后一个元素单独考虑
			//每组最后一个元素的下一个元素是下一组（还未翻转）的最后一个元素
			if(i != group-1)//如果不是最后一组 
			  //cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[(i+2)*k-1].add<<endl; 
			  printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[(i+2)*k-1].add);
			else
			  //cout<<Node[j].add<<" "<<Node[j].data<<" "<<-1<<endl;
			  printf("%05d %d %d\n",Node[j].add,Node[j].data,-1);
		} 
	}else{//不能分成整数块，
	    int group = count/k;
		for(int i=0;i<group;i++){
			int j;
			for(j=(i+1)*k-1;j>k*i;j--){
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[j-1].add<<endl; 
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[j-1].add);
			}
			if(i != group-1){
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[(i+2)*k-1].add<<endl; 
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[(i+2)*k-1].add);
			}else{
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[(i+1)*k-1+1].add<<endl;//下一个元素为本组最后一个元素的下一个元素 
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[(i+1)*k].add);
				//输出剩余元素
				for(int z=(i+1)*k;z<=count-1;z++)
				  //cout<<Node[z].add<<" "<<Node[z].data<<" "<<Node[z].next<<endl; 
				  if(Node[z].next != -1)
				    printf("%05d %d %05d\n",Node[z].add,Node[z].data,Node[z].next);
				  else
				    printf("%05d %d %d\n",Node[z].add,Node[z].data,-1);
			}
		} 
		
	}
	return 0;
}
