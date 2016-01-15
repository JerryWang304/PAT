#include<iostream>
#include<map>
#include<cstdio>
#include<cmath>
using namespace std;

map<int,double> origin;
map<int,double> m;
map<int,double>::iterator it;
//map<int,double> s;
int main(){
	int n1,n2;
	scanf("%d",&n1);
	for(int i=0;i<n1;i++){
		int a;
		double b;
		scanf("%d %lf",&a,&b);
		origin[a]=b;
	}
	scanf("%d",&n2);
	for(int i=0;i<n2;i++){
		int a;
		double b;
		scanf("%d %lf",&a,&b);
		//没读入一个，都与origin里面的相乘
		 it=origin.begin();
		 while(it != origin.end()){
		 	int ex=it->first+a;
		 	double co=it->second*b;
		 	m[ex]+=co;
		 	it++;
//		 	cout<<"ex: "<<ex;
//		 	cout<<" co: "<<co<<endl;
//		 	cout<<"m.size()= "<<m.size()<<endl;

		 } 
	}
	//去掉系数为0的项,没有这一步，第一个测试点过不了 
	for(it=m.begin();it != m.end();it++){
		if(fabs(it->second-0)<=1e-5)
		  m.erase(it);
	} 
	printf("%d",m.size());
	for(it=m.end();it != m.begin();it--){
	   if(it != m.end())	
	      printf(" %d %.1lf",it->first,it->second);
	}
	printf(" %d %.1lf",it->first,it->second);
	return 0;
}
