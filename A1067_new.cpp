#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=100100;
int pos[maxn];
int n;
int main(){
	cin>>n;
	int num;
	int left=n-1;//����0���⣬û����λ���ϵ�Ԫ�صĸ��� 
	for(int i=0;i<n;i++){
		cin>>num;
		pos[num]=i;
		if(pos[num] == num && num != 0)
		  left--;
	}
	int step=0;
	int k=1;//û������ᳬʱ 
	while(left>0){
		if(pos[0] == 0){
			int u=-1;
			for(int i=k;i<n;i++){
				if(pos[i] != i){
					u=i;
					k=i;//k֮ǰ�Ķ�����pos[k]==k,�����´α�������ֱ������k֮ǰ������ 
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






