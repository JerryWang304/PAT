#include<iostream>
#include<stack>
using namespace std;
stack<int> s;

int a[]={3,4,2,5,1},k=0;

int main(){
	int j=0;
	
	while(j<5){
		while(s.empty() || s.top() != a[j]){
			s.push(++k);
			if(k>5){
				cout<<"NO\n";
				return 0;
			}
		}
		while(s.top() == a[j]){
			j++;
			s.pop();
		}
		
	}
	if(s.empty())
		cout<<"Yes";
	system("pause");
	return 0;
}
