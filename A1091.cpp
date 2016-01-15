#include<cstdio>
#include<queue>
using namespace std;

struct node{
	int x,y,z;
}Node;

int pixel[1300][140][100];

bool vis[1300][130][100]={false};
int m,n,slice,T;//m*n

bool legal(int x,int y,int z){
	if(x>=m || x<0 || y>=n || y<0 || z>=slice || z<0)
	  return false;//���Ҫ������ǰ�棡���������� 
	if(vis[x][y][z])
	  return false;
	if(pixel[x][y][z]==0)
	  return false;
	return true;
} 
int newZ[6]={1,-1,0,0,0,0};
int newY[6]={0,0,1,-1,0,0};
int newX[6]={0,0,0,0,1,-1};
//��(x,y,z)������������� 
int BFS(int x,int y,int z){
	int total=0;
	queue<node> q;

	Node.x=x;Node.y=y;Node.z=z;
    q.push(Node);	
    vis[x][y][z]=true;
	while(!q.empty()){
		node top=q.front();
		q.pop();
		total++;//ÿ�η��ʶ��׵�Ԫ��ʱ��һ����Ϊֻ�����ŵĿ������� 
		int X,Y,Z;
		//�Ӷ��׽ڵ㿪ʼ�����ν����������ĵ�ӵ��������� 
		for(int i=0;i<6;i++){
			X=top.x+newX[i];
			Y=top.y+newY[i];
			Z=top.z+newZ[i];
			if(legal(X,Y,Z)){
			   	  Node.x=X;
				  Node.y=Y;
				  Node.z=Z;
			   	  q.push(Node);
			   	  vis[X][Y][Z]=true;
		    }
		} 
	}
	if(total>=T)
	 return total;
	else
	 return 0;
}
int main(){
	scanf("%d %d %d %d",&m,&n,&slice,&T);//֮ǰ�ٴ��˸�%d�����˰������������Ҳ������ 
	for(int i=0;i<slice;i++){
		for(int j=0;j<m;j++){
			for(int z=0;z<n;z++)
			  scanf("%d",&pixel[j][z][i]);
		}
	}
	int ans=0;
	for(int i=0;i<slice;i++){
    	for(int j=0;j<m;j++){
	    	for(int z=0;z<n;z++)
		      if(pixel[j][z][i]==1 && !vis[j][z][i])
			    ans+=BFS(j,z,i);
	   	}
	}
	printf("%d\n",ans);
	return 0;
} 
