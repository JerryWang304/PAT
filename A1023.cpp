#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 300;
int a[maxn],b[maxn],temp[maxn];
int len_a=0,len_b=0,len_temp=0;

bool isTrue(int a[],int len_a,int b[],int len_b){
	if(len_a != len_b)
	  return false;
	sort(a,a+len_a);
	sort(b,b+len_b);
	for(int i=0;i<len_a;i++)
	  if(a[i] != b[i])
	    return false;
	return true; 
}

int main(){
	string str;
	cin>>str;
	for(int i=0;i<str.length();i++)
	  a[len_a++]=str[i]-'0';
	int carry=0;
	for(int i=len_a-1;i>=0;i--){
		b[len_b++] = (carry + (2*a[i]))%10;
		carry=(carry + (2*a[i]))/10;
	}
	//最后一个进位也要考虑
	//不考虑的话，两个测试点过不去 
	if(carry>0)
	  b[len_b++]=carry;
	//b[]反转 
	for(int i=len_b-1,j=0;i>=j;i--,j++)
	  swap(b[i],b[j]);
	for(int i=0;i<len_b;i++)
	  temp[len_temp++]=b[i];
    if(isTrue(a,len_a,temp,len_temp)){
    	cout<<"Yes"<<endl;
    }else
      cout<<"No"<<endl;
   	for(int i=0;i<len_b;i++)
   	  cout<<b[i];
   	return 0;
}
