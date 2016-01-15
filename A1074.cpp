//����Ŀ֮ǰ�����ˡ��ڶ��������о������Ѱ�����˼�����׶���������д���������� 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100100;
struct node{
	int add;
	int data;
	int next;
	int order;//�������� 
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
	//n������
	for(int i=0;i<n;i++){
		int address,data,next;
		cin>>address>>data>>next;
		Node[address].add = address;
		Node[address].data = data;
		Node[address].next = next; 
	} 
	int count=0;//��¼��Ч�ڵ�ĸ���
	int p=head;
	while(p != -1){
		count++;
		Node[p].order=count;
		p=Node[p].next;
	} 
	//cout<<"count="<<count<<endl;
	sort(Node,Node+maxn,cmp);//��count����Ч�ڵ��Ƶ�������ǰ���֣������Ͳ�����ɢ���� 
	//ǰcount���ڵ�����Ч�ڵ�
	//������Էֳ������� 
	if(count%k == 0){
		int group=count/k;//����
		for(int i=0;i<group;i++){
			//ÿ������k��Ԫ�ش���ת
			int j;
			for(j=(i+1)*k-1;j>k*i;j--){
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[j-1].add<<endl;
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[j-1].add);
			} 
			//ÿ�����һ��Ԫ�ص�������
			//ÿ�����һ��Ԫ�ص���һ��Ԫ������һ�飨��δ��ת�������һ��Ԫ��
			if(i != group-1)//����������һ�� 
			  //cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[(i+2)*k-1].add<<endl; 
			  printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[(i+2)*k-1].add);
			else
			  //cout<<Node[j].add<<" "<<Node[j].data<<" "<<-1<<endl;
			  printf("%05d %d %d\n",Node[j].add,Node[j].data,-1);
		} 
	}else{//���ֳܷ������飬
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
				//cout<<Node[j].add<<" "<<Node[j].data<<" "<<Node[(i+1)*k-1+1].add<<endl;//��һ��Ԫ��Ϊ�������һ��Ԫ�ص���һ��Ԫ�� 
				printf("%05d %d %05d\n",Node[j].add,Node[j].data,Node[(i+1)*k].add);
				//���ʣ��Ԫ��
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
