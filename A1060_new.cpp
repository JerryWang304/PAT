#include<string>
#include<iostream>
using namespace std;

int n;
string a,b;
//��aת��Ϊ��ѧ��������nλ��Ч���� 
string change(string a){
	//ȥ��ǰ��0
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
	//����Ĳ����ǶԵ�
	cout<<"a = "<<a<<endl;
	string ans=""; 
	//�������0 
	if(a[0]>'0'){
		//ȥ��С����
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
	}else{//���a��С�� 
	    ans+="0."; 
	    //0.123��ʽ 
	    
		if(a[2]>'0'){
			for(int i=0;i<n;i++){
				if(i > a.length()-1){
					ans+="0";
				}else{
					ans+=a[i];
				}
			}
			ans+="*10^1";
		}else if(a[2]=='0'){//0.00123��ʽ
		     int num=0;
		     int i=2;
		     while(a[i]=='0') 
			   i++;
			   i--;//i��ʾ���һ����������0��λ�� 
		     num=i-2+1;//0�ĸ���
		
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
