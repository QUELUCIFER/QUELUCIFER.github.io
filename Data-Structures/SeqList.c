#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
typedef struct
{
    char key[15];
    char name[20];
    int age;
}DATA;
typedef struct
{
    DATA ListData[MAXSIZE+1];
    int ListLen;
}SeqListType;
void SeqListInit(SeqListType *SL);
int SeqListLength(SeqListType *Sl);
int SeqListAdd(SeqListType * SL,DATA data);
int SeqListInsert(SeqListType *SL,int n,DATA data);
int SeqListDelete(SeqListType *SL,int n);
DATA *SeqListFindByNum(SeqListType *SL,int n);
int SeqListFindByCont(SeqListType *SL,char *key);
int SeqListAll(SeqListType *SL);

void SeqListInit(SeqListType *SL)
{
    SL->ListLen=0;
}

int SeqListLength(SeqListType *SL)
{
    return (SL->ListLen);
}

int SeqListAdd(SeqListType *SL,DATA data)
{
    if(SL->ListLen>=MAXSIZE)
    {
        printf("顺序表已满，不能再添加节点了！\n");
        return 0;
    }
    SL->ListData[++SL->ListLen]=data;
    return 1;
}

int SeqListInsert(SeqListType *SL,int n,DATA data)
{
    int i;
    if(SL->ListLen>=MAXSIZE)
    {
        printf("顺序表已满，不能插入节点!");
        return 0;
    }
    if(n<1 || n>SL->ListLen-1)
    {
        printf("插入节点序号错误，不能插入元素！\n");
        return 0;
    }
    for(i=SL->ListLen;i>=n;i--)
    {
        SL->ListData[i+1]=SL->ListData[i];
    }
    SL->ListData[n]=data;
    SL->ListLen++;
    return 1;
}

int SeqListDelete(SeqListType *SL,int n)
{
    int i;
    if(n<1 || n>SL->ListLen+1)
    {
        printf("删除节点序号错误，不能删除节点！\n");
        return 0;
    }
    for(i=n;i<SL->ListLen;i++)
    {
        SL->ListData[i]=SL->ListData[i+1];
    }
    SL->ListLen--;
    return 1;
}

DATA *SeqListFindByNum(SeqListType *SL,int n)
{
    if(n<1 || n>SL->ListLen+1)
    {
        printf("节点序号错误，不能返回节点！\n");
        return NULL;
    }
    return &(SL->ListData[n]);
}

int SeqListFindByCont(SeqListType *SL,char *key)
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
    {
        if(strcmp(SL->ListData[i].key,key)==0){
            return i;
        }
        return 0;
    }
}

int SeqListAll(SeqListType *SL)
{
    int i;
    for(i=1;i<=SL->ListLen;i++)
    {
        printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age);
    }
    return 0;
}
int main()
{
	int i;
	SeqListType SL;
	DATA data,*data1;
	char key[15];
	
	SeqListInit(&SL);
	
	do{
	    printf("输入添加的结点（学号 姓名 年龄):");
	    fflush(stdin);
	    scanf("%s%s%d",&data.key,&data.name,&data.age);
	    if(data.age)
	    {
	        if(!SeqListAdd(&SL,data)){
	            break;
	        }
	    }
	    else 
	        break;
	}while(1);
	printf("\n顺序表中的节点顺序为:\n");
	SeqListAll(&SL);
	
	fflush(stdin);
	printf("\n要取出节点的序号：");
	scanf("%d",&i);
	data1=SeqListFindByNum(&SL,i);
	if(data1){
	    printf("第%d个节点为:(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
	}
	fflush(stdin);
	printf("\n要查找节点的关键字:");
	scanf("%s",key);
	i=SeqListFindByCont(&SL,key);
	data1=SeqListFindByNum(&SL,i);
	if(data1){
	    printf("第%d个节点为:(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
	}
	getc();
	return 0;
}

