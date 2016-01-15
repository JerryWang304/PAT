#include<cstdio>
#include<set>
using namespace std;
const int maxn=55;
set<int> s[maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int count;
		scanf("%d",&count);
		for(int j=0;j<count;j++){
			int temp;
			scanf("%d",&temp);
			s[i].insert(temp);
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		//比较第a个第b个集合
		int nrofCom=0;//相同的元素的个数
		for(set<int>::iterator it=s[a].begin(); it != s[a].end();it++){
			int now=*it;
			set<int>::iterator temp=s[b].find(now);//如果是一个一个比较的话会超时 
			if(temp != s[b].end()){
				nrofCom++;
			}
		} 
		int nc=nrofCom;
		//printf("nc=%d\n",nc);
		int nt=s[a].size()+s[b].size()-nrofCom;
		//printf("nt=%d\n",nt);
		double rate=nc*1.0/nt;
		//printf("rate=%lf\n",rate);
		if(int(rate*10000) % 10 >= 5) 
		  rate=rate+0.001;
		int x=int(rate*100);
		int y=int(rate*1000) % 10;
		printf("%d.%d%%\n",x,y);
	}
	return 0;
}
