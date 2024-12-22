#include <iostream>
#include <stack>
#include <string>
using namespace  std;
int uutien(string dau) {
    if(dau == "~") return 4;
    else if(dau == "|" || dau == "&") return 3;
    else if(dau == "->") return 2;
    else if(dau == "<->") return 1;
    else return 0;
}
string LogicInfix2Postfix(string infix) {
    stack<string> s;
    string tmp;
    string str = "";
    int n = infix.length();
    for(int i = 0; i < n; i++) {
        while(infix[i] == ' ') i++;
        if(infix[i] <= 'z' && infix[i] >= 'a') {
            str+=infix[i];
        }
        else {
            tmp = infix[i];
            if(infix[i] == '-') {
                tmp += infix[i+1];
                i++;
            }
            else if(infix[i] == '<') {
                tmp += infix[i+1];i++;
                tmp += infix[i+1];i++;
            }
            int b1 = 1;
            while(b1) {
                if(tmp == "(") {
                        s.push(tmp);
                        b1 = 0;
                    }
                else if(tmp == ")") {
                    while(s.top() != "(") {
                        str += s.top();
                        s.pop();
                    }
                    s.pop();
                    b1 = 0;
                }
                else if(s.empty() || s.top() == "(" || uutien(tmp) > uutien(s.top())) {
                    s.push(tmp);
                    b1 = 0;
                }
                else if(uutien(tmp) <= uutien(s.top())) {
                    str += s.top();
                    s.pop();
                }
            }
        }
    }
    while(!s.empty()) {
        str += s.top();
        s.pop();
    }
    return str;
}
int main()
{
    string s;
    getline(cin, s);
  s=LogicInfix2Postfix(s);
  cout<<s;

//   ifstream k;
//  k.open("output.txt");
//  for (int i = 0; i < 200; ++i) {
//   string a, b, c;
//   getline(k, a);
//   getline(k, b);
//   getline(k, c);
//   cout << "test case" << to_string(i) << ": " << LogicPostfixPrefixCalculator(b, c) << endl;


return 0;
}