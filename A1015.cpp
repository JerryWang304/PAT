#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;

bool isPrime(int n){
	if(n==1)
	 return false;
	else{
		int s=(int)sqrt(n*1.0);
		for(int i=2;i<=s;i++)
		  if(n % i == 0)
		    return false;
	}
	return true;
}
const int maxn=10010;
bool result[maxn];
int length=0;

int main(){
	int a,b;
	cin>>a;
	while(a>0){
		cin>>b;
		if(!isPrime(a))
		  result[length++]=false;
		else{
			//��aת��Ϊb����
				int temp[maxn]={0};//����ת����Ľ��Ƶ�ÿһλ
				int len=0;
				while(a){
					temp[len++]=a%b;
					a=a/b;
				} 
				
				int x=0;//ת��Ϊʮ���Ƶ���
				for(int i=0;i<len;i++)
				 x=x*b+temp[i];
				if(isPrime(x))
				  result[length++]=true; 
				else
				  result[length++]=false;
				
			
		}
		cin>>a;
	}
	for(int i=0;i<length;i++)
	 if(i < length-1)
	   if(result[i] )
	     cout<<"Yes"<<endl;
	   else 
	     cout<<"No"<<endl;
	 else{
	   if(result[i] )
	     cout<<"Yes";
	   else 
	     cout<<"No";
	 }
	return 0;
}

