// ע�⣺aiing bing
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 100100;

struct node{
	int add;
	char data;
	int next;
}Node[maxn];

int main(){
	int h1,h2,n;
	scanf("%d %d %d",&h1,&h2,&n);
	for(int i=0;i<n;i++){
		int address;
		char data;
		int next;
		scanf("%d %c %d",&address,&data,&next);
		Node[address].add=address;
		Node[address].data=data;
		Node[address].next=next;
	}
	string a="",b="";
	int p=h1;
	while(p!=-1){
		a+=Node[p].data;
		p=Node[p].next;
	}
	p=h2;
	while(p!=-1){
		b+=Node[p].data;
		p=Node[p].next;
	}
	string t_a(a.rbegin(),a.rend());
	string t_b(b.rbegin(),b.rend());
	char com;
	if(t_a[0] != t_b[0]) 
	  com='#';
	int i=-1;
	for(i=0;i<min(t_a.length(),t_b.length());i++){
		if(t_a[i] != t_b[i])
	       break;
	}
	if(i > 0)
	  com=t_a[i-1]; 
	if(com=='#')
	 printf("-1");
	 else{
	 	p=h1;
	 	while(p!=-1){
	 		if(Node[p].data==com){
	 		   printf("%05d",Node[p].add);
	 			break;
	 		}
	 		p=Node[p].next;
	 	}
	 }
	 return 0;
} 
