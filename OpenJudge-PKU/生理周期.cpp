
#include <iostream>
#include<cstdio>
using namespace std;
#define N 21252
int main()
{
   int p,e,i,d,CaseNo=0;
   
   while(cin>>p>>e>>i>>d&&p!=-1){
       CaseNo++;
       int k;
       for(k=d+1;(k-p)%23;k++);
       for(;(k-e)%28;k+=23);
       for(;(k-i)%33;k+=23*28);
       cout<<"CaseNo"<<CaseNo<<"The triple peak occurs in"<<k-d<<"days"<<endl;
   }
   
   return 0;
}

//输入示例:
//0 0 0 0
//0 0 0 100
//5 20 34 325
//4 5 6 7
//283 102 23 320
//203 301 203 40
//-1 -1 -1 -1

//输出示例:
//CaseNo1The triple peak occurs in21252days
//CaseNo2The triple peak occurs in21152days
//CaseNo3The triple peak occurs in19575days
//CaseNo4The triple peak occurs in16994days
//CaseNo5The triple peak occurs in8910days
//CaseNo6The triple peak occurs in10789days
