#include <iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

double exp()
{
    char s[20];
    cin>>s;
    switch(s[0]){
        case '+' :  return exp()+exp();
        case '-' : return exp()-exp();
        case '*' : return exp()*exp();
        case '/' : return exp()/exp();
        default :return atof(s);
        break;
    }
}
int main(){
    printf("%lf",exp());
    return 0;
}

STDIN:* + 11.0 12.0 + 24.0 35.0

STDOUT:1357.000000
