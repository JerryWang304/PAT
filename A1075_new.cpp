#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct stu	//学生结构
{
	int id;	//id
	int s[5];	//各题分数，内部从0开始编号
	int score;	//总分
	int pass;	//完全正确题目数
	int ns;	//无提交或无任何通过编译标志，0代表没有通过
	stu()	//初始化
	{
		id=0;score=0;pass=0;ns=0;
		for(int i=0;i<5;i++)
			s[i]=-2;	//由于输出要求，对没有处理过的用-2表示
	}
};

bool cm(const stu &s1,const stu &s2);	//比较

int main()
{
	int n,k,m;
	cin>>n>>k>>m;

	stu *student=new stu [n];	//学生，标号i对应真实id-1
	int p[5];	//分门分数
	
	int i,j;
	for(i=0;i<k;i++)	//输入信息
		scanf("%d",&p[i]);
	int id,p_id,ps;
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&id,&p_id,&ps);
		if(ps>student[id-1].s[p_id-1])
			student[id-1].s[p_id-1]=ps;
	}

	for(i=0;i<n;i++)	//计算总分，完全正确题目数，是否需要剔除
	{
		student[i].id=i+1;
		for(j=0;j<k;j++)
		{
			if(student[i].s[j]>=0)
			{
				student[i].score+=student[i].s[j];
				student[i].ns=1;
			}
			if(student[i].s[j]==p[j])
				student[i].pass++;
		}
	}
	stable_sort(student,student+n,cm); //稳定排序，可以免去一次id比较

	int rank=1;	//当前的名次，处理并列用
	int score=student[0].score;	//当前的分数
	for(i=0;i<n;i++)
	{
		if(student[i].ns==0)	//到达无用数据段跳出
			break;
		if(student[i].score!=score)	//不是并列，刷新分数
		{
			rank=i+1;
			score=student[i].score;
		}
		printf("%d %05d %d",rank,student[i].id,student[i].score);	//输出信息
		for(j=0;j<k;j++)
		{
			if(student[i].s[j]>=0)
				printf(" %d",student[i].s[j]);
			else if(student[i].s[j]==-1)
				printf(" 0");
			else
				printf(" -");
		}
		printf("\n");
	}

	delete [] student;

	return 0;
}

bool cm(const stu &s1,const stu &s2)	//按总分和完全正确题目数排序用比较
{
	if(s1.score>s2.score)
		return true;
	else if(s1.score==s2.score)
		return s1.pass>s2.pass;
	else
		return false;
}

