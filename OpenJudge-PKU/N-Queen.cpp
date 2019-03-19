#include <iostream>
#include<cmath>
using namespace std;
int N;
int queenPos[100];
void NQueen(int k);
int main()
{
   cin>>N;
   NQueen(0);
   return 0;
}
void NQueen(int k)
{
    int i;
    if(k==N){
        for(i=0;i<N;i++)
            cout<<queenPos[i]+1<<" ";
        cout<<endl;
        return ;
    }
    for(i=0;i<N;i++){
        int j;
        for(j=0;j<k;j++){//和已摆好的K个皇后位置相比较看是否冲突
        
            if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j)){
                break;
            }
        }
        if(j==k){//当前选的位置I不冲突
        
            queenPos[k]=i;//将第K个QUEEN放在位置I
            
            NQueen(k+1);
            
        }
    }
}

STDIN:4

STDOUT:
2 4 1 3 
3 1 4 2 
