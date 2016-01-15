#include<cstdio>
#include<algorithm>
using namespace std;
int n,p;
const int maxn=100100;
int a[maxn];
bool flag=false;
int main(){
	scanf("%d%d",&n,&p);
	int i,j=0;
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,a+n);
	int index_i=0,index_j=0;
	for(i=0;i<n;i++){
	  int temp=upper_bound(a+i+1,a+n,p)-a;
	  for(j=temp;j>=i+1;j--){
	  	if(a[i]+a[j] == p){
	  		flag=true;
	  		break;
	  	}
	  }
	  if(flag) break;
	}
	 
	if(flag){
		printf("%d %d",a[i],a[j]);
	}else{
		printf("No Solution");
	}
	return 0;
}
