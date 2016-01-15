#include<iostream>
#include<cstring>
using namespace std;
const int maxn=101000;
struct node{
	char id[20];
	char in[10];
	char out[10];
}Node[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].id>>Node[i].in>>Node[i].out;
	}
	char min[10]="99:99:99",max[10]="00:00:00";
	int index_first=0,index_last=0;
	for(int i=0;i<n;i++){
		if(strcmp(Node[i].in,min)<0){
		  strcpy(min,Node[i].in);
		  index_first=i;
	    }
		if(strcmp(Node[i].out,max)>0){
		  index_last=i;
		  strcpy(max,Node[i].out);
	    }
	}
	cout<<Node[index_first].id<<" "<<Node[index_last].id;
	return 0;
}
