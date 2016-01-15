#include<iostream>
#include<string>
using namespace std;
const int maxn=1200;
struct node{
	string name;
	string pword;
	bool isModified;
}Node[maxn];

int n;
bool isChanged=false;
int all=0;
bool thisChanged=false;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].name;
		cin>>Node[i].pword;
		string p=Node[i].pword;
		for(int j=0;j<p.length();j++){
			if(p[j]=='1'){
				p[j]='@';
				Node[i].isModified=true;
				isChanged=true;
				thisChanged=true;
			}else if(p[j]=='0'){
				p[j]='%';
				Node[i].isModified=true;
				isChanged=true;
				thisChanged=true;
			}else if(p[j]=='l'){
				p[j]='L';
				Node[i].isModified=true;
				isChanged=true;
				thisChanged=true;
			}else if(p[j]=='O'){
				p[j]='o';
				Node[i].isModified=true;
				isChanged=true;
				thisChanged=true;
			}
			
		}
		Node[i].pword=p;
		if(thisChanged){
			all++;
			thisChanged=false;
		}
	}
	
	if(n==1){
		if(isChanged)
		  cout<<1<<endl<<Node[0].name<<" "<<Node[0].pword;
		else
		  cout<<"There is 1 account and no account is modified";
	}else{
		if(!isChanged)
		  cout<<"There are "<<n<<" accounts and no account is modified";//这句话与上面的不一样 
		else{
			cout<<all<<endl;
			for(int i=0;i<n;i++){
				if(Node[i].isModified==true){
					cout<<Node[i].name<<" "<<Node[i].pword<<endl;
				}
			}
		}
	}
	return 0;
}
