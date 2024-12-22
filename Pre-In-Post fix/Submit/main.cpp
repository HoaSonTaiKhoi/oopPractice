#include"file.h"
#include<string>
using namespace std;
int main()
{
    string infix="(3+4)^2";
    string postfix="2 3 + 4 5 - * 2 ^ 10 30 + /";
    string logicinfix="~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))";
    string str2_3="->~t|&t~w&z<->&p&&|&w&|ppqyzz&&x|~pz~y";
    string varlue="t w z p q y x 1 1 1 1 1 1 1";

    //1.1 1.2
    cout<<Infix2Prefix(infix)<<"\n";
    cout<<Infix2Postfix(infix)<<"\n";

    //1.3
    cout<<PostfixPrefixCalculator(postfix)<<"\n";

    //2.1 2.2
    string logicpostfix=LogicInfix2Postfix(logicinfix);
    string logicprefix=LogicInfix2Prefix(logicinfix);

    cout<<logicpostfix<<"\n";
    cout<<logicprefix<<"\n";

    //2.3
    cout<<LogicPostfixPrefixCalculator(str2_3, varlue)<<"\n";
return 0;
}

//g++ main.cpp file.cpp -o main
//.\main