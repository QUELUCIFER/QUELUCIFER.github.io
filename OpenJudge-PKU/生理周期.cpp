
#include <iostream>
#include<cstdio>
using namespace std;
#define N 21252
int main()
{
   int p,e,i,d,CaseNo=0;
   while(cin>>p>>e>>i&&p!=-1){
    CaseNo++;
    int k;
    for(k=d+1;(k-p)%23;k++)
    for(;(k-e)%28;k+=23);
    for(;(k-i)%33;k+=23*28);
    cout<<"Case"<<CaseNo<<":the next triple peak occurs in"<<k-d<<"days"<<endl;
    
   }
   return 0;
}
