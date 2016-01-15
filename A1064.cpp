#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1020;
int in[maxn],n,GBT[maxn];
int k=0;
void InOrder(int now){
    if(now>n) return ;
    InOrder(now*2);
    GBT[now]=in[k++];
    InOrder(now*2+1);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
      cin>>in[i];
    sort(in,in+n);
    InOrder(1);
    for(int i=1;i<=n;i++)
     if(i==1) cout<<GBT[i];
     else cout<<" "<<GBT[i];
     return 0;
}
