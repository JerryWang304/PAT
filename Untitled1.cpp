#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define Z 8      //
#define R 6     // R ��ʾ����Ա����
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
	system("cls"); //��������
	printf("\n\n");
	printf("\t       ���˵�     \n");
	printf("  1.��������ÿ��ÿ�ֲ�Ʒ�����۶�\n");
	printf("  2.�����۶������Ա�����������������\n");
	printf("  3.ͳ��ÿ�ֲ�Ʒ�������۶���������\n");
	printf("  4.���ͳ�Ʊ���\n");
	printf("  5.��������\n");
}
void f1(data*x)    //�����ϸ���ÿ����ÿ�ֲ�Ʒ�����۶�
{
	FILE*fp;
	char fname[10],hitkey;
	int j,t;  //����ѭ����
	int i,k,s;   //���ڶ���Ա����ţ���Ʒ��ţ���Ʒ����
	system("cls");
	printf("�����������·�\n");
	printf("�������·�\n");
	scanf("%s",fname);
	strcat(fname, ".dat");
	if((fp=fopen(fname,"w"))==NULL)    //���ļ�
	{
		printf("���ܴ��ļ�!!\n");
		exit(0);
	}
	for(j=0;j<R;j++)   //����Ʒ��������
		for(t=0;t<Z;t++)
			(x+j)->product[t]=0;
		printf("������:\nԱ����� ��Ʒ��� ��������\n");  //��ʾ�û�������Ϣ��ʽ
		for(j=0;hitkey!=27;j++)
		{ scanf("%d%d%d",&i,&k,&s);

		if (i>R||i<0||k>Z||k<0)
		{  printf("��Ϣ����\n");
		continue;
		}
		else
			(x+i-1)->product[k-1]=(x+i-1)->product[k-1]+s;//ͳ�Ƹ����˵Ĳ�Ʒ������-1 Ϊ�˺�����������Ӧ
		printf("�������밴�س������������밴esc\n");
		printf("______________________________\n");
		hitkey=getch();
		}
		for(j=0;j<R;j++)
			if(fwrite((x+j),sizeof(data),1,fp)!=1)//����Ϣд���ļ�
				printf("write error!\n");
			fclose(fp);
			printf("\n\n\n\n\n����ɹ���������������ϼ��˵�!\n");
			getch();
}

void f2(data *x)  /*�����۶������Ա�����������������*/
{
	FILE *fp;
	char fname[10];
	int i,k,j,t,number[R]={0},z; //i��Ա����ţ�k�ǲ�Ʒ��ţ�j��

	system("cls") ;/*��������*/
	printf("��Ҫ�ĸ��·ݵģ�\n");
	printf("�������·�\n"); /*�����ļ������������Խ��и����·���Ϣ����*/
	scanf("%s",fname);
	strcat(fname,".dat");\
		if((fp=fopen(fname,"rb"))==NULL)  /*���ļ�*/
		{
			printf("���ܴ��ļ���\n");
			exit(0);
		}
		for(i=0;i<R;i++)  /*������Ϣ*/
			if(fread(x+i,sizeof(data),1,fp)!=1)
				printf("������Ϣ����\n"); /*������Ϣ��ʾ*/
			for(i=0;i<R;) /*���ڴ洢ְ�����*/
				number[i]=i++;
			printf("�����밴���ֲ�Ʒ����\n");
			scanf("%d",&k);
			k=k-1;/*������ṹ���е�����ֵ��Ӧ*/
			for(i=0;i<R;i++) /*��K�ֲ�Ʒ������Ա����ѡ������*/
			{
				t=i;
				for(j=i+1;j<R;j++)
					if((x+number[t])->product[k]<(x+number[j])->product[k])/*����ְ�����Զ�Ӧ�Ľṹ���ڵĲ�Ʒ����*/
						t=j;
					if(t!=j)
					{
						z=number[i];
						number[i]=number[t];
						number[t]=z;
					}
			}
			printf("\t\t\t��%d��Ʒ������Ա����Ϊ��\n",k+1);
			printf("------------------------------------------\n");
			for(i=0;i<R;i++)
				printf("\t\t\t��%d���ǣ� Ա��%d\n",i+1,number[i]+1);
			getch();
			fclose(fp);/*�رն�����ļ�*/
}



void f3(data *x)                     /*ͳ��ÿ�ֲ�Ʒ�������۶���������*/
{
	FILE *fp;
	char fname[10];
	int i,j,sum[Z]={0},number[Z]={0},z,t,k;
	system("cls");                        /*��������*/
	printf("��������ĸ��µģ�\n");
	printf("�������·ݣ�\n");             /*�����ļ������������Խ��и����·���Ϣ����*/
	scanf("%s",fname);
	strcat(fname,".dat");
	if((fp=fopen(fname,"rb"))==NULL)         /*���ļ�*/
	{    printf("���ܴ��ļ�!\n");
	exit(0);
	}
	for(i=0;i<R;i++)                       /*������Ϣ*/
		if(fread(x+i,sizeof(data),1,fp)!=1)
			printf("������Ϣ����\n");
		for(i=0;i<Z;i++)                       /*�Ը�����Ʒ�������*/
			for(j=0;j<R;j++)
				sum[i]=sum[i]+(x+j)->product[i];
			for(i=0;i<Z;)                          /*���ڴ洢��Ʒ���*/
				number[i]=i++;
			for(i=0;i<Z;i++)
				printf("%3d",number[i]);
			for(i=0;i<Z;i++)                        /*�Բ�Ʒ�Ӹߵ�������ѡ�������㷨*/
			{  t=i;
			for(j=i+1;j<Z;j++)                  /*��Ʒ�仯ʱ����Ʒ���������֮�仯���������*/
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
			printf("�����Ʒ����\n");
			printf("��Ʒ���  ����\n");
			printf("----------------\n");
			for(i=0;i<Z;i++)
				printf(" ��Ʒ% 4d% 1d\n",number[i]+1,sum[i]);
			printf("\n\n\n\t\t\t������������ϲ˵�!");
			getch();
			fclose(fp);
}                                   /*�رն�����ļ�*/
void f4(data *x)                               /*���ͳ�Ʊ���*/
{    FILE *fp;
char fname[10];
int i,j,sum[Z+1]={0};
system("cls");
printf("��������ĸ��£�\n");  /*ʵΪ����һ���ļ������Ա���и����·ݵ���Ϣ����*/
printf("�������·�\n");
scanf("%s",fname);
strcat(fname, ".dat");
if((fp=fopen(fname,"rb"))==NULL)           /*���ļ�*/
{    printf("���ܴ��ļ�������\n");
exit(0);
}
for(i=0;i<R;i++)
if(fread(x+i,sizeof(data),1,fp)!=1)                              /*������Ϣ*/
printf("������Ϣ����");
for(i=0;i<Z;i++)                                            /*�Ը�����Ʒ���*/
for(j=0;j<R;j++)
sum[i]=sum[i]+(x+j)->product[i];
for(i=0;i<Z;i++)                                                 /*����Ʒ�ܺ�*/
sum[Z]=sum[Z]+sum[i];
printf("____________________________\n");
printf("���ͳ�Ʊ������£�\n");                     /*��Ҫ�����ͳ�Ʊ�*/
printf("����Ա����  ��Ʒ����  ����֮��\n");
for(i=0;i<R;i++)
for(j=0;j<Z;j++)
printf("Ա��%-8d��Ʒ%-6d����%-10d\n",i+1,j+1,(x+i)->product[j]);
printf("__________________�ܺ�_______________________\n");
for(i=0;i<Z;i++)
{
	if(i==0)
		printf("��Ʒ%d֮��  %-10d  %\n",i+1,sum[i],sum[Z]);
	else
		printf("��Ʒ%d֮��  %-10d\n",i+1,sum[i]);
}
printf("\n\n\n\t\t\t ��������������˵�");
getch();
}
void main()
{
	int i,choice;
	data sxy[R];                              /*R��ʾԱ���ĸ�����ǰ��ĺ곣��*/
	printf("\n\n\n\n\n\n\t--------------------------------------------\n");
	printf("\t            ��ӭ������Ʒ����ϵͳ��       \n");
	printf("\t___________________________________________\n");
	printf("\n\n\t\t\t��������������˵�\n");
	getch();
	for(i=0;;i++)
	{
		system("cls");                                              /*��������*/
		menu();                                     /*���˵�������ʾ�û�����ѡ��*/
		printf("������ʲô��\n");
		printf("��ѡ��\n");                                     /*����Ҫ���еĲ���*/
		scanf("%d",&choice);
		if(choice==5)//
		{
			system("cls");
			printf("%\n\n\n\n___________________________\n");
			printf("\t____��ӭʹ����Ʒ����ϵͳ��_____\n");
			printf("_________________________\n");
			printf("\n\n\n\t\t\t��������˳�\n");
			getch();
			break;
		}
		else
			switch(choice)
		{ case 1:f1(sxy);break;//��������ÿ��ÿ�ֲ�Ʒ������
 case 2:f2(sxy);break;//�����۶������Ա����������������򣬲����������
 case 3:f3(sxy);break;//ͳ��ÿ�ֲ�Ʒ���ܹ����۶�������������
 case 4:f4(sxy);break;//���ͳ�Ʊ���
		}
	}
}
