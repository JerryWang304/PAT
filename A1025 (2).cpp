#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef struct
{
    char id[20];
    int final_rank;
    int location_number;
    int local_rank;
    int score;
}Stu;
Stu stu[30002];
bool cmp_all(Stu s1,Stu s2)
{
    if(s1.score != s2.score)
    return s1.score>s2.score;
    else
    return strcmp(s1.id,s2.id)<0;
}
int main()
{
    int N,K,i,j,total=0;
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>K;
        for(j=0;j<K;j++)
        {
           cin>>stu[total].id>>stu[total].score;
           stu[total].location_number=i;
           total++;
        }
          //读完一组了，计算第i组内的排名
          sort(stu+total-K,stu+total,cmp_all);
          //写入local_rank
          stu[total-K].local_rank=1;
          int m=2;
          for(j=total-K+1;j<total;j++,m++)
          {
              if(stu[j].score==stu[j-1].score)
              stu[j].local_rank=stu[j-1].local_rank;
              else stu[j].local_rank=m;

          }
    }

    //test
    cout<<"test:"<<endl;
        for(i=0;i<total;i++)
    {
        cout<<stu[i].id<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<" "<<endl;
    }
    cout<<'\n';
    //先算总排名
    sort(stu,stu+total,cmp_all);
    //写入final_rank
    stu[0].final_rank=1;
    for(i=1;i<total;i++)
    {
        if(stu[i].score == stu[i-1].score)
          stu[i].final_rank=stu[i-1].final_rank;
        else stu[i].final_rank=i+1;
    }
    //全部输出
    for(i=0;i<total;i++)
    {
        cout<<stu[i].id<<" "<<stu[i].final_rank<<" "<<stu[i].location_number<<" "<<stu[i].local_rank<<" \n";
    }
    return 0;

}

