#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 26*26*26*10+2;
vector<int> course[maxn];

int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+name[i]-'A';
	}
	id = id*10+name[3]-'0';
	return id;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int a,b;
	for(int i=0;i<k;i++){
		scanf("%d%d",&a,&b);
		for(int j=0;j<b;j++){
			char name[5];
	    	scanf("%s",name);
		    int id=getID(name);
		    course[id].push_back(a);
		}
	}
	for(int i=0;i<n;i++){
		char name[5];
		scanf("%s",name);
		int id = getID(name);
		printf("%s %d",name,course[id].size());
		if(course[id].size()>0)
		  printf(" ");
		sort(course[id].begin(),course[id].end());
		for(int j=0;j<course[id].size();j++)
		  if(j==0) printf("%d",course[id][j]);
		  else printf(" %d",course[id][j]);
		if(i<n-1) printf("\n"); 
	}
	return 0;
}

