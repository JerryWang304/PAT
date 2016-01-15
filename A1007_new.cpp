#include<iostream>
using namespace std;
const int maxn=10010;
int dp[maxn];//dp[i]存放以a[i]为结尾的连续序列的最大和
int a[maxn];
int s[maxn]={0};

int main(){
	
	int n;
	cin>>n;
	//这句如果改成bool flag;而不初始化的话，测试点4过不去 
	//解决方法：1->bool flag=false;
	//          2->在main函数外面定义bool flag;这样flag默认为false，定义在主函数里是随机值 
	bool flag=false;//flag=false表示全为负数
	
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
    dp[0]=a[0];
	for(int i=1;i<n;i++){
		if(dp[i-1]+a[i]>a[i]){//选a[i]
		   dp[i]=dp[i-1]+a[i]; 
		   s[i]=s[i-1];
		}else{//不选a[i] 
			dp[i]=a[i];
			s[i]=i; 
		}
	} 
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k])
		  k=i;
	}
	cout<<dp[k]<<" "<<a[s[k]]<<" "<<a[k];//是输出数，不是下标 
	return 0;
} 
//我把上面的注销重写，测试点全过了，说明我原来的部分（动态规划之前的）有问题 
//#include<iostream>
//using namespace std;
//const int maxn=10010;
//int a[maxn],dp[maxn];
//int s[maxn]={0};
//
//
//int main(){
//	int n;
//	cin>>n;
//	bool flag=false;
//	for(int i=0;i<n;i++){
//	
//	  cin>>a[i];
//	  if(a[i]>=0)
//	    flag=true;
//    }
//    if(flag==false){
//    	cout<<0<<" "<<a[0]<<" "<<a[n-1];
//    	return 0;
//    }
//    dp[0]=a[0];
//    for(int i=1;i<n;i++){
//    	if(dp[i-1]+a[i]>a[i]){
//    		dp[i]=dp[i-1]+a[i];
//    		s[i]=s[i-1];
//    	}else{
//    		dp[i]=a[i];
//    		s[i]=i;
//    	}
//    }
//    int k=0;
//    for(int i=0;i<n;i++){
//    	if(dp[i] > dp[k])
//    	  k=i;
//    }
//    cout<<dp[k]<<" "<<a[s[k]]<<" "<<a[k];
//}





