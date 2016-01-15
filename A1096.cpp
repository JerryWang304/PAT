#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;
bool isP(int x){
    int mid = sqrt(1.0*x);
    if(x<=1) return false;
    for(int i=2;i<=mid;i++)
      if(x%i==0)
       return false;
    return true;
}
int main(){
	int n;
	scanf("%d",&n);
	if(isP(n)){
	    printf("1\n");
	    printf("%d",n);
	    return 0;
	}
	int mid=sqrt(1.0*n);
	int MAX=-1;
	int MIN=100000000;
	int u=-1;
	for(int i=2;i<=mid;i++){
		int count=0;
		int j=i;
		while(n%j==0){
			j++;
			count++;
		}
		if(count>MAX){
		    MAX=count;
		    u=i;
		}

	}
	printf("%d\n",MAX);
	for(int i=0;i<MAX;i++){
	    if(i==0) printf("%d",u++);
	    else printf("*%d",u++);
	}
	return 0;
}
