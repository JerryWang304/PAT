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
		//�Ƚϵ�a����b������
		int nrofCom=0;//��ͬ��Ԫ�صĸ���
		for(set<int>::iterator it=s[a].begin(); it != s[a].end();it++){
			int now=*it;
			set<int>::iterator temp=s[b].find(now);//�����һ��һ���ȽϵĻ��ᳬʱ 
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
