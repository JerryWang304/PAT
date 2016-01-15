#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100100;
int sum=0;
int d[maxn];
int a[maxn];

int result[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		d[i]=sum;
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if(a<b) 
		  swap(a,b);
		int x=d[a-1]-d[b-1];
		result[i]=min(sum-x,x);
	}
	for(int i=0;i<m;i++)
	 cout<<result[i]<<endl;
	return 0;
}
