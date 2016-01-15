#include<iostream>
#include<map>
#include<cstdio>
using namespace std;

int main(){
	map<int,double> m;
	int n1;
	cin>>n1;
	for(int i=0;i<n1;i++){
		int a;
		double b;
		cin>>a;
		cin>>b;
		m[a]=b;
	}
	int n2;
	cin>>n2;
	for(int i=0;i<n2;i++){
		int a;
		double b;
		cin>>a;
		cin>>b;
		m[a]+=b;
		if(m[a]==0)
		 m.erase(a);//系数相加后，可能会为0，所以要去掉 ，要不好几个测试点过不了 
	}
	map<int,double>::iterator it;
	//不加下面这段，最后一个测试点过不了 
	if(m.size()==0){
		printf("%d",m.size());
		return 0;
	} 
	printf("%d ",m.size());
	
	for(it=m.end();it != m.begin();it--)
	  if(it != m.end())
	    printf("%d %.1lf ",it->first,it->second);
	printf("%d %.1lf",it->first,it->second);
	return 0;
}
