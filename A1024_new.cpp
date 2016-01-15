#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

bool isP(string str){
	int len=str.length();
	for(int i=0;i<=len/2;i++)
	  if(str[i] != str[len-1-i])
	    return false;
	return true;
} 

string reverse(string str){
	string temp(str.rbegin(),str.rend());
	return temp;
}
//这里的两个字符串长度相等的 
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
	return sum;
}
int main(){
	string str;
	int max_step;
	int step=0;
	cin>>str>>max_step;
	
	while(!isP(str) && step<max_step){
		string temp=reverse(str);
		str=add(str,temp);
		step++; 
	}
	cout<<str<<endl<<step;
	return 0;
}

