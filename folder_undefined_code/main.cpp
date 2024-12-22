#include "CTRR.h"



int main(){
    string infix="(3+4)*(5-2)/(6+1)";
    cout <<Infix2Postfix(infix)<<endl;
    cout <<Infix2Prefix(infix)<<endl;
    string input="123 456 + 789 321 - * 2 ^ 654 321 + /";
    cout <<PostfixPrefixCalculator(input)<<endl;
    string logic21="a&b";
    cout <<LogicInfix2Postfix(logic21)<<endl;
    string logic22="~t->t&~w|(z&(p&(w&(p|p&q)|y&z&z)<->x&(~p|z)&~y))";
    cout <<LogicInfix2Prefix(logic22)<<endl;
    string logicInput="->~t|&t~w&z<->&p&&|&w&|ppqyzz&&x|~pz~y";
    string value="t w z p q y x 1 1 1 1 1 1 1";
    cout <<LogicPostfixPrefixCalculator(logicInput,value)<<endl;
    return 0;
}