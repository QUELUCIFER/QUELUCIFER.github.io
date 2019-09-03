### 二叉树的链表结构

```c
    typedef struct TNode *Position;
    typedef Position BinTree; /* 二叉树类型 */
    struct TNode{ /* 树结点定义 */
        ElementType Data; /* 结点数据 */
        BinTree Left;     /* 指向左子树 */
        BinTree Right;    /* 指向右子树 */
    };
```

### 二叉树的四种遍历

```c
    void InorderTraversal( BinTree BT )
    {
        if( BT ) {
            InorderTraversal( BT->Left );
            /* 此处假设对BT结点的访问就是打印数据 */
            printf("%d ", BT->Data); /* 假设数据为整型 */
            InorderTraversal( BT->Right );
        }
    }
     
    void PreorderTraversal( BinTree BT )
    {
        if( BT ) {
            printf("%d ", BT->Data );
            PreorderTraversal( BT->Left );
            PreorderTraversal( BT->Right );
        }
    }
     
    void PostorderTraversal( BinTree BT )
    {
        if( BT ) {
            PostorderTraversal( BT->Left );
            PostorderTraversal( BT->Right );
            printf("%d ", BT->Data);
        }
    }
     
    void LevelorderTraversal ( BinTree BT )
    { 
        Queue Q; 
        BinTree T;
     
        if ( !BT ) return; /* 若是空树则直接返回 */
         
        Q = CreatQueue(); /* 创建空队列Q */
        AddQ( Q, BT );
        while ( !IsEmpty(Q) ) {
            T = DeleteQ( Q );
            printf("%d ", T->Data); /* 访问取出队列的结点 */
            if ( T->Left )   AddQ( Q, T->Left );
            if ( T->Right )  AddQ( Q, T->Right );
        }
    }
```

### 二叉搜索树的插入与删除

```c
    BinTree Insert( BinTree BST, ElementType X )
    {
        if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
            BST = (BinTree)malloc(sizeof(struct TNode));
            BST->Data = X;
            BST->Left = BST->Right = NULL;
        }
        else { /* 开始找要插入元素的位置 */
            if( X < BST->Data )
                BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
            else  if( X > BST->Data )
                BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
            /* else X已经存在，什么都不做 */
        }
        return BST;
    }
     
    BinTree Delete( BinTree BST, ElementType X ) 
    { 
        Position Tmp; 
     
        if( !BST ) 
            printf("要删除的元素未找到"); 
        else {
            if( X < BST->Data ) 
                BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
            else if( X > BST->Data ) 
                BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
            else { /* BST就是要删除的结点 */
                /* 如果被删除结点有左右两个子结点 */ 
                if( BST->Left && BST->Right ) {
                    /* 从右子树中找最小的元素填充删除结点 */
                    Tmp = FindMin( BST->Right );
                    BST->Data = Tmp->Data;
                    /* 从右子树中删除最小元素 */
                    BST->Right = Delete( BST->Right, BST->Data );
                }
                else { /* 被删除结点有一个或无子结点 */
                    Tmp = BST; 
                    if( !BST->Left )       /* 只有右孩子或无子结点 */
                        BST = BST->Right; 
                    else                   /* 只有左孩子 */
                        BST = BST->Left;
                    free( Tmp );
                }
            }
        }
        return BST;
    }
```

### AVL树的旋转与插入

```c
    BinTree Insert( BinTree BST, ElementType X )
    {
        if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
            BST = (BinTree)malloc(sizeof(struct TNode));
            BST->Data = X;
            BST->Left = BST->Right = NULL;
        }
        else { /* 开始找要插入元素的位置 */
            if( X < BST->Data )
                BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
            else  if( X > BST->Data )
                BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
            /* else X已经存在，什么都不做 */
        }
        return BST;
    }
     
    BinTree Delete( BinTree BST, ElementType X ) 
    { 
        Position Tmp; 
     
        if( !BST ) 
            printf("要删除的元素未找到"); 
        else {
            if( X < BST->Data ) 
                BST->Left = Delete( BST->Left, X );   /* 从左子树递归删除 */
            else if( X > BST->Data ) 
                BST->Right = Delete( BST->Right, X ); /* 从右子树递归删除 */
            else { /* BST就是要删除的结点 */
                /* 如果被删除结点有左右两个子结点 */ 
                if( BST->Left && BST->Right ) {
                    /* 从右子树中找最小的元素填充删除结点 */
                    Tmp = FindMin( BST->Right );
                    BST->Data = Tmp->Data;
                    /* 从右子树中删除最小元素 */
                    BST->Right = Delete( BST->Right, BST->Data );
                }
                else { /* 被删除结点有一个或无子结点 */
                    Tmp = BST; 
                    if( !BST->Left )       /* 只有右孩子或无子结点 */
                        BST = BST->Right; 
                    else                   /* 只有左孩子 */
                        BST = BST->Left;
                    free( Tmp );
                }
            }
        }
        return BST;
    }
```

### 堆

```c
    typedef struct HNode *Heap; /* 堆的类型定义 */
    struct HNode {
        ElementType *Data; /* 存储元素的数组 */
        int Size;          /* 堆中当前元素个数 */
        int Capacity;      /* 堆的最大容量 */
    };
    typedef Heap MaxHeap; /* 最大堆 */
    typedef Heap MinHeap; /* 最小堆 */
     
    #define MAXDATA 1000  /* 该值应根据具体情况定义为大于堆中所有可能元素的值 */
     
    MaxHeap CreateHeap( int MaxSize )
    { /* 创建容量为MaxSize的空的最大堆 */
     
        MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
        H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
        H->Size = 0;
        H->Capacity = MaxSize;
        H->Data[0] = MAXDATA; /* 定义"哨兵"为大于堆中所有可能元素的值*/
     
        return H;
    }
     
    bool IsFull( MaxHeap H )
    {
        return (H->Size == H->Capacity);
    }
     
    bool Insert( MaxHeap H, ElementType X )
    { /* 将元素X插入最大堆H，其中H->Data[0]已经定义为哨兵 */
        int i;
      
        if ( IsFull(H) ) { 
            printf("最大堆已满");
            return false;
        }
        i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
        for ( ; H->Data[i/2] < X; i/=2 )
            H->Data[i] = H->Data[i/2]; /* 上滤X */
        H->Data[i] = X; /* 将X插入 */
        return true;
    }
     
    #define ERROR -1 /* 错误标识应根据具体情况定义为堆中不可能出现的元素值 */
     
    bool IsEmpty( MaxHeap H )
    {
        return (H->Size == 0);
    }
     
    ElementType DeleteMax( MaxHeap H )
    { /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
        int Parent, Child;
        ElementType MaxItem, X;
     
        if ( IsEmpty(H) ) {
            printf("最大堆已为空");
            return ERROR;
        }
     
        MaxItem = H->Data[1]; /* 取出根结点存放的最大值 */
        /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
        X = H->Data[H->Size--]; /* 注意当前堆的规模要减小 */
        for( Parent=1; Parent*2<=H->Size; Parent=Child ) {
            Child = Parent * 2;
            if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
                Child++;  /* Child指向左右子结点的较大者 */
            if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
            else  /* 下滤X */
                H->Data[Parent] = H->Data[Child];
        }
        H->Data[Parent] = X;
     
        return MaxItem;
    } 
     
    /*----------- 建造最大堆 -----------*/
    void PercDown( MaxHeap H, int p )
    { /* 下滤：将H中以H->Data[p]为根的子堆调整为最大堆 */
        int Parent, Child;
        ElementType X;
     
        X = H->Data[p]; /* 取出根结点存放的值 */
        for( Parent=p; Parent*2<=H->Size; Parent=Child ) {
            Child = Parent * 2;
            if( (Child!=H->Size) && (H->Data[Child]<H->Data[Child+1]) )
                Child++;  /* Child指向左右子结点的较大者 */
            if( X >= H->Data[Child] ) break; /* 找到了合适位置 */
            else  /* 下滤X */
                H->Data[Parent] = H->Data[Child];
        }
        H->Data[Parent] = X;
    }
     
    void BuildHeap( MaxHeap H )
    { /* 调整H->Data[]中的元素，使满足最大堆的有序性  */
      /* 这里假设所有H->Size个元素已经存在H->Data[]中 */
     
        int i;
     
        /* 从最后一个结点的父节点开始，到根结点1 */
        for( i = H->Size/2; i>0; i-- )
            PercDown( H, i );
    }

```

### 集合的定义与并查操作

```c
    #define MAXN 1000                  /* 集合最大元素个数 */
    typedef int ElementType;           /* 默认元素可以用非负整数表示 */
    typedef int SetName;               /* 默认用根结点的下标作为集合名称 */
    typedef ElementType SetType[MAXN]; /* 假设集合元素下标从0开始 */
     
    void Union( SetType S, SetName Root1, SetName Root2 )
    { /* 这里默认Root1和Root2是不同集合的根结点 */
        /* 保证小集合并入大集合 */
        if ( S[Root2] < S[Root1] ) { /* 如果集合2比较大 */
            S[Root2] += S[Root1];     /* 集合1并入集合2  */
            S[Root1] = Root2;
        }
        else {                         /* 如果集合1比较大 */
            S[Root1] += S[Root2];     /* 集合2并入集合1  */
            S[Root2] = Root1;
        }
    }
     
    SetName Find( SetType S, ElementType X )
    { /* 默认集合元素全部初始化为-1 */
        if ( S[X] < 0 ) /* 找到集合的根 */
            return X;
        else
            return S[X] = Find( S, S[X] ); /* 路径压缩 */
    }
```
