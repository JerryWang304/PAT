#include<iostream> 
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 34000;
const int m=340;

struct node{
	string id;
	int score;
	int frank;
	int lrank;
	int local_number;
}Node[maxn],temp[m];

int n;//总共有n组
int total=0;

bool cmp(node a,node b){
	if(a.score != b.score)
	   return a.score>b.score;
	else
	   return a.id < b.id;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int count;//本组有多少个
		cin>>count;
		for(int j=0;j<count;j++){
			cin>>temp[j].id;
			cin>>temp[j].score;
			temp[j].local_number=i;
		} 
		//每读完一组，组内排序
		sort(temp,temp+count,cmp);
		temp[0].lrank=1;
		for(int j=1;j<count;j++){
			if(temp[j].score != temp[j-1].score)
			  temp[j].lrank = j+1;
			else
			  temp[j].lrank=temp[j-1].lrank;
		}
		
		for(int j=0;j<count;j++){
			Node[total++]=temp[j];
		}
		 
	}
	sort(Node,Node+total,cmp);
	Node[0].frank=1;
	for(int j=1;j<total;j++){
		if(Node[j].score != Node[j-1].score)
		  Node[j].frank = j+1;
		else
		  Node[j].frank=Node[j-1].frank;
	}
	cout<<total<<endl;
	for(int j=0;j<total;j++){
		cout<<Node[j].id<<" "<<Node[j].frank<<" "<<Node[j].local_number<<" "<<Node[j].lrank<<endl; 
	}
	return 0;
}



 
