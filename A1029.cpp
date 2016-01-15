#include<cstdio>
const int maxn = 1000010;
int a[maxn],b[maxn],c[maxn];
int count=0;
int main(){
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	int m;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	  scanf("%d",&b[i]);
	
	i=0;j=0;
	while(i<n && j<m){
		if(a[i]<=b[j]){
			c[count++]=a[i];
			i++;
		}else{
			c[count++]=b[j];
			j++;
		}
	}
	while(i<n) c[count++]=a[i++];
	while(j<m) c[count++]=b[j++];
	if(count%2==1) printf("%d",c[count/2]);
	else printf("%d",c[count/2-1]);
	return 0;
	
}
