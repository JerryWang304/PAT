#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 10010;
struct node{
	int id;
	string title;
	string author;
	set<string> keywords;
	string publisher;
	string year;
}Node[maxn];

int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>Node[i].id;
		getchar();
		getline(cin,Node[i].title);
		getline(cin,Node[i].author);
		string key;
		while(cin>>key){
			Node[i].keywords.insert(key);
			char c=getchar();
			if(c=='\n')
			  break;
		}
		getline(cin,Node[i].publisher);
	    getline(cin,Node[i].year);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int seek;
		string found;
		scanf("%d: ",&seek);
		getline(cin,found);
		int ans[maxn];
		int len_ans=0;
		if(seek==1){
			for(int j=0;j<n;j++){
				if(Node[j].title==found){
					ans[len_ans++]=Node[j].id;
				}
			}
		}else if(seek==2){
			for(int j=0;j<n;j++){
				if(Node[j].author==found){
					ans[len_ans++]=Node[j].id;
				}
			}
		}else if(seek==3){
			for(int j=0;j<n;j++){
				set<string>::iterator it=Node[j].keywords.find(found);
				if(it != Node[j].keywords.end())
				  ans[len_ans++]=Node[j].id;
			}
		}else if(seek==4){
			for(int j=0;j<n;j++){
				if(Node[j].publisher==found){
					ans[len_ans++]=Node[j].id;
				}
			}
		}else if(seek==5){
			for(int j=0;j<n;j++){
				if(Node[j].year==found){
					ans[len_ans++]=Node[j].id;
				}
			}
		}
		cout<<seek<<": "<<found<<endl;
		if(len_ans==0){
			cout<<"Not Found"<<endl;
		}else{
			sort(ans,ans+len_ans);
			for(int k=0;k<len_ans;k++)
			  printf("%07d\n",ans[k]);//不补0会出错，最后两个测试点过不了 
		}
	}
	return 0;
}
