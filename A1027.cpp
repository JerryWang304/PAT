#include<iostream> 
using namespace std;
int main(){
	int r,g,b;
	cin>>r>>g>>b;
	char a[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	cout<<"#";
	cout<<a[r/13]<<a[r%13];
	cout<<a[g/13]<<a[g%13];
	cout<<a[b/13]<<a[b%13];
	return 0;
}
