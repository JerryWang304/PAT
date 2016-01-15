#include<iostream>
#include<cmath>
using namespace std;
typedef struct
{
    int prime;
    int count;
}factor;
factor fac[12];

bool isPrime(int n)
{
    int k=(int)sqrt(1.0*n);
    for(int i=2; i<=k; i++)
        if(n%i==0)
            return false;
    return true;
}

int main()
{
    int n,nrofPrime=0;
    cin>>n;
    int temp_n=n;
    if(n==1)
    {
        cout<<"1:1"<<endl;
        return 0;
    }
    else
    {
        //先算sqrt(n)内的质数及其个数
        int temp=(int)sqrt(1.0*n);
        //test
        //cout<<"sqrt(1.0*n):"<<temp<<endl;
        for(int i=2; i<=temp; i++)
        {
            if(isPrime(i) && n%i==0)
            {
                fac[nrofPrime].prime=i;
                fac[nrofPrime].count=0;
                while(n%i == 0)
                {
                    n=n/i;
                    fac[nrofPrime].count++;
                }
                nrofPrime++;
                //test
                //cout<<fac[nrofPrime].prime<<":"<<fac[nrofPrime].count<<endl;
            }
        }
        //如果n>1，则说明n有大于sqrt(n)的因子
        if(n!=1)
        {
            fac[nrofPrime].prime=n;
            fac[nrofPrime++].count=1;
        }
        cout<<temp_n<<"=";
        for(int i=0; i<nrofPrime; i++)
        {
            if(fac[i].count>1)
            {
                cout<<fac[i].prime<<"^"<<fac[i].count;
                if(i != nrofPrime-1) cout<<"*";
            }
            else if(fac[i].count==1)
            {
                cout<<fac[i].prime;
                if(i != nrofPrime-1) cout<<"*";
            }
        }
    }
    return 0;

}














