

#include <iostream>
#include<memory>
#include<string>
#include<cstring>
using namespace std;

int GetBit(char c,int i)
{
    return (c>>i)&1; //取c的第i位
}

void SetBit(char &c,int i,int v){ //设置c的第i位为v
    if(v)
       c|=(1<<i);
    else
        c&=~(1<<i);
}

void Flip(char & c,int i)
{
    //将c的第i位取反
    c^=(1<<i);
}
void OutputResult(int t,char result[])
{
    cout<<"Puzzle #"<<t<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<6;j++){
            cout<<GetBit(result[i],j);
            if(j<5)
                cout<<" ";
        }
        cout<<endl;
    }
}
int main()
{
   char oriLights[5];
   char result[5];
   char lights[5];
   char switchs;//某一行的开关状态
   int T;
   cin>>T;
   for(int t=1;t<=T;t++){
       memset(oriLights,0,sizeof(oriLights));
       for(int i=0;i<5;i++){
           for(int j=0;j<6;j++){
               int s;
               cin>>s;
               SetBit(oriLights[i],j,s);
           }
       }
       for(int n=0;n<64;n++){
           memcpy(lights,oriLights,sizeof(oriLights));
           switchs=n;
           for(int i=0;i<5;i++){
               result[i]=switchs;
               for(int j=0;j<6;j++){
                   if(GetBit(switchs,j)){
                       if(j>0)
                            
                            Flip(lights[i],j-1);
                        Flip(lights[i],j);
                        if(j<5)
                            Flip(lights[i],j+1);
                        
                   }
               }
               if(i<4)
                    lights[i+1]^=switchs;
                switchs=lights[i];
           }
           if(lights[4]==0){
               OutputResult(t,result);
               break;
           }
       }//for(int n=0;n<64;n++)
   }
   
   return 0;
}

STDIN:
2
0 1 1 0 1 0
1 0 0 1 1 1
0 0 1 0 0 1
1 0 0 1 0 1
0 1 1 1 0 0
0 0 1 0 1 0
1 0 1 0 1 1
0 0 1 0 1 1
1 0 1 1 0 0
0 1 0 1 0 0

STDOUT:
Puzzle #1
1 0 1 0 0 1
1 1 0 1 0 1
0 0 1 0 1 1
1 0 0 1 0 0
0 1 0 0 0 0
Puzzle #2
1 0 0 1 1 1
1 1 0 0 0 0
0 0 0 1 0 0
1 1 0 1 0 1
1 0 1 1 0 1
