#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1010;

struct mouse{
	int weight;
	int rank;
}Mouse[maxn];

queue<int> q;//队列里面存放的是编号顺序 

int main(){
	int np,ng;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++)
	  scanf("%d",&Mouse[i].weight);
	int order;
	for(int i=0;i<np;i++){
		scanf("%d",&order);
		q.push(order);//将顺序插入队列 
	}
	int nrofWinner;
	while(q.size() != 1){
		int size=q.size();
		if(size % ng == 0)
		  nrofWinner = size/ng;
		else
		  nrofWinner = size/ng+1;
		
		for(int i=0;i<nrofWinner;i++){
			int k=q.front();
			for(int j=0;j<ng;j++){
				if(i*ng+j>=size) break;
				int front = q.front();
				if(Mouse[front].weight>Mouse[k].weight){
					k=front;
				} 
				Mouse[front].rank=nrofWinner+1;
				q.pop();
			}
			q.push(k);
		}
		
	}
	Mouse[q.front()].rank=1;
	for(int i=0;i<np;i++)
	 if(i==0) printf("%d",Mouse[i].rank);
	 else printf(" %d",Mouse[i].rank);
	
	return 0;
} 
