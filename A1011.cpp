#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=100100;
double Max[maxn];
char m[maxn];
int main(){
	
	char c1,c2,c3;
	double game[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		 cin>>game[i][j];
		 if(game[i][j]>Max[i]){
		 	Max[i]=game[i][j];
		 	if(j==0) m[i]='W';
		 	else if(j==1) m[i]='T';
		 	else if(j==2) m[i]='L';
		 }
	    }
		
	}

    for(int i=0;i<3;i++)
     cout<<m[i]<<" ";
    double a=1.0;
    for(int i=0;i<3;i++)
    a=a*Max[i];
    a=a*0.65*2-2;
    int b=(int)(a*100)%10;
    if(b>=5)
     a=a+0.01;
    printf("%.2lf",a);
	return 0;
	
} 
