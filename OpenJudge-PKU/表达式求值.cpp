
#include <iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

int factor_value();
int term_value();
int expression_value();
int main()
{
   cout << expression_value() << endl; 
   
   return 0;
}
int expression_value()//求一个表达式的值
{
    int result =term_value();//求第一项的值
    bool more =true;
    while(more){
        char op =cin.peek();//看一个字符不取走
        if(op=='+'||op=='-'){
            cin.get();//取走一个字符
            int value = term_value();
            if(op=='+') result+=value;
            else result-=value;
        }
        else more=false;
    }
    return result;
}
int term_value()
{
    int result =factor_value();//求第一个因子的值
    while(true){
        char op=cin.peek();
        if(op=='*'||op=='/'){
            cin.get();
            int value=factor_value();
            if(op=='*') result*=value;
            else result/=value;
        }
        else break;
    }
    return result;
}
int factor_value()
{
    int result=0;
    char c =cin.peek();
    if (c=='('){
        cin.get();
        result=expression_value();
        cin.get();
    }
    else {
        while(isdigit(c)){
            result=10*result+c-'0';
            cin.get();
            c=cin.peek();
        }
    }
    return result;
}

STDIN:(2+3)*(5+7)+9/3

STDOUT:63
