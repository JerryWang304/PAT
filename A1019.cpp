#include<iostream>
#include<string> 
#include<sstream>
using namespace std;
const int maxn=10010;
//��aת��ΪB���� 
int length=0;
string t[maxn];
void turn(long long a,long long b){
	
	do{
		long long temp;
		temp=a%b;
		a=a/b;
		stringstream ss;
		ss<<temp;
		string s;
		ss>>s;
		t[length++]=s;
	}while(a);//����д��while(a){},��a==0ʱ��ֱ������loop�ˣ�����һ�����Ե������ 
}
bool flag=true;

int main(){
	long long a;
	long long b;
	cin>>a>>b;
	turn(a,b);
	for(int i=0;i<length/2;i++){
		int j=length-1-i;
		if(t[i] != t[j]){
			flag=false;
			break;
		}
	}
	if(flag)
	  cout<<"Yes"<<endl;
	else
	  cout<<"No"<<endl;
	for(int i=length-1;i>=0;i--)
	  if(i != 0)
	    cout<<t[i]<<" ";
	  else
	    cout<<t[i];
	return 0;
	//
}
