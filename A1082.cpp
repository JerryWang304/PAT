//看题目本以为及其复杂，其实仔细想想也还好
//从前往后的话，确实不好模拟，不过从后往前就比较好理解了
//不过还是有一个测试点过不了555~ 
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
	int counting=0;
	while(a[j]=='0'){
		j--;
		counting++;
	}
	if(j==0&&a.length()==9)
	 out[len_out++]="Yi";
	else if(counting>=5&&a.length()>=5)
	 out[len_out++]="Wan";
	while(j>=0){
		if(a[j]=='0'){
			if(j==a.length()-1){
				j--;
			}
			else{
			     out[len_out++]="ling";
			  while(a[j] == '0'){
			  	if(a.length()-j-5==0)
			  	  out[len_out++]="Wan";
			  	j--;
			  }
		    }
		}else{
			stringstream ss;
			ss<<num[a[j]-'0'];
			string temp;
			ss>>temp;
			if(j==a.length()-1){
				out[len_out++]=temp;				
			}else if(j==0 && a.length()==9){
				out[len_out++]=temp+" Yi";
			}else {
				stringstream sss;
				sss<<wei[(a.length()-j-2)%4];
				//cout<<" (j-2)%4 = "<<(count-j-2)%4<<endl;
				string t;
				sss>>t;
				//cout<<"t= "<<t<<endl;
				out[len_out++]=temp+" "+t;
			}
			j--;
		}
	}
	for(int i=len_out-1;i>=0;i--)
	 if(i == len_out-1)
	  cout<<out[i];
	 else
	  cout<<" "<<out[i]; 
	return 0;
	
}
