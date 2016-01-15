#include<iostream>
using namespace std;
int pre[5];

void DFS(int s,int v){
	if(v==s){
		cout<<v<<endl;
		return;
	}
	DFS(s,pre[v]);
	cout<<v<<endl;
}

int main(){
	pre[1]=1;
	pre[2]=1;
	pre[3]=2;
	pre[4]=3;
	DFS(1,4);
	return 0;
	
}
