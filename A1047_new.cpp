#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 40010;
vector<int> course[maxn];
char name[maxn][5];

bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",name[i]);
		int c;
		scanf("%d",&c);
		for(int j=0;j<c;j++){
			int temp;
			scanf("%d",&temp);
			course[temp].push_back(i);
		}
	}
	//对每门课程 学生姓名排序
	for(int i=1;i<=k;i++){
		sort(course[i].begin(),course[i].end(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(vector<int>::iterator it=course[i].begin();it != course[i].end();it++){
			int index=*it;
			printf("%s\n",name[index]);
		}
	} 
	return 0;
}
