//问题出在进制最大可以是多少 
//18 19 7通不过 
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
const int maxn=200000;
//将base进制的s转化为10进制 
long long ten(string s,int base){
	long long temp=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9')
		  temp=temp*base+s[i]-'0';
		else if(s[i]>='a' && s[i]<='z')
		  temp=temp*base+s[i]-'a'+10;
	}
	return temp;
}

int main(){
	string n1,n2;
	long long tag,base;
	cin>>n1>>n2>>tag>>base;
	if(tag==1){
		long long x=ten(n1,base),y;
		//找到 n2里面最小的
		char min='z'+1;
		for(int i=0;i<n2.length();i++){
			if(n2[i]<min)
			 min=n2[i];
		}
		
		int base_start;
		if(min>='0'&&min<='9')
		  base_start=min-'0';
		else 
		  base_start=min-'a'+10;
		base_start++;//最小的进制 
		do{
		    y=ten(n2,base_start);
			if(x==y)
			 break;
			base_start++;
		}while(base_start<maxn);
		if(x != y)
		 cout<<"Impossible";
		else
		 cout<<base_start;
		 		 			
	}else if(tag == 2){
		long long x=ten(n2,base),y;
		//找到 n1里面最小的
		char min='z'+1;
		for(int i=0;i<n1.length();i++){
			if(n1[i]<min)
			 min=n1[i];
		}
		
		int base_start;
		if(min>='0'&&min<='9')
		  base_start=min-'0';
		else 
		  base_start=min-'a'+10;
		base_start++; 
		do{
			y=ten(n1,base_start);
			if(x==y)
			 break;
			base_start++;
		}while(base_start<maxn);
		if(x != y)
		  cout<<"Impossible";		 
		else
		 cout<<base_start;
		 
	}
	return 0;
	 
} 
