//两个测试点过不了 ,改完flag。。。还是有一个测试点过不了555~ 
#include<iostream>
using namespace std;
const int maxn=10010;
int main(){
	
	int n;
	cin>>n;
	bool flag=false;//flag=false表示全为负数，，，一定要初始化!
	int a[maxn];
	for(int i=0;i<n;i++){
	  cin>>a[i];
	  if(a[i]>=0)
	    flag=true;
    }
	if(flag==false)//如果全是负数
	{
		cout<<0<<" "<<a[0]<<" "<<a[n-1];
		return 0;
	} 
	//最大子序列和
	int max=0;
	int ThisSum=0;
	int first,last;
	for(int i=0;i<n;i++){
		ThisSum+=a[i];
		if(ThisSum>max){
		 max=ThisSum;
		 last=i;
	    }
		else if(ThisSum<0){
		  ThisSum=0; 
	    }
	} 
	
	int i,temp=0;
	for(i=last;i>=0;i--){
		temp=temp+a[i];
		if(temp==max)
		 break;
	}

	first=i;
	cout<<max<<" "<<a[first]<<" "<<a[last];//是输出数，不是下标 
	return 0;
}
