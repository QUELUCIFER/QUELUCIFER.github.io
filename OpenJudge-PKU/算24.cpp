
#include <iostream>
#include<cmath>
using namespace std;
double a[5];
#define EPS 1e-6
bool iszero(double x)
{
    return fabs(x)<=EPS;
}
bool count24(double a[],int n)
{
    if(n==1){
        if(iszero(a[0]-24))
            return true;
        else 
            return false;
    }
    double b[5];
    for(int i=0;i<n-1;++i)
        for(int j=i+1;j<n;++j){//枚举两个数的组合
            int m=0;//还剩m个数
            for(int k=0;k<n;++k)
                if(k!=i&&k!=j)
                    b[m++]=a[k];//将其余数放入b
            b[m]=a[i]+a[j];
            if(count24(b,m+1))
                return true;
            b[m]=a[i]-a[j];
            if(count24(b,m+1))
                return true;
            b[m]=a[j]-a[i];
            if(count24(b,m+1))
                return true;
            b[m]=a[i]*a[j];
            if(count24(b,m+1))
                return true;
            if(!iszero(a[j])){
                b[m]=a[i]/a[j];
                if(count24(b,m+1))
                    return true;
            }
            if(!iszero(a[i])){
                b[m]=a[j]/a[i];
                if(count24(b,m+1))
                    return true;
            }
            
        }
        return false;
}
int main()
{
    while(true){
        for(int i=0;i<4;++i)
            cin>>a[i];
        if(iszero(a[0]))  break;
        if(count24(a,4)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

STDIN:
5 5 5 1
1 1 4 2
0 0 0 0

STDOUT:
YES
NO
