//��Ŀ 
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int maxn=1200;
string str[maxn];
string output[20][5];
//���ع���β��
string common(string a,string b){
	string com="";
	
	int len_a=a.length();
	int len_b=b.length();
	int i=len_a-1,j=len_b-1;
	for(;i>=0 && j>=0;i--,j--){
		if(a[i]==b[j]){
			com.append(1,a[i]);
		}else{
			break;
		}
	}
	string s;
	s.assign(com.rbegin(),com.rend());//�ַ�����ת 
	return s;
} 

int main(){
	int n;
	cin>>n;
	int i=0; 
	do{
		getline(cin,str[i]);
		i++;
	}while(i<=n);
	//Ϊʲôstr[0]û�ж����ȥ��������������Ӧ���Ƕ���n֮��Ŀո� 
	string com;
	string first=str[1];
	
    i=2;
	while(i<=n){
		com=common(first,str[i]);
		first=com;
		i++;
	}
	if(com.length()==0)
	  cout<<"nai";
	else
	  cout<<com;
	return 0;	
}
