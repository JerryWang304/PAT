#include<cstdio>
#include<map>
using namespace std;

map<int,int> m;

int main(){
	int M,n;
	int a;
	scanf("%d%d",&M,&n);
	for(int i=0;i<n;i++){
		
		for(int j=0;j<M;j++){
			scanf("%d",&a);
			m[a]++;
		}
	}
	int MAX=-1,temp=0;
	for(map<int,int>::iterator it=m.begin();it != m.end();it++){
		if(it->second>MAX){
			temp=it->first;
			MAX=it->second;
		}
		
	}
	printf("%d",temp);
	return 0;
}
