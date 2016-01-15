#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100100;
int n,p,a[maxn];

int main(){
	cin>>n>>p;
	for(int i=0;i<n;i++)
	  cin>>a[i];
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		int j=upper_bound(a+i+1,a+n,(long long)a[i] * p)-a;
		int len=j-i;
		ans=max(ans,len);
	}
	cout<<ans;
	return 0;
}
