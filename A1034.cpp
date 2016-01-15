#include<map>
#include<iostream>
#include<string>
using namespace std;
int n,k;
const int maxn = 2002;
int g[maxn][maxn]={0};

map<string,int> name2int;
map<int,string> int2name;

int num=0;//编号,每个名字对应一个编号，从0开始 
int getID(string name){
	if(name2int.find(name) != name2int.end()){
		return name2int[name];
	}else{
		name2int[name]=num;
		int2name[num]=name;
		return num++;
	}
}
int length[maxn]={0};//每个人的通话总时长 
int num_now_gang;//当前团伙的人数
int num_now_length;//当前团伙通话总时长
int max_length_now;//通话最长的那个人
int head;//头目
int total_now;//当前团伙的总时长 
bool vis[maxn]={false};
void DFS(int s){
	vis[s]=true;
	total_now+=length[s];//这样计算总时长是错的啊
	 
	if(length[s]>max_length_now){
		max_length_now=length[s];
		head=s;
	}
	num_now_gang++;
	for(int i=0;i<num;i++){
		if(!vis[i] && (g[s][i] != 0 || g[i][s] != 0) )
		  DFS(i);
	} 
} 
map<string,int> ans;//每个头目对应的人员数 
int main(){
	cin>>n>>k;
	string a,b;
	int length_now;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		int id_a=getID(a);
		int id_b=getID(b);
		cin>>length_now;
		g[id_a][id_b]=length_now;
		length[id_a]+=length_now;
		length[id_b]+=length_now; 
	}
	int total=0;//团伙总人数
	
	for(int i=0;i<num;i++){
		num_now_gang=0;
		num_now_length=0;
		max_length_now=0;
		head=0;
		total_now=0;
		if(!vis[i]){
		   DFS(i);
		     
		   if(total_now/2>k && num_now_gang>=3){//total_now/2才是总通话时长，length[]数组存储的是每个节点的通话总时长，用DFS访问时，每个的通话时长被访问了两次 
			string name_now=int2name[head];
			ans[name_now] = num_now_gang;
			total++;
		   }
		}

	}
	if(total==0){
		cout<<0;
		return 0;
	}
	cout<<total<<endl;
	map<string,int>::iterator it;
	for(it = ans.begin(); it != ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
