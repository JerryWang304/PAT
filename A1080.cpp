#include<iostream>
#include<algorithm>
using namespace std;
const int max_stu=40002;
const int max_sch=101;

int max_num[max_sch];

typedef struct Student{
	int id;
	int e;
	int i;
	int f;
	int school[max_sch];
	int rank;
}Student;

typedef struct School{
	Student stu[max_stu/2];
	int num_app;
	int max;
	int ac;
	Student receive_stu[max_stu/2]; 
}School;


Student stu[max_stu];
School sch[max_sch];

bool cmp(Student a,Student b){
	if(a.f != b.f)
	  return a.f>b.f;
	else 
	  return a.e>b.e;
}

bool cmp_id(Student a,Student b){
	return a.id < b.id;
}
bool cmp_rank(Student a,Student b){
	return a.rank < b.rank;
}
int n,m,k;

bool vis[max_stu]={false};//��i��ѧ���Ѿ���¼ȡ 

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	  cin>>sch[i].max;//ÿ��ѧУ���¼������ 
	for(int i=0;i<n;i++){
		cin>>stu[i].e;
		cin>>stu[i].i;
		stu[i].id=i;
		stu[i].f=(stu[i].e+stu[i].i)/2;
		//�����ѧУ 
		for(int z=0;z<k;z++){
		  cin>>stu[i].school[z];
		  int s=stu[i].school[z];//�����ѧУ�ı�� 
		  //sch[s].stu[sch[s].num_app++]=i;//ÿ��ѧУ�����ѧ�� 
		  sch[s].stu[sch[s].num_app++]=stu[i]; 
	    }

		
	}
	//test -> ÿ��ѧУ���ܵ�ѧ�����ͳ��û�д��� 
//	for(int i=0;i<m;i++){
//		cout<<i<<": ";
//		for(int j=0;j<sch[i].num_app;j++)
//		 cout<<sch[i].stu[j].id<<"  ";
//		cout<<endl;
//	}
	//��ÿ��ѧУ�����ѧ������
	for(int i=0;i<m;i++){
		sort(sch[i].stu, sch[i].stu+sch[i].num_app,cmp);
		//test
//		cout<<i<<": ";
//		for(int j=0;j<sch[i].num_app;j++)
//		 cout<<sch[i].stu[j].id<<"  ";
//		cout<<endl;
		
		
		//����ѧ������
		sch[i].stu[0].rank=1;
		for(int j=1;j<sch[i].num_app;j++){
			if(sch[i].stu[j].e==sch[i].stu[j-1].e && sch[i].stu[j].f==sch[i].stu[j-1].f)
			  sch[i].stu[j].rank=sch[i].stu[j-1].rank;
			else
			  sch[i].stu[j].rank=j+1;
		} 
		//�������������� 
		sort(sch[i].stu,sch[i].stu+sch[i].num_app,cmp_rank);
		//¼��ѧ��
//		for(int j=0;j<sch[i].num_app;j++){
//			if(sch[i].ac<sch[i].max && vis[sch[i].stu[j].id]==false){
//				sch[i].receive_stu[sch[i].ac++]=sch[i].stu[j];
//				vis[sch[i].stu[j].id]=true;
//			}
//			else if(sch[i].ac==sch[i].max&&vis[sch[i].stu[j].id]==false){
//				Student last=sch[i].receive_stu[sch[i].ac-1];
//				while(sch[i].stu[j].rank==last.rank && vis[sch[i].stu[j].id]==false){
//					sch[i].receive_stu[sch[i].ac++]=sch[i].stu[j];
//					vis[sch[i].stu[j].id]=true;
//					j++;
//				}
//				break;
//			}
//		}
		
		 
	} 
	//��ÿ��ѧ�����������ȼ�¼��
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int choice=stu[i].school[j];//�����ѧУ
			//���㱾ѧ��������
			int r,z;
			for(z=0;z<sch[choice].num_app;z++){
				Student s=sch[choice].stu[z];
				if(s.id==stu[i].id){
					r=s.rank;
					break;
				}
			} 
			if(z<=sch[choice].max && vis[i]==false){
				sch[choice].receive_stu[sch[choice].ac++]=stu[i];
				vis[i]=true;
			}else{
				if(r==stu[sch[choice].max-1].rank && vis[i]==false){
					sch[choice].receive_stu[sch[choice].ac++]=stu[i];
					vis[i]=true;
				}
			}
			
		}
	} 
//			//test
//	for(int i=0;i<m;i++){
//		cout<<i<<": ";
//		for(int j=0;j<sch[i].num_app;j++)
//		 cout<<sch[i].stu[j].id<<"  ";
//		cout<<endl;
//	}
	//���ѧ����Ϣ 
	for(int i=0;i<m;i++){
		//��id����
		sort(sch[i].stu,sch[i].stu+sch[i].ac,cmp_id);
		if(sch[i].ac==0){
			cout<<endl;
		}else{
			for(int j=0;j<sch[i].ac;j++){
				if(j==0) 
				   cout<<sch[i].stu[j].id;
				else 
				   cout<<" "<<sch[i].stu[j].id;
			}
			cout<<endl;
		}
	}
	return 0;
}

