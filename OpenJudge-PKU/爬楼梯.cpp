#include <iostream>
using namespace std;
int N;
int stairs(int n)
{
    if(n<0) return 0;
    if(n==0)  return 1;
    return stairs(n-1)+stairs(n-2);
}
int main()
{
    while(cin>>N){
        cout<<stairs(N)<<endl;
    }
    return 0;
}

STDIN:
5
8
10

STDOUT:
8
34
89
