
1单选(0.5分)
假设P为调用过程，Q为被调用过程，程序在IA-32处理器上执行，以下有关过程调用的叙述中，错误的是（   ）。

得分/总分

A.
C语言程序中的函数调用就是过程调用


B.
从Q跳回到Q执行应使用RET指令


C.
从P传到Q的实参无需重新分配空间存放

0.50/0.50

D.
从P跳转到Q执行应使用CALL指令

正确答案：C你选对了
2单选(0.5分)
以下是有关IA-32的过程调用方式的叙述，错误的是（   ）。

得分/总分

A.
EAX、ECX和EDX都是调用者保存寄存器


B.
EBX、ESI、EDI、EBP和ESP都是被调用者保存寄存器

0.50/0.50

C.
返回地址是CALL指令下一条指令的地址，被保存在栈中


D.
入口参数使用栈（stack）传递，即所传递的实参被分配在栈中

正确答案：B你选对了
3单选(0.5分)
以下是有关IA-32的过程调用所使用的栈和栈帧的叙述，错误的是（   ）。

得分/总分

A.
过程嵌套调用深度越深，栈中栈帧个数越多，严重时会发生栈溢出


B.
只能通过将栈指针ESP作为基址寄存器来访问用户栈中的数据

0.50/0.50

C.
从被调用过程返回调用过程之前，被调用过程会释放自己的栈帧


D.
每进行一次过程调用，用户栈从高地址向低地址增长出一个栈帧

正确答案：B你选对了
4单选(0.5分)
以下是有关C语言程序的变量的作用域和生存期的叙述，错误的是（   ）。

得分/总分

A.
非静态局部变量可以和全局变量同名，是因为它们被分配在不同存储区


B.
不同过程中的非静态局部变量可以同名，是因为它们被分配在不同栈帧中


C.
静态（static型）变量和非静态局部（auto型）变量都分配在对应栈帧中

0.50/0.50

D.
因为非静态局部变量被分配在栈中，所以其作用域仅在过程体内

正确答案：C你选对了
5单选(0.5分)
以下是一个C语言程序代码：

int add(int x, int y)

{

    return x+y;

}

 

int caller( )

{

    int t1=100 ;

    int t2=200;

    int sum=add(t1, t2);

    return sum;

}

 以下关于上述程序代码在IA-32上执行的叙述中，错误的是（    ）。

得分/总分

A.
变量sum被分配在caller函数的栈帧中


B.
变量t1和t2被分配在caller函数的栈帧中


C.
add函数返回时返回值存放在EAX寄存器中


D.
传递参数时t1和t2的值从高地址到低地址依次存入栈中

0.50/0.50
正确答案：D你选对了
6单选(0.5分)

第5题中的caller函数对应的机器级代码如下：

1      pushl       %ebp

                       2      movl       %esp, %ebp

                       3      subl         $24, %esp

                       4      movl        $100, -12(%ebp)

                       5      movl        $200, -8(%ebp) 

                       6      movl       -8(%ebp), %eax

                       7      movl        %eax, 4(%esp)

                       8      movl        -12(%ebp), %eax

                       9      movl        %eax, (%esp)  

                       10    call          add  

                       11    movl        %eax, -4(%ebp) 

                       12    movl        -4(%ebp), %eax

                       13    leave        

                       14    ret 

 假定caller的调用过程为P，对于上述指令序列，以下叙述中错误的是（     ）。

得分/总分

A.
第1条指令将过程P的EBP内容压入caller栈帧


B.
第3条指令将栈指针ESP向高地址方向移动，以生成当前栈帧

0.50/0.50

C.
第2条指令使BEP内容指向caller栈帧的底部


D.
从上述指令序列可看出，caller函数没有使用被调用者保存寄存器

正确答案：B你选对了
7单选(0.5分)
对于第5题的caller函数以及第6题给出的对应机器级代码，以下叙述中错误的是（    ）。

得分/总分

A.
参数t1和t2的有效地址分别为R[esp]和R[esp]+4


B.
变量t1和t2的有效地址分别为R[ebp]-12和R[ebp]-8


C.
变量t1所在的地址高（或大）于变量t2所在的地址

0.50/0.50

D.
参数t1所在的地址低（或小）于参数t2所在的地址

正确答案：C你选对了
8单选(0.5分)
以下有关递归过程调用的叙述中，错误的是（     ）。

得分/总分

A.
可能需要执行递归过程很多次，因而时间开销大


B.
递归过程第一个参数的有效地址为R[ebp]+8


C.
每次递归调用在栈帧中保存的返回地址都不相同

0.50/0.50

D.
每次递归调用都会生成一个新的栈帧，因而空间开销大

正确答案：C你选对了
9单选(0.5分)
以下关于if (cond_expr) then_statement else else_statement选择结构对应的机器级代码表示的叙述中，错误的是（    ）。

得分/总分

A.
一定包含一条条件转移指令（分支指令）


B.
一定包含一条无条件转移指令


C.
对应then_statement的代码一定在对应else_statement的代码之前

0.50/0.50

D.
计算cond_expr的代码段一定在条件转移指令之前

正确答案：C你选对了
10单选(0.5分)
以下关于循环结构语句的机器级代码表示的叙述中，错误的是（   ）。

得分/总分

A.
不一定包含无条件转移指令


B.
一定至少包含一条条件转移指令


C.
循环结束条件通常用一条比较指令CMP来实现


D.
循环体内执行的指令不包含条件转移指令

0.50/0.50
正确答案：D你选对了

