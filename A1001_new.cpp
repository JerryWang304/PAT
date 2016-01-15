//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int main(){
//	
//	int a,b;
//	scanf("%d%d",&a,&b);
//	int c=a+b;
//	if(c<0){
//		printf("-");
//		c=-c;
//	}
//	int num[10]={0},i=0;
//	if(c==0) num[i++]=0;
//	while(c){
//		num[i++]=c%10;
//		c=c/10;
//	}
//	for(int j=i-1,count=1;j>=0;j--,count++){
//		printf("%d",num[j]);
//		if(j > 0 && count%3==0)
//		printf(",");
//	}
//	return 0;
//}

#include<cstdio>
using namespace std;
int num[10];
int main(){
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;
	if(sum<0){
		printf("-");
		sum=-sum;
	}
	int len=0;
	if(sum==0)
	  num[len++]=0;
	while(sum){
		num[len++]=sum%10;
		sum/=10;
		
	}
	
	for(int k=len-1;k>=0;k--){
		printf("%d",num[k]);
		if(k>0 && k%3==0) 
		 printf(",");
	}
	return 0;
	
	
}
