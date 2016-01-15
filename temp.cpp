#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

string add(string str1,string str2){
	//翻转以后相加，这样下标就可以从0开始了 
	string s1(str1.rbegin(),str1.rend());
	string s2(str2.rbegin(),str2.rend());
	if(s1.length() < s2.length()){
		swap(s1,s2);
	}
	//s1长
	int len=s1.length()-s2.length();
	for(int i=0;i<len;i++)
	  s2+='0'; 
	int a,b,carry=0;
	string sum="";
	for(int i=0;i<s1.length();i++){
		a=s1[i]-'0';
		b=s2[i]-'0';	
		int temp=(carry+a+b)%10;
		sum+=(char)(temp+'0');
		carry=(carry+a+b)/10;
		
	}
	if(carry>0)
	  sum+=(char)(carry+'0');
	sum=string(sum.rbegin(),sum.rend());
	cout<<endl;
	return sum;
}
int main(){
	string str1,str2;
	cin>>str1>>str2;
	cout<<add(str1,str2);
	return 0;
}

