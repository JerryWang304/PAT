#include<iostream>
using namespace std;
const int maxn = 120;
long long a,b,c;
int result[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		long long add = a+b;
		if(a>0 && b>0 && add <0)
		  result[i]=1;
		else if(a<0 && b<0 && add >= 0){
			result[i]=0;
		}else if(add > c)
		   result[i]=1;
		 else result[i]=0;
	}
	for(int i=0;i<n;i++){
		cout<<"Case #"<<i+1<<": ";
		if(result[i]==0)
		  cout<<"false"<<endl;
		else
		  cout<<"true"<<endl;
	}
	return 0;
}
