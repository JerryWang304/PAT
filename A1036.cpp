#include<iostream> 
#include<string>
using namespace std;

const int maxn = 10010;

struct node{
	string name;
	char gender;
	string id;
	int score;
}Node[maxn];

int index_M=-1,index_F=-1;
int min_M=101,max_F=-12;

int n;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].name;
		cin>>Node[i].gender;
		cin>>Node[i].id;
		cin>>Node[i].score;
		
		if(Node[i].gender=='M'){
			if(Node[i].score<min_M){
				index_M=i;
				min_M=Node[i].score;
			}
		}else{
			if(Node[i].score>max_F){
				index_F=i;
				max_F=Node[i].score;
			}
		}
	} 
	int d=max_F-min_M;
	if(index_F != -1)
	  cout<<Node[index_F].name<<" "<<Node[index_F].id<<endl;
	else
	  cout<<"Absent"<<endl;
	if(index_M != -1)
	  cout<<Node[index_M].name<<" "<<Node[index_M].id<<endl;
	else
	  cout<<"Absent"<<endl;
	if(index_M == -1 || index_F == -1)
	  cout<<"NA";
	else
	  cout<<d;
	return 0;
}











