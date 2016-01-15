
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

bool hash[maxn]={false};
int main(){
	int size;
	int n;
	scanf("%d%d",&size,&n);
	while(!isPrime(size))
	  size++;
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int index=a[i]%size;
		if(hash[index] == false){
			hash[index]=true;
			if(i==0)
			  printf("%d",index);
			else
			  printf(" %d",index);
		}else{//平方探查法
		    int step;
			for(step=1;step<=size-1;step++){
				index=(a[i]+step*step)%size;
				if(hash[index]==false){
					hash[index]=true;
					printf(" %d",index);
					break;
				}
			} 
			if(step>size-1){
				printf(" -");
			}
			
		}
	}
	
}
/*
Sample Input:
4 4
10 6 4 15
Sample Output:
0 1 4 -
*/
