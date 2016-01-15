#include<cstdio>
#include<algorithm>
#include<sstream>
using namespace std;
int nrofONE(int a){
	stringstream ss;
	ss<<a;
	string s;
	ss>>s;
	int count=0;
	for(int i=0;i<s.length();i++)
	  if(s[i]=='1')
	   count++;
	return count;
}
int main(){
	int n;
	scanf("%d",&n);
	int count=0;
	for(int i=1;i<=n;i++)
	 count+=nrofONE(i);
	printf("%d",count);
	return 0;
}
