//自己写出来的，好开森啊。。。估计到了考场上写不出来 
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map> 
#include<set>
using namespace std;
const int maxn = 250;
const int INF = 1e9;
int n,k;
int g[maxn][maxn];
bool vis[maxn]={false};
string start;
map<string,int> name2index;
map<int,string> index2name;
int num=0;
set<string> Set; 
int getID(string s){
//	set<string>::iterator it =Set.begin();
	if(Set.find(s)==Set.end()){
	   Set.insert(s);
	   name2index[s]=num;
	   index2name[num]=s;
	   int t=num;
	   num++;
	   return t;		
	}else{
		return name2index[s];
	}
}
int d[maxn];
int h[maxn];
vector<int> temp,path;
vector<int> pre[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n;i++)
	  pre[i].push_back(i);
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(!vis[j] && d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(!vis[v] && g[u][v] != INF){
				if(d[u] + g[u][v] < d[v]){
					d[v] = d[u] + g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u] + g[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	} 
}
int Max=-1;
int Max_avg=-1;
int nrofRodes=0;
int ans_ha;
void DFS(int v){
	if(v==0){
		nrofRodes++;
		temp.push_back(v);
		int sum_ha=0;
		double avg_ha=0;
		for(int i=0;i<temp.size();i++){
			sum_ha+=h[temp[i]];
		}
		avg_ha=sum_ha/(temp.size()-1);
		if(Max < sum_ha){
			Max  = sum_ha;
			Max_avg = avg_ha;//这句话....critical 
			path = temp;
		}else if(Max == sum_ha && avg_ha > Max_avg){
			Max_avg=avg_ha;
			path=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(v);
	for(int i=0;i<pre[v].size();i++)
	  DFS(pre[v][i]);
	temp.pop_back();
}

int main(){
	cin>>n>>k>>start;
	int s=getID(start);//s=0
	fill(g[0],g[0]+maxn*maxn,INF);
	for(int i=1;i<=n-1;i++){
		string t;
		int happy;
		cin>>t>>happy;
		h[getID(t)]=happy;
		
	}
	for(int i=0;i<k;i++){
		string a,b;
		int c;
		cin>>a>>b>>c;
		g[getID(a)][getID(b)] = g[getID(b)][getID(a)] =c;
	}
	Dijkstra(0);
	DFS(getID("ROM")); 
	for(int i=path.size()-1;i>=0;i--){
		ans_ha+=h[path[i]];
		
	}
	int ans_avg=ans_ha/(path.size()-1);
	cout<<nrofRodes<<" "<<d[getID("ROM")]<<" "<<ans_ha<<" "<<ans_avg<<endl;
	for(int i=path.size()-1;i>=0;i--){
		cout<<index2name[path[i]];
		if(i!=0) cout<<"->";
	}	
	return 0;
}
