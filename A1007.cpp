//�������Ե������ ,����flag������������һ�����Ե������555~ 
#include<iostream>
using namespace std;
const int maxn=10010;
int main(){
	
	int n;
	cin>>n;
	bool flag=false;//flag=false��ʾȫΪ����������һ��Ҫ��ʼ��!
	int a[maxn];
	for(int i=0;i<n;i++){
	  cin>>a[i];
	  if(a[i]>=0)
	    flag=true;
    }
	if(flag==false)//���ȫ�Ǹ���
	{
		cout<<0<<" "<<a[0]<<" "<<a[n-1];
		return 0;
	} 
	//��������к�
	int max=0;
	int ThisSum=0;
	int first,last;
	for(int i=0;i<n;i++){
		ThisSum+=a[i];
		if(ThisSum>max){
		 max=ThisSum;
		 last=i;
	    }
		else if(ThisSum<0){
		  ThisSum=0; 
	    }
	} 
	
	int i,temp=0;
	for(i=last;i>=0;i--){
		temp=temp+a[i];
		if(temp==max)
		 break;
	}

	first=i;
	cout<<max<<" "<<a[first]<<" "<<a[last];//��������������±� 
	return 0;
}
