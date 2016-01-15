#include<cstdio>
#include<stack>
using namespace std;

stack<int> s;

int MAX,n,k;
const int maxn = 1010;
int a[maxn];

bool isTrue(int a[]){//长度为n
	while(!s.empty())
	  s.pop();
	//每个数依次入栈
	int index=0;//a[index]为当前比较的元素 
	for(int i=1;i<=n;i++){
		s.push(i);
		if(s.size()>MAX)
		  return false;
		   while(!s.empty() && s.top() == a[index]){
		    	index++;
			    s.pop();
		   }
	} 
	if(!s.empty()) 
	  return false;
	return true; 
}

int main(){
	scanf("%d%d%d",&MAX,&n,&k);
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++)
		  scanf("%d",&a[j]);
	  if(isTrue(a))
	   printf("YES\n");
	  else
	  printf("NO\n");
	}

	return 0;
}
