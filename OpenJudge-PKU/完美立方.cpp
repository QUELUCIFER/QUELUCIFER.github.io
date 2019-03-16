#include <iostream>
#include<cstdio>
using namespace std;

int main()
{
   int N;
   scanf("%d",&N);
    for(int a=2;a<=N;a++)
        for(int b=2;b<a;b++)
            for(int c=b;c<a;c++)
                for(int d=c;d<a;d++)
                    if(a*a*a==b*b*b+c*c*c+d*d*d){
                        printf("Cube=%d,Triple=(%d,%d,%d)\n",a,b,c,d);
                    }
   
   
   
   return 0;
}

输入示例:24
输出示例:
Cube=6,Triple=(3,4,5)
Cube=12,Triple=(6,8,10)
Cube=18,Triple=(2,12,16)
Cube=18,Triple=(9,12,15)
Cube=19,Triple=(3,10,18)
Cube=20,Triple=(7,14,17)
Cube=24,Triple=(12,16,20)
