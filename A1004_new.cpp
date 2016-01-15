#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=120;

vector<int> G[maxn];
int leaf[maxn]={0};//left[i]��ʾ��i���Ҷ�ӽڵ�ĸ���
int max_h=1;

void DFS(int index,int h){
	max_h=max(h,max_h);
	if(G[index].size()==0){
	 leaf[h]++;
	 return;
    }
    for(int i=0;i<G[index].size();i++){
    	DFS(G[index][i],h+1);
    }
} 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int parent,k;
		cin>>parent>>k;
		for(int j=0;j<k;j++){
			int child;
			cin>>child;
			G[parent].push_back(child);
		}
	} 
	DFS(1,1);
	cout<<leaf[1];
	for(int i=2;i<=max_h;i++)
	  cout<<" "<<leaf[i];
	return 0;
}


