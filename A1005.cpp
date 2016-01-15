#include<iostream>
#include<string>
#include<sstream>
using namespace std;

char str[10][8]={"zero","one","two","three","four","five","six","seven","eight","nine"};
string num;
int sum=0;

int main(){
	cin>>num;
	for(int i=0;i<num.length();i++){
		sum+=num[i]-'0';
	}
	//cout<<sum;
	int length=0;
	int temp=sum;
	if(temp==0) 
	  length=1;
	else while(temp){
		length++;
		temp=temp/10;
	}
	
	stringstream ss;
	ss<<sum;
	string b;
	ss>>b;
	
	//cout<<endl<<length;
	for(int i=0;i<length;i++){
		if(i==0)
		  cout<<str[b[i]-'0'];
		else
		  cout<<" "<<str[b[i]-'0'];
	}
	return 0;
}

