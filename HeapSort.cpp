#include<iostream>
using namespace std;
//最大堆排序
//每次把最大值放到最后 
void heapfily(int a[],int i,int size){
	if(i<size){
		int left=2*i+1;
		int right=2*i+2;
		int Max=i;
		if(left<size && a[Max] < a[left]) Max= left;
		if(right<size && a[Max] < a[right]) Max=right;
		if(Max!=i){
			int temp=a[Max];
			a[Max] = a[i];
			a[i]=temp;
		}
	}
}
void all(int a[],int size){
	for(int i=size-1;i>=0;i--){
		heapfily(a,i,size);
	}
}
void heapsort(int a[],int size){
	for(int i=size-1;i>=0;i--){
		all(a,i+1);
		int temp=a[i];
		a[i]=a[0];
		a[0]=temp;
	}
}
int main(){
	int a[10]={2,7,1,3,4,8,-9,10,-98,123};
	heapsort(a,10);
	for(int i=0;i<10;i++)
	  cout<<a[i]<<" ";
	return 0;
}
