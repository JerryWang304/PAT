//超时 
#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100100;
int ans[maxn]={0};//记录i,j ans[i]=j表示i,j满足条件 
int a[maxn];

bool flag=false;//是否有解
int sum[maxn]={0};
int Min=100000000; 
int temp_m=0;
void find(int n,int m){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int SUM=sum[j]-sum[i-1];
			if(SUM == m){
				flag=true;
				ans[i]=j;
				//cout<<"i="<<i<<"  j="<<j<<endl;
			}
			else if(SUM > m){
				temp_m=SUM;
				break;
			}
		}
	} 
}


int main(){
	int n; 
    int m;//钱 
	//cin>>n>>m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
	  scanf("%d",&a[i]);
	  int temp=0;
	  for(int j=i;j>=1;j--)
	    temp+=a[j];
	  sum[i]=temp;
	}

	
    while(flag==false){
    	find(n,m);
    	m=temp_m;
    }
	if(flag==true){
		for(int i=1;i<=n;i++)
		  	if(ans[i] != 0)
		  	  //cout<<i<<"-"<<ans[i]<<endl;
		  	  printf("%d-%d\n",i,ans[i]);
	}
	return 0;
}
