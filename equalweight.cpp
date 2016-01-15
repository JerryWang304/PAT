#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 200;
struct node{
	int id;
	vector<int> child;
}Node[maxn];
int n,m,s;
int weight[maxn];
vector<int> ans[maxn];
int len=0;

bool cmp(vector<int> v1,vector<int> v2){
	int i=0,j=0;
	while(i<v1.size() && j<v2.size()){
		if(v1[i] > v2[j])
			return true;
		i++;
		j++;
	}
	return false;
}

void DFS(int now,int sum,vector<int> path){
	sum+=weight[now];
	if(sum>s){
		return;
	}
	if(sum == s && Node[now].child.size() == 0){
		path.push_back(weight[now]);
		ans[len++]=path;
		return;
	}
	path.push_back(weight[now]);
	for(int i=0;i<Node[now].child.size();i++)
		DFS(Node[now].child[i],sum,path);
	path.pop_back();
}

int main(){
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
		cin>>weight[i];
	for(int i=0;i<m;i++){
		int id;
		int k;
		int chi;
		cin>>id>>k;
		Node[id].id = id;
		for(int j=0;j<k;j++){
			cin>>chi;
			Node[id].child.push_back(chi);
		}
	}
	vector<int> path;
	path.clear();
	DFS(0,0,path);
	sort(ans,ans+len,cmp);
	for(int i=0;i<len;i++){
		for(int j=0;j<ans[i].size();j++){
			if(j<ans[i].size()-1)
				cout<<ans[i][j]<<" ";
			else
				cout<<ans[i][j]<<endl;
		}
	}
	return 0;
}
