#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define Z 8      //
#define R 6     // R 表示销售员个数
typedef struct
{
  int product[Z];
}data;
void menu();
void f1(data *x);
void f2(data *x);
void f3(data *x);
void f4(data *x);
void menu()
{
	system("cls"); //清屏命令
	printf("\n\n");
	printf("\t       主菜单     \n");
	printf("  1.计算上月每人每种产品的销售额\n");
	printf("  2.按销售额对销售员进行排序，输出排序结果\n");
	printf("  3.统计每种产品的总销售额，输出排序结果\n");
	printf("  4.输出统计报表\n");
	printf("  5.结束操作\n");
}
void f1(data*x)    //计算上个月每个人每种产品的销售额
{
	FILE*fp;
	char fname[10],hitkey;
	int j,t;  //用于循环体
	int i,k,s;   //用于定义员工序号，产品序号，产品数量
	system("cls");
	printf("输入想计算的月份\n");
	printf("请输入月份\n");
	scanf("%s",fname);
	strcat(fname, ".dat");
	if((fp=fopen(fname,"w"))==NULL)    //打开文件
	{
		printf("不能打开文件!!\n");
		exit(0);
	}
	for(j=0;j<R;j++)   //对商品数量清零
		for(t=0;t<Z;t++)
			(x+j)->product[t]=0;
		printf("请输入:\n员工序号 产品序号 销售数量\n");  //提示用户输入信息格式
		for(j=0;hitkey!=27;j++)
		{ scanf("%d%d%d",&i,&k,&s);

		if (i>R||i<0||k>Z||k<0)
		{  printf("信息错误！\n");
		continue;
		}
		else
			(x+i-1)->product[k-1]=(x+i-1)->product[k-1]+s;//统计各个人的产品数量，-1 为了和数组序号相对应
		printf("继续输入按回车，结束输入请按esc\n");
		printf("______________________________\n");
		hitkey=getch();
		}
		for(j=0;j<R;j++)
			if(fwrite((x+j),sizeof(data),1,fp)!=1)//把信息写入文件
				printf("write error!\n");
			fclose(fp);
			printf("\n\n\n\n\n保存成功，按任意键返回上级菜单!\n");
			getch();
}

void f2(data *x)  /*按销售额对销售员进行排序，输出排序结果*/
{
	FILE *fp;
	char fname[10];
	int i,k,j,t,number[R]={0},z; //i是员工序号，k是产品序号，j是

	system("cls") ;/*清屏命令*/
	printf("你要哪个月份的？\n");
	printf("请输入月份\n"); /*输入文件名，这样可以进行各个月份信息读入*/
	scanf("%s",fname);
	strcat(fname,".dat");\
		if((fp=fopen(fname,"rb"))==NULL)  /*打开文件*/
		{
			printf("不能打开文件！\n");
			exit(0);
		}
		for(i=0;i<R;i++)  /*读出信息*/
			if(fread(x+i,sizeof(data),1,fp)!=1)
				printf("读入信息出错！\n"); /*读入信息提示*/
			for(i=0;i<R;) /*用于存储职工编号*/
				number[i]=i++;
			printf("请输入按何种产品排序\n");
			scanf("%d",&k);
			k=k-1;/*便于与结构体中的数组值对应*/
			for(i=0;i<R;i++) /*按K种产品对销售员排序，选择排序法*/
			{
				t=i;
				for(j=i+1;j<R;j++)
					if((x+number[t])->product[k]<(x+number[j])->product[k])/*调用职工各自对应的结构体内的产品数量*/
						t=j;
					if(t!=j)
					{
						z=number[i];
						number[i]=number[t];
						number[t]=z;
					}
			}
			printf("\t\t\t按%d产品对销售员排序为：\n",k+1);
			printf("------------------------------------------\n");
			for(i=0;i<R;i++)
				printf("\t\t\t第%d名是： 员工%d\n",i+1,number[i]+1);
			getch();
			fclose(fp);/*关闭读入的文件*/
}



void f3(data *x)                     /*统计每种产品的总销售额，输出排序结果*/
{
	FILE *fp;
	char fname[10];
	int i,j,sum[Z]={0},number[Z]={0},z,t,k;
	system("cls");                        /*清屏命令*/
	printf("您想计算哪个月的？\n");
	printf("请输入月份：\n");             /*输入文件名，这样可以进行各个月份信息读入*/
	scanf("%s",fname);
	strcat(fname,".dat");
	if((fp=fopen(fname,"rb"))==NULL)         /*打开文件*/
	{    printf("不能打开文件!\n");
	exit(0);
	}
	for(i=0;i<R;i++)                       /*读出信息*/
		if(fread(x+i,sizeof(data),1,fp)!=1)
			printf("读入信息出错！\n");
		for(i=0;i<Z;i++)                       /*对各种商品进行求和*/
			for(j=0;j<R;j++)
				sum[i]=sum[i]+(x+j)->product[i];
			for(i=0;i<Z;)                          /*用于存储商品编号*/
				number[i]=i++;
			for(i=0;i<Z;i++)
				printf("%3d",number[i]);
			for(i=0;i<Z;i++)                        /*对产品从高到低排序选择排序算法*/
			{  t=i;
			for(j=i+1;j<Z;j++)                  /*产品变化时，产品编号有人随之变化，便于输出*/
				if(sum[t]<sum[j])
					t=j;
				if(t!=i)
				{   k=sum[i];
				sum[i]=sum[t];
				sum[t]=k;
				z=number[i];
				number[i]=number[t];
				number[t]=z;
				}
			}
			printf("输出产品排序\n");
			printf("产品编号  数量\n");
			printf("----------------\n");
			for(i=0;i<Z;i++)
				printf(" 产品% 4d% 1d\n",number[i]+1,sum[i]);
			printf("\n\n\n\t\t\t按任意键返回上菜单!");
			getch();
			fclose(fp);
}                                   /*关闭读入的文件*/
void f4(data *x)                               /*输出统计报表*/
{    FILE *fp;
char fname[10];
int i,j,sum[Z+1]={0};
system("cls");
printf("您想计算哪个月？\n");  /*实为输入一个文件名，以便进行各个月份的信息输入*/
printf("请输入月份\n");
scanf("%s",fname);
strcat(fname, ".dat");
if((fp=fopen(fname,"rb"))==NULL)           /*打开文件*/
{    printf("不能打开文件！！！\n");
exit(0);
}
for(i=0;i<R;i++)
if(fread(x+i,sizeof(data),1,fp)!=1)                              /*读出信息*/
printf("读入信息出错！");
for(i=0;i<Z;i++)                                            /*对各种商品求和*/
for(j=0;j<R;j++)
sum[i]=sum[i]+(x+j)->product[i];
for(i=0;i<Z;i++)                                                 /*求商品总和*/
sum[Z]=sum[Z]+sum[i];
printf("____________________________\n");
printf("输出统计报表如下：\n");                     /*按要求输出统计表*/
printf("销售员代号  产品代号  销售之和\n");
for(i=0;i<R;i++)
for(j=0;j<Z;j++)
printf("员工%-8d产品%-6d数量%-10d\n",i+1,j+1,(x+i)->product[j]);
printf("__________________总和_______________________\n");
for(i=0;i<Z;i++)
{
	if(i==0)
		printf("产品%d之和  %-10d  %\n",i+1,sum[i],sum[Z]);
	else
		printf("产品%d之和  %-10d\n",i+1,sum[i]);
}
printf("\n\n\n\t\t\t 按任意键返回主菜单");
getch();
}
void main()
{
	int i,choice;
	data sxy[R];                              /*R表示员工的个数，前面的宏常量*/
	printf("\n\n\n\n\n\n\t--------------------------------------------\n");
	printf("\t            欢迎进入商品销售系统！       \n");
	printf("\t___________________________________________\n");
	printf("\n\n\t\t\t按任意键进入主菜单\n");
	getch();
	for(i=0;;i++)
	{
		system("cls");                                              /*清屏命令*/
		menu();                                     /*主菜单函数提示用户怎样选择*/
		printf("你想做什么？\n");
		printf("请选择：\n");                                     /*输入要进行的操作*/
		scanf("%d",&choice);
		if(choice==5)//
		{
			system("cls");
			printf("%\n\n\n\n___________________________\n");
			printf("\t____欢迎使用商品销售系统！_____\n");
			printf("_________________________\n");
			printf("\n\n\n\t\t\t按任意键退出\n");
			getch();
			break;
		}
		else
			switch(choice)
		{ case 1:f1(sxy);break;//计算上月每人每种产品的销售
 case 2:f2(sxy);break;//按销售额对销售员的销售情况进行排序，并输出排序结果
 case 3:f3(sxy);break;//统计每种产品的总共销售额，并且输出排序结果
 case 4:f4(sxy);break;//输出统计报表
		}
	}
}
