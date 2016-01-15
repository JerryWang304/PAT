#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=10010;
int a[maxn],n;
int now=0,sum=0;//现在在第几层

int main(){
	scanf("%d",&n);
//	cout<<"n= "<<n<<endl;
	for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	
	for(int i=0;i<n;i++){
		if(a[i]>now){
			sum+=(a[i]-now)*6+5;
		//	now=a[i];
		}else if(a[i] < now){
			sum+=(now-a[i])*4+5;
		//	now=a[i];
		}else if(a[i] == now){
			sum+=5;//这是个坑。。。不加这句测试点2,3,6过不了 
		}
		now=a[i];
//		cout<<"a["<<i<<"]= "<<a[i]<<endl;
//		cout<<"sum= "<<sum<<endl;
//		cout<<"now= "<<now<<endl;
	} 
	cout<<sum;
	return 0;
} 
