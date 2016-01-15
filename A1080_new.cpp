#include<iostream>
#include<algorithm>
using namespace std;
const int max_stu=40010;
const int max_sch=102;

typedef struct Student{
	int e;
	int i;
	int f;
	int school[max_sch];
	int id;
	int rank;
}Student;

typedef struct School{
	int max;
	int ac;//���ܵ�����
	Student last;
	int receive_stu[max_stu];
}School;

int n,m,k;
int max_num[max_sch];

Student stu[max_stu];
School sch[max_sch];

bool cmp(Student a,Student b){
	if(a.f != b.f)
	  return a.f>b.f;
	else 
	  return a.e>b.e;
} 
bool cmp_id(int a,int b){
	return a < b;
}

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	  cin>>sch[i].max;//�����������
	for(int i=0;i<n;i++){
		cin>>stu[i].e;
		cin>>stu[i].i;
		stu[i].id=i;
		stu[i].f=stu[i].e+stu[i].i;
		for(int j=0;j<k;j++)
		  cin>>stu[i].school[j];
	}
	
	//������
	sort(stu,stu+n,cmp);
	//��������
	stu[0].rank=1;
	for(int i=1;i<n;i++){
		if(stu[i].e == stu[i-1].e && stu[i].f==stu[i-1].f)
		   stu[i].rank=stu[i-1].rank;
		else
		   stu[i].rank=i+1;
	} 
	//��n�����������η���
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int choice = stu[i].school[j];//��ǰ�����ѧУ���
			if(sch[choice].ac<sch[choice].max){
				sch[choice].receive_stu[sch[choice].ac++]=stu[i].id;//���ڣ�sch[choice].receive_stu[sch[choice].ac++]=i 
				sch[choice].last=stu[i];
				break;
			}else{
				if(sch[choice].last.rank == stu[i].rank){
				  sch[choice].receive_stu[sch[choice].ac++]=stu[i].id;//ͬ�� 
				  sch[choice].last=stu[i];
				  break;
			    }
			}
		}
	}
	for(int i=0;i<m;i++){
	   //�Խ���ѧ����id����
	   sort(sch[i].receive_stu,sch[i].receive_stu+sch[i].ac,cmp_id);
	   if(sch[i].ac==0){
	   	cout<<endl;
	   }else{
	   	for(int j=0;j<sch[i].ac;j++){
	   		if(j==0)
	   		  cout<<sch[i].receive_stu[j];
	   		else
	   		  cout<<" "<<sch[i].receive_stu[j];
	   	  }
	   	  cout<<endl;
	   }
	}
	return 0;
	
}









