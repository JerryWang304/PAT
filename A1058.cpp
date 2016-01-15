#include<iostream>
#include<cstdio> 
using namespace std;
int a,b,c;
int d,e,f;
int g,s,k;
int main(){
	scanf("%d.%d.%d",&a,&b,&c);
	scanf("%d.%d.%d",&d,&e,&f);
	g=a+d;
	s=b+e;
	k=c+f;
	if(k>=29){
		s+=k/29;	
		k=k%29;
	}
	if(s>=17){
		g+=s/17;
		s=s%17;		
	}
	printf("%d.%d.%d",g,s,k);
	return 0;
}
