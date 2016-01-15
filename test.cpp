//一个序列排序好后的相邻两个数的差值的最大值 
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int maxn  = 2000;
int a[maxn];
int t[maxn]={0};
int main(){
	
	int MIN = 1000;
	int MAX = -101;
	
	for(int i=0;i<maxn;i++){
		int now = rand()%1000;
		a[i] = now;
		if(now < MIN) MIN = now;
	    if(now > MAX) MAX = now;
	    
	}
	
	for(int i=0;i<maxn;i++){
		t[a[i]]++;
	}
	int ans=0;
	int i=MIN,j=MIN;
	while(j<MAX){
		if(t[j] == 0)
		   j++;
		else{
			if(j-i>ans){
			  ans=j-i;

		    }
		    i=j;
		    j++;
		}
		
	}
	cout<<"ans = "<<ans<<endl;
	sort(a,a+maxn);
	int ret = 0;
	for(int i=1;i<maxn;i++){
		if(a[i] - a[i-1] > ret)
		  ret = a[i] - a[i-1];
	}
	cout<<"ret = "<<ret;
	return 0;
}

