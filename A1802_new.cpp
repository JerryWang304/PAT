#include<iostream> 
#include<string>
#include<sstream>
using namespace std;

char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[4][5]={"Shi","Bai","Qian","Wan"};

int main(){
	string a;
	cin>>a;
	int count=0;//几位数 
	
	if(a[0]=='-'){
	  cout<<"Fu ";
	  count=a.length()-1;
	  string::iterator it = a.begin();
	  a.erase(it);
    }
    int j=a.length()-1;//从后往前
	string out[12];
	int len_out=0;
	//末尾有连续个0的情况要考虑
//	while(a[j]=='0')
//	 j--; 
	while(j>=0){
		if(a[j] != '0'){
			stringstream ss;
			ss<<num[a[j]-'0'];
			string s;
			ss>>s;
			if(j==a.length()-1){
				out[len_out++]=s;
			}else if(j==0 && a.length()==9){
				out[len_out++]=s+" "+"Yi";
			}else{
				stringstream sm;
				sm<<wei[(a.length()-j-2)%4];
				string t;
				sm>>t;
				out[len_out++]=s+" "+t;
			}
			j--;
		}else{//0位 
		   
		   while(a[j]=='0'){
		   	   
		       j--;	
		   }
		}
	}
	for(int i=len_out-1;i>=0;i--)
	 if(i == len_out-1)
	  cout<<out[i];
	 else
	  cout<<" "<<out[i]; 
	return 0;
	
}
