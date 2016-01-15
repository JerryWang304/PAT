#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=9999;
int g[maxn][maxn];
int result[maxn];
int n;//顶点数

int main(){
	cin>>n;
	for(int i=1;i<n;i++){
	  cin>>g[i][i+1];
	  g[i+1][i]=g[i][i+1];
    }
	cin>>g[n][1];
	g[1][n]=g[n][1];
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		//计算a->b的最短路径
		if(a==b){
			result[i]=0;
		}else{
			//往左走
			int now=a;
			int left=0;
			do{
				now=(now+1)%n==0 ? n : (now+1)%n;
				int index;
				if(now-1<=0)
				  index=n+(now-1)%n;
				else
				  index=(now-1)%n;
				  
				left+=g[index][now]; 
				//cout<<"left now:"<<left<<endl;				                                                               ;
			}while(now != b);
			//cout<<"left"<<":"<<left<<"   "; 
			//往右走
			int Now=a;
			int right=0;
			do{
				Now = Now-1<=0 ? n+(Now-1)%n : (Now-1)%n;
				int index=(Now+1)%n;
				if(index==0)
				 index=n;
				right+=g[index][Now];
				//cout<<"right now:"<<right<<endl;
			}while(Now != b);
			//cout<<"right"<<":"<<right<<endl;
			result[i]=min(left,right);
		}
	}
	for(int i=0;i<m;i++)
	  cout<<result[i]<<endl;
	return 0;
} 
