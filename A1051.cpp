//��� 
#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
stack<int> s;
int MAX;//ջ�����ֵ 
int length;//ÿ�����ݳ��� 
const int maxn = 1010;
bool vis[maxn]={false};
int main(){
	int k;
	scanf("%d%d%d",&MAX,&length,&k);
	for(int i=0;i<k;i++){
		int a[maxn];
		for(int j=0;j<length;j++){
			scanf("%d",&a[j]);
		}
        
        bool flag =true;
        
      while(!s.empty())
	    s.pop();
	//cout<<"s.empty()="<<s.empty()<<endl;
	//vis[i]=true��ʾ�Ѿ���ջ 
      fill(vis,vis+maxn,false);
	   for(int i=0;i<length;i++){
		int now=a[i];
		//��nowС����ȵģ���û����ջ��������ջ 
		cout<<i<<": length = "<<length<<endl;
		for(int j=1;j<=now && vis[j]==false;j++){
			s.push(j);
		}
		cout<<"s.top = "<<s.top()<<endl;
		if(s.size()>MAX)
		  flag =  false;
		if(s.top()==now){
			s.pop();
			vis[now]=true;
		}else{
			flag= false;
		}
	}


		if(flag)
		 printf("YES\n");
		else
		 printf("NO\n");
	}
	return 0;
}
