#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=  100100;
int a[maxn],b[maxn];
int n;
int main(){
	cin>>n;
	int zero=0;//zero是0的下标 
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0)
		  zero=i;
		b[a[i]]=i;
	}
	int step=0; 
	while(zero != 0){
		//a[zero] 与 a[b[zero]]值互换
		swap(a[zero],a[b[zero]]);
		step++; 
		int temp=zero;
		zero = b[zero];
		b[temp] = temp;
		b[0]=zero;
	}
	int u=-1;
	for(int i=0;i<n;i++){
		if(a[i] != i){
			u=i;
			break;
		}
	}
	if(u==-1){
		cout<<step;
		return 0;
	}else{
		zero=u;
		b[0]=zero;
		b[a[u]]=0;
		//0与a[u]互换
		//cout<<"a[u]="<<a[u]<<endl;
		//cout<<"u = "<<u<<endl;
		swap(a[0],a[u]);
		step++;
		
		//cout<<b[a[u]]<<endl;
		while(zero != 0){
		    //cout<<"zero = "<<zero<<" b[5]="<<b[5]<<endl;		
			//a[zero] 与 a[b[zero]]值互换
			swap(a[zero],a[b[zero]]);
			step++; 
			int temp=zero;
			zero = b[zero];
			b[temp] = temp;
			b[0]=zero;
			
	    }
//	    for(int i=0;i<n;i++)
//	      cout<<"a["<<i<<"] = "<<a[i]<<endl;
//	    cout<<endl;
//	    for(int i=0;i<n;i++){
//	    	int z=a[i];
//	    	cout<<"b["<<z<<"] = "<<b[z]<<endl;
//	    }
	}
	cout<<step;
	return 0;
}
