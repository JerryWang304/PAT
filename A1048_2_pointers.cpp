#include<cstdio>
#include<algorithm>
using namespace std;
int n,p;
const int maxn=100100;
int a[maxn];
int main(){
	scanf("%d%d",&n,&p);
	int i,j=0;
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,a+n);
	i=0;
	j=n-1;
	while(i<j){
		if(a[i]+a[j]==p){
			printf("%d %d",a[i],a[j]);
			return 0;
		}else if(a[i] + a[j] < p){
			i++;
		}else{
			j--;
		}
	}
	printf("No Solution");
	return 0;
}
