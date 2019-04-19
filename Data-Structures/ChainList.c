
// ChainList.h
        #include<stdlib.h>
        typedef struct Node
        {
          DATA data;
          struct Node *next;
        }ChainListType;
        ChainListType *ChainListAddEnd(ChainListType *head,DATA data);
        ChainListType *ChainListAddFirst(ChainListType *head,DATA data);
        ChainListType *ChainListFind(ChainListType *head,char *key);
        ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data);//插入节点到指定位置
        int ChainListDelete(ChainListType *head,char *key);
        int ChainListLength(ChainListType *head);


// ChainList.c
  #include<string.h>
ChainListType *ChainListAddEnd(ChainListType *head,DATA data)
{
  ChainListType *node,*h;
  if(!(node=(ChainListType *)malloc(sizeof(ChainListType))))
  {
    printf("为保存节点申请内存失败"!\n);
    return NULL;
  }
  node->data=data;
  node->next=NULL;
  if(head==NULL)
  {
    head=node;
    return head;
  }
  h=head;//保存头指针
  while(h->next!=NULL)
  {
    h=h->next;
  }
  h->next=node;
  return head;
}

ChainListType *ChainListFirst(ChainListType *head,DATA data)
{
  ChainListType *node,*h;
  if(!(node=(ChainListType *)malloc(sizeof(ChainListType))))
  {
    printf("为保存节点申请内存失败"!\n);
    return NULL;
  }
  node->data=data;
  node->next=head;
  head=node;
  return head;
}

ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data)
{
  ChainListType *node,*node1;
  if(!(node=(ChainListType *)malloc(sizeof(ChainListType))))
  {
    printf("为保存节点申请内存失败"!\n);
    return NULL;
  }
  node->data=data;
  node1=ChainListFind(head,findkey);
  if(node1)
  {
    node->next=node1->next;
    node1->next=node;
  }else{
    free(node);
    printf("未找到插入位置!\n");
  }
  return head;
}

ChainListType *ChainListFind(ChainListType *head,char *key)
{
  ChainListType *h;
  h=head;
  while(h)
  {
    if(strcmp(h->data.key,key)==0)
    {
      return h;
    }
    h=h->next;
  }
  return NULL;
}
  
ChainListType *ChainListDelete(ChainListType *head,char *key)
{
  ChainListType *h,*node;
  node=h=head;
  while(h)
  {
    if(strcmp(h->data.key,key)==0)
    {
      node->next=h->next;
      free(h);
      return 1;
    }else{
      node=h
      h=h->next;
    }
  }
  return 0;
}
  
  int ChainListLength(ChainListType *head)
  {
    ChainListType *h;
    int i=0;
    h=head;
    while(h)
    {
      i++;
      h=h->next;
    }
    return i;
  }
 
 //ChainListTest.c
 
 #include<stdio.h>
typedef struct
{
  char key[15];
  char name[20];
  int age;
}DATA;
#include "ChainList.h"
#include "ChainList.c"
void ChainListAll(ChainListType *head)
{
  ChainListType *h;
  DATA data;
  h=head;
  printf("链表所有数据如下:\n");
  while(h)
  {
    data=h->data;
    printf("(%s,%s,%d)\n",data.key,daya.name,data.age);
    h=h->next;
  }
  return ;
}
int main()
{
  ChainListType *node,*head=NULL;
  DATA data;
  char key[15],findkey[15];
  printf("输入链表中的数据，包括关键字、姓名、年龄，关键字输入0则退出:\n");
  do{
    fflush(stdin);
    scanf("%s",data.key);
    if(strcmp(data.key,"0")==0)
    {
      break;
    }
    scanf("%s%d",data.name,&data.age);
    head=ChainListAddEnd(head,data);
  }while(1);
  printf("该链表共有%d个节点。\n",ChainListLength(head));
  ChainListAll(head);
  printf("\n插入节点，输入插入位置的关键字:");
  scanf("%s",&findkey);
  printf("输入插入节点的数据(关键字 姓名 年龄):");
  scanf("%s%s%d",data.key,data.name,&data.age);
  head=ChainListInsert(head,findkey,data);
  
  ChainListAll(head);
  printf("\n在链表中查找，输入查找关键字：");
  fflush(stdin);
  scanf("%s",key);
  node=ChainListFind(head,key);
  if(node)
  {
    data=node->data;
    printf("关键字%s对应的节点数据为(%s,%s,%d)\n",key,data.key,data.name,data.age);
  }else{
    printf("在链表中未找到关键字为%s的节点！\n",key);
   }
   printf("\n在链表中删除节点，输入要删除的关键字:");
   fflush(stdin);
   scanf("%s",key);
   ChainListDelete(head,key);
   ChainListAll(head);
   getc();
   return 0;
}
           
  
