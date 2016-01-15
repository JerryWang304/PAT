#include<iostream>
#include<map>
#include<string>
using namespace std;

map<string,int> m;

bool check(char t){
	if(t>='0' && t<='9') return true;
	if(t>='A' && t<='Z') return true;
	if(t>='a' && t<='z') return true;
	return false;
}

int main(){
	string str;
	getline(cin,str);
	int i=0;
	while(i < str.length()){
		string word="";
		while(i<str.length() && check(str[i])==true){
			if(str[i]>='A' && str[i]<='Z')
			  str[i]=str[i]-'A'+'a';
			word+=str[i];
			i++;
		}
		if(word.length()>0)
		  m[word]++;
		while(!check(str[i]))
		i++;
	}
	int MAX=-10;
	string ans;
	for(map<string,int>::iterator it=m.begin();it != m.end();it++){
		if(it->second>MAX){
			MAX=it->second;
			ans=it->first;
		}
	}
	cout<<ans<<" "<<MAX;
	return 0;
}
