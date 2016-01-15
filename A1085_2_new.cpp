//two pointer
#include<iostream>
#include<algorithm>
using namespace std;
int n,p;
const int maxn = 100100;
int a[maxn];

int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	sort(a,a+n);
	int i=0,j=0,count=1;
	while(i<n && j<n){
		while(j<n && a[j]<=(long long)a[i]*p){
			count=max(count,j-i+1);
			j++;
		}
		i++;
	}
	cout<<count;
	return 0;
}
