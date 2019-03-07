01-复杂度3 二分查找 （20 分）
本题要求实现二分查找算法。

函数接口定义：
Position BinarySearch( List L, ElementType X );
其中List结构定义如下：

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};
L是用户传入的一个线性表，其中ElementType元素可以通过>、==、<进行比较，并且题目保证传入的数据是递增有序的。函数BinarySearch要查找X在Data中的位置，即数组下标（注意：元素从下标1开始存储）。
找到则返回下标，否则返回一个特殊的失败标记NotFound。

裁判测试程序样例：
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
输入样例1：
5
12 31 55 89 101
31
输出样例1：
2
输入样例2：
3
26 78 233
31
输出样例2：
0


#局部代码:
Position BinarySearch( List Tbl, ElementType K )
{
	if(Tbl==NULL)
		return NotFound;
	int low=1,high=Tbl->Last;
	int mid;
	while(low<=high)//low一定小于等于high 如下标为1、2、3 要查询的是下标为1的数,第一次是比较下标为2的,不符合 high就变成了1,如果写low<high就会返回错误的结果
	{
		mid=(low+high)/2;
		if(Tbl->Data[mid]==K)
			return mid;
		else if(Tbl->Data[mid]>K)
			high=mid-1;
		else
			low=mid+1;
	}
	return NotFound;
}

#全部代码:
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

List ReadInput(){//List is a point;
    int N;
    scanf("%d",&N);
    List L = (struct LNode*)malloc(sizeof(struct LNode)); /* Strange!! Why LNode is non-declared? Use struct LNode instead of LNode!!!*/
    L->Last = N;
    for(ElementType i=1;i<=N;i++){
        scanf("%d",&L->Data[i]);
    }
    return L;
}

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */
Position BinarySearch( List L, ElementType X ){
    Position position;
    Position left = 0;
    Position right = L->Last;
    ElementType flag = 0;
    while(left <= right){
        Position mid = left + (right -left)/2; 
        /* I know that there should notice sth, 
        but i cannot remember that exactly*/
        if(L->Data[mid] == X){
            position = mid;
            flag = 1;
            break;
        }
        else if(L->Data[mid] > X){
            right = mid-1;
        }else{
            left = mid+1; 
        }
    }
    if(flag == 0)
        position = NotFound;
    return position;  /*Only one return.*/
}
--------------------- 
作者：酱油瓶被人注册了 
来源：CSDN 
原文：https://blog.csdn.net/qq_25175067/article/details/79502801 
版权声明：本文为博主原创文章，转载请附上博文链接！
