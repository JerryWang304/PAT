#include<iostream>
using namespace std;
const int maxn = 10010;
int a[maxn],n;
int d[maxn],s[maxn];
int main(){
	cin>>n;
	for(int i=0;i<n;i++) 
	  cin>>a[i];
	int Max=0,thisSum=0;
	d[0]=a[0];
	s[0]=0;
	for(int i=1;i<n;i++){
		if(d[i-1]+a[i] > a[i]){
			d[i]=d[i-1]+a[i];
			s[i]=s[i-1];
		}else{
			d[i]=a[i];
			s[i]=i;
		}
	}
	int u=0;
	for(int i=0;i<n;i++){
		if(d[i]>d[u]){
			u=i;
		}
	}
	cout<<d[u]<<" "<<a[s[u]]<<" "<<a[u]; 
	return 0;
}
