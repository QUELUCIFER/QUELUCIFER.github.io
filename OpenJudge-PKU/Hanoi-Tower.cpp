#include <iostream>

using namespace std;

void Hanoi(int n,char src,char mid,char dest,int src_n)
{
   if(n==1){
        cout << src_n<<":"<<src<<"->"<<dest << endl; 
        return;
   }
    
    Hanoi(n-1,src,dest,mid,src_n);
    cout<<src_n<<":"<<src<<"->"<<dest<<endl;
    Hanoi(n-1,mid,src,dest,src_n);
    return;
}

int main()
{
   int n;
   char a,b,c;
   cin>>n>>a>>b>>c;
   Hanoi(n,a,b,c,1);
   
   return 0;
}

STDIN:3 A B C

STDOUT:
1:A->C
1:A->B
1:C->B
1:A->C
1:B->A
1:B->C
1:A->C
