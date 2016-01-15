#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 10010;
int a[maxn];

bool isPrime(int x){
	if(x<=1) return false;
	int temp=sqrt(1.0*x);
	for(int i=2;i<=temp;i++)
	  if(x % i == 0)
	    return false;
	return true;
}


int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("1=1");
		return 0;
	}
	printf("%d=",n);
	int first_i=n;
	int MAX;
	if(isPrime(n)) 
	  MAX = n;
	else 
	  MAX=sqrt(n);//定义MAX是讨巧的办法，居然通过了。直接控制循环在sqrt(n)内是不行的，比如7=7,13=13 
	//事实上，如果n有大于sqrt(n)的质因子，那么这个质因子一定是n本身,因为n能整出它嘛。 
	for(int i=2;i <= MAX;i++){
	  if(isPrime(i) && n % i ==0){
		int count = 0;
		int temp=i;
		while(n%temp==0){
			if(temp<first_i){
				first_i=temp;
			}
			count++;
			temp=temp*i;
		}
		if(i==first_i){
			if(count>=2){
				printf("%d^%d",i,count);
			}else{
				printf("%d",i);
			}
		}else{
			if(count>=2){
				printf("*%d^%d",i,count);
			}else{
				printf("*%d",i);
			}			
		}
		}
	}
	return 0;
}

