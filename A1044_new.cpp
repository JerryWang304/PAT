#include<cstdio>
const int maxn = 100100;
int sum[maxn] = {0};

int upper_bound(int L,int R,int x){
	int left=L,right=R;
	while(left<right){
		int mid=(left+right)/2;
		if(sum[mid]>x)
		  right=mid;
		else
		  left=mid+1;
	}
	return left;
}

int main() {
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i]+=sum[i-1];
	}
	int nearM=100000000;
	for(int i=1;i<=n;i++){
		int j=upper_bound(i,n+1,sum[i-1]+m);
		if(sum[j-1]-sum[i-1] == m){
			nearM=m;
			break;
		}else if(sum[j-1]-sum[i-1]<nearM && j<=n){
			nearM=sum[j]-sum[i-1];
		}
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(i,n+1,sum[i-1]+nearM);
		if(sum[j-1]-sum[i-1] == nearM)
		  printf("%d-%d\n",i,j-1);
	}
	return 0;
}
