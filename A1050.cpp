#include<iostream>
#include<string>
#include<map>
using namespace std;

string a,b;
map<char,bool> m;

int main(){
	getline(cin,a);
	getline(cin,b);
	
	for(int i=0;i<b.length();i++){
		char temp=b[i];
		m[temp]=true;
	}
	
	for(int i=0;i<a.length();i++){
		if(m[a[i]]==false)
		  cout<<a[i];
	}
	return 0;
	
}
