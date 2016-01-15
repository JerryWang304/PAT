#include<string>
#include<iostream>
using namespace std;

int n;
string a,b;

bool isEqual(string a,string b){
	for(int i=0;i<n;i++){
		if(a[i] != b[i] && a[i] != '.' && b[i] != '.')
		  return false;
		else if(a[i] == b[i] && a[i]=='.'){
			i++;
			n++;
			if(a[i] != b[i])
			  return false;
		}
	}
	return true;
}
//将a写成科学计数法形式 
string change(string a){
	string ans="";
	if(a=="0"){
		return "0";
	}else{
		ans+="0.";
		//去掉.
		string temp="";
		for(int j=0;j<a.length();j++){
			if(a[j] != '.')
			  temp+=a[j];
		} 
		for(int i=0;i<n;i++){
			if(i>temp.length()-1)
			  ans+="0";	
			else{
				ans+=temp[i];
			}
			  
		}
		ans+="*10";
		int i;
		for(i=0;i<a.length();i++){
			if(a[i]=='.')
			  break;
		}
		int ex;
		if(i==a.length()-1)
		  ex=a.length();
		else
		  ex=i;
		ans+="^";
		char t=(char)(ex+'0');
		ans+=t;
		
	}
	return ans;
}

int main(){
	cin>>n>>a>>b;
	if(isEqual(a,b)){
		cout<<"YES ";
		cout<<change(a);
	}else{
		cout<<"NO ";
		cout<<change(a)<<" "<<change(b);
	}
	return 0;
}
