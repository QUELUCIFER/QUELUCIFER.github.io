#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAYLEN 6
int CreateData(int arr[],int n, int min, int max)
{
    int i,j,flag;
    srand(time(NULL));
    if((max-min+1)<n)  return 0;
    for(i-0;i<n;i++)
    {
        do
        {
            //arr[i]=(max-min+1)*rand()%(RAND_MAX+1)+min;
            arr[i]=(max-min+1)*rand()%100+min;
            flag=0;
            for(j=0;j<i;j++)
            {
                if(arr[i]==arr[j])
                    flag=1;
            }
        }while(flag);
    }
    return 1;
}
void Bubble_Sort(int a[],int n)
{
    int i,j,t,flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        printf("第%2d遍:",i+1);
        for(j=0;j<n;j++)
            printf("%d",a[j]);
        printf("\n");
        if(flag==0)
            break;
        else
            flag=0;
    }
}
int main()
{
   int i,a[ARRAYLEN];
    for(i=0;i<ARRAYLEN;i++)
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))
    {
        printf("生成随机数不成功!\n");
        getchar();
        return 1;
    }
    printf("原数据:");
    for(i=0;i<ARRAYLEN;i++)
        printf("%d",a[i]);
    printf("\n");
    Bubble_Sort(a,ARRAYLEN);
    printf("排序后:");
    for(i=0;i<ARRAYLEN;i++)
        printf("%d",a[i]);
    printf("\n");
    getchar();
    return 0;
}

/*
原数据:21-2757-23-4725
第 1遍:-4721-2757-2325
第 2遍:-47-2721-235725
第 3遍:-47-27-23212557
第 4遍:-47-27-23212557
排序后:-47-27-23212557
*/
