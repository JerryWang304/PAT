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
	  MAX=sqrt(n);//����MAX�����ɵİ취����Ȼͨ���ˡ�ֱ�ӿ���ѭ����sqrt(n)���ǲ��еģ�����7=7,13=13 
	//��ʵ�ϣ����n�д���sqrt(n)�������ӣ���ô���������һ����n����,��Ϊn��������� 
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

