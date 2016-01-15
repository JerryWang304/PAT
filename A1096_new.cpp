#include<iostream>
#include<cmath>
using namespace std;

int a;
bool isPrime(int x){
	if(x<=1) 
		return false;
	int mid = (int)sqrt(x*1.0);
	for(int i=2;i<=mid;i++){
		if(x%i == 0)
			return false;
	}
	return true;
}

int main(){
	
	cin>>a;
	if(isPrime(a)){
		cout<<1<<endl;
		cout<<a;
		system("pause");
		return 0;
	}
	int MAX=0;
	int u=0;
	for(int i=2;i<=a;i++){
		int count = 0;
		int j=i;
		int sum = j;
		while(a%j==0){
			j++;
			count++;
			sum*=j;
		}
		if(count>MAX && (a%sum) ){
			u=i;
			MAX = count;
		}

	}
	//
	for(int i=2;i<=a;i++){
		int count = 0;
		int j=i;
		
		while(a%j==0){
			j++;
			count++;
			
		}
		if(count == MAX && i<u){
			u=i;
			break; 
		}

	}

	cout<<MAX<<endl;
	for(int i=0;i<MAX;i++){
		if(i<MAX-1)
			cout<<u++<<'*';
		else
			cout<<u++;
	}
	system("pause");
	return 0;
}
