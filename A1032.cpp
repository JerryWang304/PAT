#include<cstdio>
#include<iostream>
using namespace std;

typedef struct n
{
    char ch;
    int next;
    bool flag;

}Node;

Node node[100010];//node[i]£¬i´ú±íµØÖ·

int main()
{
    int i,N,h1,h2;

    for(i=0;i<10010;i++)
     node[i].flag=false;

    cin>>h1>>h2>>N;
    int s1;char c;int s2;

    for(i=0;i<N;i++)
    {
        cin>>s1>>c>>s2;
        node[s1].ch=c;
        node[s1].next=s2;
    }
    int p;

    for(p=h1;p!=-1;p=node[p].next)
        node[p].flag=true;

    for(p=h2;p!=-1;p=node[p].next)
    {
        if(node[p].flag==true)
         break;
    }

    if(p != -1)
      printf("%05d",p);
    else
      printf("-1");
    return 0;

}
