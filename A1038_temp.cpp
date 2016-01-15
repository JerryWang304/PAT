#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100100;
string str[maxn]; 
string ans="";

bool cmp(string a,string b){
	return a+b<b+a;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>str[i];
	}
	sort(str,str+n,cmp);
	for(int i=0;i<n;i++)
	  ans+=str[i];
    while(ans[0]=='0'){
    	if(ans.size()==1)//不加这句会测试点通不过 
    	  break;
    	ans.erase(ans.begin());

    }
	cout<<ans;
	return 0;
	
}
