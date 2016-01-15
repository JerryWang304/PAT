//200000 -1  ->  输出结果为：1,999,999，而不是199,999,9
//2015-4-12 
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int c=a+b;
	//cout<<"c="<<c<<endl;
	if(c<0){
	 cout<<'-';
	 c=-c;
    }
	stringstream ss;
	string s;
	ss<<c;
	ss>>s;
	//cout<<"s="<<s<<endl;
	reverse(s.begin(),s.end());
	for(int i=s.length()-1;i>=0;i--){
		cout<<s[i];
		if(i%3==0 && i>0 ) 
		  cout<<',';
	}
	return 0;
}
