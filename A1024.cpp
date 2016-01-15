#include<iostream>
#include<string>
#include<sstream>
using namespace std;

long long re(long long x){
	stringstream ss;
	ss<<x;
	string str;
	ss>>str;
	long long temp=0;
	string s(str.rbegin(),str.rend());
	for(int i=0;i<s.length();i++)
	  temp = temp*10 +s[i]-'0';
	return temp;
}

long long num(string s){
	long long temp=0;
	for(int i=0;i<=s.length();i++)
	  temp = temp*10 +s[i]-'0';
	return temp;
}

bool isP(long long x){
	stringstream ss;
	ss<<x;
	string s;
	ss>>s;
	for(int i=0;i<s.length()/2;i++)
	  if(s[i] != s[s.length()-1-i])
	    return false;
	return true;
}

int main(){
	int max_step;
	long long first;
	cin>>first>>max_step;
	long long second=re(first);
	int step=0;
	while(!isP(first) && step<max_step){
		first=first+second;
		second=re(first);
		step++;
	}
	cout<<first<<endl;
	cout<<step;
	return 0;
} 
