#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
int n,m,k,ds;
const int maxn=1100;
int g[maxn][maxn];

int getID(string s){
	int sum=0;
	for(int i=0;i<s.length();i++){
		if(s[i]!='G'){
			sum=sum*10 + s[i]-'0';//脑抽写成sum+=...... 
		}
	}
	if(s[0]=='G') return n+sum;
	else return sum;
}

int vis[maxn]={false};
int d[maxn];
const int INF=1e9;
double avg;
int Max;
double Min;
void Dijkstra(int s){
	fill(d,d+maxn,INF);
	d[s]=0;
	for(int i=0;i<n+m;i++){
		int u=-1,MIN=INF;
		for(int j=1;j<=n+m;j++){
			if(!vis[j] && d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n+m;v++){
			if(!vis[v] && g[u][v] != INF){
				if(d[u]+g[u][v] < d[v]){
					d[v] = d[u] + g[u][v];
				}
			}
		}
	}
	//计算平均距离，和最大距离
	int sum=0;
	int max_temp=-1;
	double min_temp=INF;
	for(int i=1;i<=n;i++){
		sum+=d[i];
		if(d[i]>max_temp)
		  max_temp=d[i];
		if(d[i]<min_temp)
		  min_temp=d[i];
	}
	Max=max_temp;
	Min=min_temp;
	avg=sum*1.0/n;

}
struct node{
	int id;
	double avg;
	double min;
}Node[maxn];
int length=0;
//题目没完全理解透，导致cmp函数写错了 
bool cmp(node a,node b){
	if(a.min != b.min)
	  return a.min > b.min;
	else if(a.avg != b.avg)
	  return a.avg < b.avg;
	else
	  return a.id < b.id;
}
double re(double t){
	int temp =(int)(t*100);
	temp=temp%10;
	if(temp>=5) {
		int r=(int)(t*10);
		r++;
		t=r*1.0/10;
	}
	else{
		int r=(int )(t*10);
		t=r*1.0/10;
	}
	return t;
}
int main(){
	cin>>n>>m>>k>>ds;
    fill(g[0],g[0]+maxn*maxn,INF);
	for(int i=0;i<k;i++){
		string a,b;
		int len;
		cin>>a>>b>>len;
		g[getID(a)][getID(b)]=len;
		g[getID(b)][getID(a)]=len;
	}

	for(int i=n+1;i<=n+m;i++){
		fill(vis,vis+maxn,false);

		Dijkstra(i);
		if(Max<=ds){//每个居民都在范围内 
			Node[length].id=i;
			Node[length].avg=avg;
			Node[length].min=Min;
			length++;
	        //cout<<Min<<" "<<avg<<endl;
		}
	}
	if(length==0){
	    printf("No Solution");
		return 0;
	}
	sort(Node,Node+length,cmp);
	//cout<<'G'<<Node[0].id-n<<endl;
	printf("G%d\n",Node[0].id-n);
	double ans_min=re(Node[0].min);
	double ans_avg=re(Node[0].avg);
	printf("%.1f %.1f",ans_min,ans_avg);
	return 0;
}
