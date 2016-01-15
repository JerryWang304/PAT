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

bool vis[max_stu]={false};//第i个学生已经被录取 

int main(){
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	  cin>>sch[i].max;//每个学校最大录用人数 
	for(int i=0;i<n;i++){
		cin>>stu[i].e;
		cin>>stu[i].i;
		stu[i].id=i;
		stu[i].f=(stu[i].e+stu[i].i)/2;
		//申请的学校 
		for(int z=0;z<k;z++){
		  cin>>stu[i].school[z];
		  int s=stu[i].school[z];//申请的学校的编号 
		  //sch[s].stu[sch[s].num_app++]=i;//每个学校申请的学生 
		  sch[s].stu[sch[s].num_app++]=stu[i]; 
	    }

		
	}
	//test -> 每个学校接受的学生编号统计没有错误 
//	for(int i=0;i<m;i++){
//		cout<<i<<": ";
//		for(int j=0;j<sch[i].num_app;j++)
//		 cout<<sch[i].stu[j].id<<"  ";
//		cout<<endl;
//	}
	//对每个学校申请的学生排序
	for(int i=0;i<m;i++){
		sort(sch[i].stu, sch[i].stu+sch[i].num_app,cmp);
		//test
//		cout<<i<<": ";
//		for(int j=0;j<sch[i].num_app;j++)
//		 cout<<sch[i].stu[j].id<<"  ";
//		cout<<endl;
		
		
		//更新学生排名
		sch[i].stu[0].rank=1;
		for(int j=1;j<sch[i].num_app;j++){
			if(sch[i].stu[j].e==sch[i].stu[j-1].e && sch[i].stu[j].f==sch[i].stu[j-1].f)
			  sch[i].stu[j].rank=sch[i].stu[j-1].rank;
			else
			  sch[i].stu[j].rank=j+1;
		} 
		//按排名进行排序 
		sort(sch[i].stu,sch[i].stu+sch[i].num_app,cmp_rank);
		//录用学生
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
	//按每个学生的申请优先级录用
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			int choice=stu[i].school[j];//申请的学校
			//计算本学生的排名
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
	//输出学生信息 
	for(int i=0;i<m;i++){
		//按id排名
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

