#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 110;
struct node{
	long long  a;
	long long  b;
}Node[maxn];
long long gcd(long long a,long long b){
	if(b==0)
	 return a;
	else
	 return gcd(b,a%b);
}

node add(node m,node n){
	long long x=m.a*n.b+n.a*m.b;
	long long y=m.b*n.b;
	long long g=gcd(x,y);
	node temp;
	temp.a=x/g;
	temp.b=y/g;
	return temp;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
	  scanf("%lld/%lld",&Node[i].a,&Node[i].b);
    }
    node sum;
    sum.a=0;
    sum.b=1;
	for(int i=0;i<n;i++){
	  sum=add(sum,Node[i]);
	  //printf("%lld/%lld\n",sum.a,sum.b);
    } 
	if(sum.a==0){
		printf("0");
	}else if(sum.a % sum.b == 0){
		printf("%lld",sum.a/sum.b);
	}else if(sum.a > sum.b){
		printf("%lld ",sum.a/sum.b);
		printf("%lld/%lld",sum.a%sum.b,sum.b);
	}else{
		printf("%lld/%lld",sum.a,sum.b);
	}
	printf("\n%lld",gcd(-10,5));
	return 0;
}

/*
5
2/5 4/15 1/30 -2/60 8/3
*/
