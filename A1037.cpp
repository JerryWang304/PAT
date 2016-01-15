//超时 
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 100002;
int a[maxn],b[maxn];
int na,nb;

bool vis_b[maxn]={false};//是否被访问过 

bool cmp(int x,int y){
	return x>y;
}

int main(){
	//ios::sync_with_stdio(false);
	//cin>>na;
	scanf("%d",&na);
	for(int i=0;i<na;i++)
	  scanf("%d",&a[i]);
	
	//cin>>nb;
	scanf("%d",&nb);
	for(int i=0;i<nb;i++)
	  scanf("%d",&b[i]);
   
    sort(a,a+na,cmp); 
    sort(b,b+nb,cmp);
    int sum=0;//最大的和
	for(int i=0;i<na;i++){
		int max=-1000000000;
		int u=-1;
		for(int j=0;j<nb;j++){
			if(vis_b[j] == false){//这个数没有被用过
			   if(b[j] * a[i] > max && b[j] * a[i] > 0){
			       max=b[j]*a[i];
				   u=j;
			   }
			   if(b[j]*a[i] < 0)
			     break;
				
			}

		}
		if(u != -1){
			vis_b[u]=true;
		}
		if(max>0) sum+=max;
	} 
	printf("%d",sum);
	return 0;
	
}
