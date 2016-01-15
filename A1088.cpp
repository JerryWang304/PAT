#include<cstdio>
#include<cmath>
using namespace std;
struct node{
	long long a;
	long long b;
}x,y;

long long gcd(long long x,long long y){
	if(y==0)
	 return x;
	else
	 return gcd(y,x%y);
}

node add(node x,node y){
	long long m=x.a*y.b + x.b*y.a;
	long long n=x.b*y.b;
	long long g=1;
	if(m != 0)
	 g=gcd(abs(m),abs(n));
	node temp;
	temp.a=m/g;
	temp.b=n/g;
	return temp;
}

node minus(node x,node y){
	long long m=x.a*y.b-y.a*x.b;
	long long n=x.b*y.b;
	long long g=1;
	if(m != 0)
	 g=gcd(abs(m),abs(n));
	node temp;
	temp.a=m/g;
	temp.b=n/g;
	return temp;
}
node multiply(node x,node y){
	long long m=x.a*y.a;
	long long n=x.b*y.b;
	long long g=1;
	if(m != 0)
	 g=gcd(abs(m),abs(n));
	node temp;
	temp.a=m/g;
	temp.b=n/g;
	return temp;
}
node divided(node x,node y){
	long long m=x.a*y.b;
	long long n=x.b*y.a;
	long long g=1;
	if(m != 0)
	 g=gcd(abs(m),abs(n));
	node temp;
	temp.a=m/g;
	temp.b=n/g;
	return temp;
}

void show(node x){
	if(x.b<0){
		x.a=-x.a;
		x.b=-x.b;
	} 
	if(x.a<0)
	 printf("(");
	if(x.a==0){
		printf("0");
	}
	//整数 
	else if(x.a%x.b==0){
		printf("%lld",x.a/x.b);
	}else if(x.a < 0 && abs(x.a) > x.b){//假分数
	    printf("%lld %lld/%lld",x.a/x.b,-x.a%x.b,x.b); 
	}else if(x.a > 0 && x.a > x.b){//假分数 
		printf("%lld %lld/%lld",x.a/x.b,x.a%x.b,x.b); 
	}else{//真分数 
		printf("%lld/%lld",x.a,x.b);
	}
	if(x.a<0)
	 printf(")");
}
int main(){
	scanf("%lld/%lld",&x.a,&x.b);
	scanf("%lld/%lld",&y.a,&y.b);
	//加法
	node add_node=add(x,y);
	show(x);
	printf(" + ");
	show(y);
	printf(" = ");
	show(add_node);
	printf("\n");
	//减法 
	node minus_node=minus(x,y);
	show(x);
	printf(" - ");
	show(y);
	printf(" = ");
	show(minus_node);
	printf("\n");
	//乘法
	node mul_node=multiply(x,y);
	show(x);
	printf(" * ");
	show(y);
	printf(" = ");
	show(mul_node);
	printf("\n"); 
	//除法
	node div_node=divided(x,y);
	show(x);
	printf(" / ");
	show(y);
	printf(" = ");
	if(div_node.b==0)
	  printf("Inf");
	else
	  show(div_node);
	return 0;
}

/*

Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/
