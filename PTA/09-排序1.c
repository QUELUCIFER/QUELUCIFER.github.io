/*09-排序1 排序 (25 分)

给定N个（长整型范围内的）整数，要求输出从小到大排序后的结果。

本题旨在测试各种不同的排序算法在各种数据情况下的表现。各组测试数据特点如下：

数据1：只有1个元素；

数据2：11个不相同的整数，测试基本正确性；

数据3：103个随机整数；

数据4：104个随机整数；

数据5：105个随机整数；

数据6：105个顺序整数；

数据7：105个逆序整数；

数据8：105个基本有序的整数；

数据9：105个随机正整数，每个数字不超过1000。

输入格式:

输入第一行给出正整数N（≤10​5​​），随后一行给出N个（长整型范围内的）整数，其间以空格分隔。
输出格式:

在一行中输出从小到大排序后的结果，数字间以1个空格分隔，行末不得有多余空格。
输入样例:

11
4 981 10 -17 0 -20 29 50 8 43 -5

输出样例:

-20 -17 -5 0 4 8 10 29 43 50 981
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100005
typedef long ElementType;
void Swap( ElementType *a, ElementType *b ) {
	ElementType Tmp = *a;
	*a = *b;
	*b = Tmp;
}
//冒泡排序; 顺序O(N), 逆序O(N^2); 稳定
void Bubble_Sort( ElementType A[], int N ) {
	int P, i, flag;
	for( P = N - 1; P > 0; P-- ) {  //执行N - 1趟冒泡
		flag = 0;
		for( i = 0; i < P; i++ )	//一趟冒泡，比较P次
			if( A[i] > A[i + 1] ){
				Swap(&A[i], &A[i + 1]);
				flag = 1;	//标记发生了交换
			}
		if( flag == 0 ) break;	//上一趟冒泡中无交换，说明已排好序
	}
}
//插入排序(与堆下滤有异曲同工之处); 顺序O(N), 逆序O(N^2); 稳定
void Insertion_Sort( ElementType A[], int N ) {
	int P, i;
	ElementType Tmp;
	for( P = 1; P < N; P++ ) {
		Tmp = A[P];		//取出未排序序列中的第一个元素
		for( i = P; i > 0 && A[i - 1] > Tmp; i-- )
			A[i] = A[i - 1];	//依次与已排序序列中的元素比较并右移
		A[i] = Tmp;		//插入到合适的位置
	}
}
//希尔排序 - 希尔增量; O(N^2); 不稳定
void Shell_Sort( ElementType A[], int N ) {
	int D, P, i;
	ElementType Tmp;
	for( D = N / 2; D > 0; D /= 2 )		//希尔增量，每次减半，直到为0
		for( P = D; P < N; P++ ) {    //插入排序，所有1改成D，条件 i > 0 改成 i >= D
			Tmp = A[P];
			for( i = P; i >= D && A[i - D] > Tmp; i -= D )
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}
//希尔排序 - 用Sedgewick增量序列; 猜想：平均O( N^(7/6) ), 最坏O( N^(4/3) ); 不稳定
void Shell_Sort_Sedgewick( ElementType A[], int N ) {
	int Si, D, P, i;
	ElementType Tmp;
	//这里只列出一小部分增量，公式：选取 9 * 4^i - 9 * 2^i + 1 或 4^i - 3 * 2^i + 1 中的项组合而成
	//int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
    int Sedgewick[] = {146305, 64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1, 0};
	for( Si = 0; Sedgewick[Si] >= N; Si++ )
		;	//初始增量Sedgewick[Si]不能超过待排序列的长度
	for( D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si] )
		for( P = D; P < N; P++) {    //插入排序
			Tmp = A[P];
			for( i = P; i >= D && A[i - D] > Tmp; i -= D )
				A[i] = A[i - D];
			A[i] = Tmp;
		}
}
//选择排序; O(N^2); 不稳定
void Selection_Sort( ElementType A[], int N ) {
	int P, i, idx;
	for( P = 0; P < N - 1; P++ )	{	//N-1不用选择，因为前面已经排好序
		idx = P;		//选择P这个位置，从它后面的元素中找一个最小的代替它
		for( i = P + 1; i < N; i++ )
			if( A[idx] > A[i] )
				idx = i;	//记录最小元素的下标，用此方法减少交换次数
		if( idx != P )	//如果找到比A[P]小的元素A[idx]，则交换
			Swap(&A[idx], &A[P]);
	}
}
//堆排序; O(N*logN); 不稳定
void PercDown( ElementType A[], int p, int N ) {
	//将N个元素的数组中以A[p]为根的子堆调整为最大堆
	int Parent, Child;
	ElementType X;
	X = A[p];	//取出根结点存放的值
	//(Parent * 2 + 1) < N 检测Parent有没有孩子
	for( Parent = p; (Parent * 2 + 1) < N; Parent = Child ) {
		Child = Parent * 2 + 1;
		if( Child != N - 1 && A[Child] < A[Child + 1] )
			Child++;	//Child指向左右子结点较大者
		if( X >= A[Child] ) break;
		else	//下滤
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}
void Heap_Sort( ElementType A[], int N ) {
	int i;
	//建立最大堆，由于下标从0开始，最后一个元素的父结点是 N / 2 - 1
	for( i = N / 2 - 1; i >= 0; i--)	
		PercDown(A, i, N);
	//删除堆顶
	for( i = N - 1; i > 0; i-- ) {
		Swap(&A[0], &A[i]);		
		PercDown(A, 0, i);
	}
}
//归并排序 - 递归实现; O(N*logN); 稳定
//L = 左边起始位置，R = 右边起始位置，RightEnd = 右边终点位置
void Merge( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd ) {
	//将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列
	int LeftEnd, NumElements, Tmp;
	int i;
	LeftEnd = R - 1;	//左边终点位置
	Tmp = L;	//有序序列的起始位置
	NumElements = RightEnd - L + 1;		//元素总个数
	while( L <= LeftEnd && R <= RightEnd ) {
		if( A[L] <= A[R] )
			TmpA[Tmp++] = A[L++];	//将左边元素复制到TmpA
		else
			TmpA[Tmp++] = A[R++];	//将右边元素复制到TmpA
	}
	while( L <= LeftEnd )
		TmpA[Tmp++] = A[L++];	//直接复制左边剩下的
	while( R <= RightEnd )
		TmpA[Tmp++] = A[R++];	//直接复制右边剩下的
	for( i = 0; i < NumElements; i++, RightEnd-- )
		A[RightEnd] = TmpA[RightEnd];	//将有序的TmpA复制回A
}
void Msort( ElementType A[], ElementType TmpA[], int L, int RightEnd ) {
	//核心递归排序函数
	int Center;
	if( L < RightEnd ) {
		Center = (L + RightEnd) / 2;
		Msort( A, TmpA, L, Center );				//递归解决左边
		Msort( A, TmpA, Center + 1, RightEnd );		//递归解决右边
		Merge( A, TmpA, L, Center + 1, RightEnd );	//合并两段有序序列
	}
}
void Merge_Sort_Recursion( ElementType A[], int N ) {
	//在这里开辟TmpA数组，只需开辟一次
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));
	if( TmpA != NULL ) {
		Msort( A, TmpA, 0, N - 1 );
		free( TmpA );
	}
	else printf("空间不足");
}
//归并排序 - 循环实现; O(N*logN); 稳定
//Merge1相比Merge少了 将TmpA中的元素导回A 的步骤
void Merge1( ElementType A[], ElementType TmpA[], int L, int R, int RightEnd ) {
	//将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列
	int LeftEnd, NumElements, Tmp;
	int i;
	LeftEnd = R - 1;	//左边终点位置
	Tmp = L;	//有序序列的起始位置
	NumElements = RightEnd - L + 1;		//元素总个数
	while( L <= LeftEnd && R <= RightEnd ) {
		if( A[L] <= A[R] )
			TmpA[Tmp++] = A[L++];	//将左边元素复制到TmpA
		else
			TmpA[Tmp++] = A[R++];	//将右边元素复制到TmpA
	}
	while( L <= LeftEnd )
		TmpA[Tmp++] = A[L++];	//直接复制左边剩下的
	while( R <= RightEnd )
		TmpA[Tmp++] = A[R++];	//直接复制右边剩下的
}
void Merge_pass( ElementType A[], ElementType TmpA[], int N, int length ) {
	//两两归并相邻有序子列
	int i, j;
	for( i = 0; i <= N - 2 * length; i += 2 * length )
		Merge1( A, TmpA, i, i + length, i + 2 * length - 1 );
	if( i + length < N )	//归并最后2个子列
		Merge1( A, TmpA, i, i + length, N - 1 );
	else  //最后只剩1个子列
		for( j = i; j < N; j++ )
			TmpA[j] = A[j];
}
void Merge_Sort_Loop( ElementType A[], int N ) {
	int length;
	ElementType *TmpA;
	length = 1;		//初始化子序列长度
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));
	if ( TmpA != NULL ) {
		while( length < N ) {
			Merge_pass( A, TmpA, N, length );
			length *= 2;
			Merge_pass( TmpA, A, N, length );
			length *= 2;
		}
		free( TmpA );
	}
	else printf("空间不足");
}
int main(){
	ElementType A[MAX];
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%ld", &A[i]);
	//Bubble_Sort(A, N);
	//Insertion_Sort(A, N);
	//Shell_Sort(A, N);
	//Shell_Sort_Sedgewick(A, N);
	//Selection_Sort(A, N);
	//Heap_Sort(A, N);
	//Merge_Sort_Recursion(A, N);
	Merge_Sort_Loop(A, N);
	printf("%d", A[0]);
	for(int i = 1; i < N; i++)
		printf(" %d", A[i]);
	system("pause");
	return 0;
}





