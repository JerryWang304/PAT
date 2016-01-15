#include<string>
#include<iostream>
using namespace std;

int n;
string a,b;
//将a转化为科学计数法，n位有效数字 
string change(string a){
	//去除前导0
	int index_dot=-1;
	for(int i=0;i<a.length();i++){
		if(a[i]=='.'){
			index_dot=i;
			break;
		}
	} 
	if(index_dot>=1){
		while(a[0]=='0'&&a.length()>0)
		  a.erase(a.begin());
		if(a[0]=='.')
	      a="0"+a;
	}else{
		while(a[0]=='0')
		  a.erase(a.begin());
	}
	//上面的步骤是对的
	cout<<"a = "<<a<<endl;
	string ans=""; 
	//如果大于0 
	if(a[0]>'0'){
		//去掉小数点
		string temp="";
		for(int i=0;i<a.length();i++)
		  if(a[i] != '.')
		    temp+=a[i]; 
		ans+="0.";
		for(int i=0;i<n;i++){
			if(i>temp.length()-1)
			 ans+="0";
			else
			 ans+=temp[i];
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
		return ans;
	}else{//如果a是小数 
	    ans+="0."; 
	    //0.123形式 
	    
		if(a[2]>'0'){
			for(int i=0;i<n;i++){
				if(i > a.length()-1){
					ans+="0";
				}else{
					ans+=a[i];
				}
			}
			ans+="*10^1";
		}else if(a[2]=='0'){//0.00123形式
		     int num=0;
		     int i=2;
		     while(a[i]=='0') 
			   i++;
			   i--;//i表示最后一个（连续）0的位置 
		     num=i-2+1;//0的个数
		
			 	for(int j=0;j<n;j++){
			 		if(i+j+1>a.length()-1)
			 		  ans+="0";
			 		else
			 		  ans+=a[j+i+1];
			 	}
			 
			 ans+="*10^-";
			 char t=char('0'+num);
			 ans+=t;
			
		}
		return ans;
	} 
	

}
int main(){
	cin>>n;
	cin>>a>>b;
	if(change(a)==change(b)){
		cout<<"YES "<<change(a);
	}else{
		cout<<"NO ";
		cout<<change(a)<<" "<<change(b);
	}
	return 0;
}
