#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int capacity;//�������� 
int max_d;//�����յ�ľ��� 
int avg;//ÿ��λ����������ܶ��پ��� 
int n;//����վ�ĸ��� 
const int maxn=1200;
struct node{
	double price;
	double d;//�����ݵľ��� 
	int id; 
}Node[maxn];

bool cmp(node a,node b){
	return a.d < b.d;
}

int main(){
	cin>>capacity;
	cin>>max_d;
	cin>>avg;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].price;
		cin>>Node[i].d;
		Node[i].id=i;
	}
	Node[n].price=0;
	Node[n].d=max_d;
	sort(Node,Node+n,cmp);
	double exp=0; //���� 
//	for(int i=0;i<n;i++)
//	  cout<<Node[i].id<<" "<<Node[i].price<<" "<<Node[i].d<<endl;
	//������û�м���վ��ֱ���˳� 
	if(Node[0].d > 0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int index_now=0;//��ǰ��˵ļ���վ
	int max_move=capacity*avg;//���������ܵ�������
	double nowtank=0;//��ǰ������
	while(index_now < n){
		int u=-1;
		double min_price=10000000;
		for(int i=index_now+1;i<=n && Node[i].d-Node[index_now].d <= max_move;i++){
			//�ҵ��ͼ���͵ļ���վ
			if(Node[i].price < min_price){
				u=i;
				min_price = Node[i].price;
				if(Node[i].price < Node[index_now].price)
				  break;//�ҵ���һ���۸�С�ڵ�ǰ�۸�ļ���վ��ֱ���˳� 
			} 
		
		}
		if(u==-1) break;
		double need = (Node[u].d-Node[index_now].d) / avg;//������һ������վ��Ҫ������
		if(Node[u].price <= Node[index_now].price ){//��һ������վ�ļ۸���� 
			//���ܹ�������һ������վ����
//			double add=need- nowtank;
//			exp+=add*Node[index_now].price; 
//			nowtank = 0;//�������վ������������ 
            if(nowtank<need){
               double add = need-nowtank;
			   exp+=add*Node[index_now].price;
			   nowtank=0;	
			}else{
				nowtank-=(need);
			}
		}else{
			//��ǰ�ļ���վ�ļ۸����,�������
			double add = capacity-nowtank;
			exp+=add*Node[index_now].price;
			nowtank=capacity-need; 
		}
		index_now=u;
	} 
	if(index_now==n)
	  printf("%.2lf",exp);
	else
	  printf("The maximum travel distance = %.2lf",Node[index_now].d+max_move);
	return 0;
}






