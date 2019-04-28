#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAYLEN 10
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
int Division(int a[],int left,int right)
{
    int base=a[left];
    while(left<right)
    {
        while(left<right&&a[right]>base)
        {
            --right;
        }
        a[left]=a[right];
        while(left<right&&a[left]<base)
        {
            ++left;
        }
        a[right]=a[left];
    }
    a[left]=base;
    return left;
}
void Quick_Sort(int a[],int left,int right)
{
    int i,j;
    if(left<right)
    {
        i=Division(a,left,right);
        Quick_Sort(a,left,i-1);
        Quick_Sort(a,i,right);
    }
    return ;
}
int main()
{
    int i,a[ARRAYLEN];
    for(i=0;i<ARRAYLEN;i++)
    {
        a[i]=0;
    }
    if(!CreateData(a,ARRAYLEN,1,100))
    {
        printf("生成随机数不成功！\n");
        getchar();
        return 1;
    }
    printf("原数据:");
    for(i=0;i<ARRAYLEN;i++)
        printf("%d",a[i]);
    printf("\n");
    Quick_Sort(a,0,ARRAYLEN-1);
    printf("排序后:");
    for(i=0;i<ARRAYLEN;i++)
        printf("%d",a[i]);
    printf("\n");
    getchar();
    return 0;
}
