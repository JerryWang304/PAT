#include<iostream>
using namespace std;
const int maxn=100100; 
int h[maxn];
int n;
int a[maxn];

int main(){
	cin>>n;
	fill(h,h+maxn,-1);
	int max=-1;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a[i]=temp;
		if(temp>max)
		  max=temp;
		h[temp]++;
		
	}
	bool flag=false;
	for(int i=0;i<n;i++){
		//cout<<"a["<<i<<"]:"<<a[i]<<"   h["<<"a["<<i<<"]"<<"]:"<<h[a[i]]<<endl;
		if(h[a[i]]==0){
			flag=true;
			cout<<a[i];
			break;
		}
	}
	if(flag==false)
	  cout<<"None";
	return 0;
}
