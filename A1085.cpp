#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn = 100010;

int a[maxn];
int n,p;

//int length(int i,int j){
//	long long temp=a[i]*p;
//	if(temp >= a[j]){
//		return j-i+1;
//	}else if(j>=i){
//		return max(length(i+1,j),length(i,j-1));
//	}else{
//		return 1;
//	}
//}

//从a[i+1],a[i+2],,,a[n-1]中找到满足a[index] <= a[i] * p的最大下标index
//用二分法 
int len(int i,long long x){//x==a[i]*p
	int left=i+1;
	int right=n-1;
	if(a[n-1] <= x) return n-1;
	while(left<right){
		int mid=(left+right)/2;
		if(a[mid] > x){
			right=mid;
		}else{
			left = mid+1;
		}
	} 
	return left-1;
}


int main(){
	scanf("%d %d",&n,&p);
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	sort(a,a+n);
	int now_len=0;
	int ans=1;
	long long x=0;
	for(int i=0;i<n;i++){
		x=a[i] * p;
		now_len=len(i+1,x)-i+1;
		ans=max(ans,now_len);
		
	}
	printf("%d",ans);
	return 0;
}
