#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<map>
using namespace std;

int rate[24];
int N;
const int maxn=2001;
map<string,int> m;//第i个人有多少条个记录 
map<string,double> money;
struct node{
	string name;
	string time;
	string status;
}Node[maxn];

string up(string a){
	for(int i=0;i<a.length();i++){
		if(a[i]>='a' && a[i]<='z')
		 a[i]=a[i]-'a'+'A';
	}
	return a;
}

bool cmpName(node a,node b){
	if(a.name != b.name)
	  return a.name < b.name;
	else 
	  return a.time < b.time;
}

double expense(int d1,int h1,int m1,int d2,int h2,int m2){
	int sum=0;
	for(int i=0;i<24;i++)
	  sum+=rate[i];
	double allday=0;
	allday=sum*60;
	//price+=allday*(d2-d1);

	double price=0;
	//如果是同一天
	 
	if(d1==d2){
		if(m1==0){
			h1++;
			price+=rate[h1]*60;
		}else{
			price+=rate[h1]*(60-m1);
			h1++;
		}
		while(h1<h2){
			price+=rate[h1]*60;
			h1++;
		}
		price+=rate[h2]*m2;
	}
	if(d2>d1)
	  if(h1<=h2 && m1<=m2){
		if(m1==0){
			h1++;
			price+=rate[h1]*60;
		}else{
			price+=rate[h1]*(60-m1);
			h1++;
		}
		while(h1<h2){
			price+=rate[h1]*60;
			h1++;
		}
		price+=rate[h2]*m2;
		price+=allday*(d2-d1);
		
	  }else{
		//price=allday*(d2-d1)-expense(d2,h1,m1,d2,h2,m2);
		if(h1>h2){
			price+=allday*(d2-d1-1);
			for(int i=0;i<h2;i++)
			  price+=rate[i]*60;
			price+=rate[h2]*m2;
			
			for(int i=h1+1;i<24;i++)
			  price+=rate[i]*60;
			price+=rate[h1]+(60-m1);
		}
	}
	return price;
}

int main(){
	for(int i=0;i<24;i++)
	  cin>>rate[i];
	cin>>N;//N组数据
	int nrofName=0;
	for(int i=0;i<N;i++){
		cin>>Node[i].name>>Node[i].time>>Node[i].status;
		m[Node[i].name]++; 
	}

	sort(Node,Node+N,cmpName);

//    for(int i=0;i<N;i++){
//    	cout<<Node[i].name<<" "<<m[Node[i].name]<<endl;
//       } 
//     return 0;
	int ThisLine=0;
	while(ThisLine<N){
	    int now=ThisLine;
	    //cout<<"ThisLine= "<<ThisLine<<endl;
		string ThisName=Node[ThisLine].name;
		string time=Node[ThisLine].time;
		//cout<<ThisLine<<endl;
		cout<<ThisName<<" ";
		int month=(time[0]-'0') * 10 + (time[1]-'0');
		printf("%02d\n",month);

		while(now<=ThisLine+m[ThisName]-1){
			//cout<<"now= "<<now<<endl;
			if(Node[now].status=="on-line" && Node[now+1].status=="off-line"){
				string start=Node[now].time.substr(3);
				string end = Node[now+1].time.substr(3);
				cout<<start<<" "<<end<<" ";
				int lastTime=0;
				int d1=0,h1=0,m1=0;
				d1=(start[0]-'0')*10+(start[1]-'0');
				h1=(start[3]-'0')*10+(start[4]-'0');
				m1=(start[6]-'0')*10+(start[7]-'0');
				int d2=0,h2=0,m2=0;
				d2=(end[0]-'0')*10+(end[1]-'0');
				h2=(end[3]-'0')*10+(end[4]-'0');
				m2=(end[6]-'0')*10+(end[7]-'0');
				lastTime=d2*24*60+h2*60+m2-(d1*24*60+h1*60+m1);
				cout<<lastTime<<" ";
				double price=0;
                price=expense(d1,h1,m1,d2,h2,m2);
				printf("$%.02lf\n",price/100.0);
				money[ThisName]+=price/100.0;
			}
			now++;
		}
		
		cout<<"Total amount: ";
		printf("$%.02lf\n",money[ThisName]);
		ThisLine+=m[ThisName]; 
	  }

	return 0;
}




