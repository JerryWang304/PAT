#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100100;
int pos[maxn];
int n;
int main(){
	cin>>n;
	int num;
	int left=n-1;//除了0以外，没有在位置上的元素的个数 
	for(int i=0;i<n;i++){
		cin>>num;
		pos[num]=i;
		if(pos[num] == num && num != 0)
		  left--;
	}
	int step=0;
	int k=1;//没有这个会超时 
	while(left>0){
		if(pos[0] == 0){
			int u=-1;
			for(int i=k;i<n;i++){
				if(pos[i] != i){
					u=i;
					k=i;//k之前的都满足pos[k]==k,所以下次遍历可以直接跳过k之前的数字 
					break;
				}
			}
			swap(pos[0],pos[u]);
			step++;
			
		}
		while(pos[0] != 0){
			swap(pos[0],pos[pos[0]]);
			step++;
			left--;
		}
	}
	cout<<step;
	return 0;
}






