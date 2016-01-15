#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int capacity;//汽油容量 
int max_d;//到达终点的距离 
int avg;//每单位汽油最多能跑多少距离 
int n;//汽油站的个数 
const int maxn=1200;
struct node{
	double price;
	double d;//到杭州的距离 
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
	double exp=0; //花费 
//	for(int i=0;i<n;i++)
//	  cout<<Node[i].id<<" "<<Node[i].price<<" "<<Node[i].d<<endl;
	//出发点没有加油站，直接退出 
	if(Node[0].d > 0){
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	int index_now=0;//当前光顾的加油站
	int max_move=capacity*avg;//加满油能跑的最大距离
	double nowtank=0;//当前的油量
	while(index_now < n){
		int u=-1;
		double min_price=10000000;
		for(int i=index_now+1;i<=n && Node[i].d-Node[index_now].d <= max_move;i++){
			//找到油价最低的加油站
			if(Node[i].price < min_price){
				u=i;
				min_price = Node[i].price;
				if(Node[i].price < Node[index_now].price)
				  break;//找到第一个价格小于当前价格的加油站则直接退出 
			} 
		
		}
		if(u==-1) break;
		double need = (Node[u].d-Node[index_now].d) / avg;//到达下一个加油站需要的油量
		if(Node[u].price <= Node[index_now].price ){//下一个加油站的价格便宜 
			//加能够到达下一个加油站的油
//			double add=need- nowtank;
//			exp+=add*Node[index_now].price; 
//			nowtank = 0;//到达加油站后，正好用完油 
            if(nowtank<need){
               double add = need-nowtank;
			   exp+=add*Node[index_now].price;
			   nowtank=0;	
			}else{
				nowtank-=(need);
			}
		}else{
			//当前的加油站的价格便宜,则加满油
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






