#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int n,m,k;
const int maxn = 1010;
int a[maxn];
int main(){
	cin>>m>>n>>k;
	while(k--){
		while(!s.empty())
		    s.pop();
		int cur=1;
		bool flag = true;
		for(int i=0;i<n;i++){
			int now;
			cin>>now;
			while(s.empty() || s.top() != now){
				s.push(cur);
				
				if(s.size()>m){
					flag=false;
					break;
				}
				
				cur++;
			}
			if(s.top() == now){
				s.pop();				
			}			
		}		
		if(flag)
		   cout<<"YES\n";
		else 
		   cout<<"NO\n";
	}
	system("pause");
	return 0;
}
