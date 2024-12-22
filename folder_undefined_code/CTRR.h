#include <iostream>
#include <string>
#include <stack>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <vector>
using namespace std;



// 1.1
int precedence(char op); // độ ưu tiên toán tử
string Infix2Postfix(string infix);

// 1.2
int Kiem_Tra_Do_Uu_Tien(char op);
string Infix2Prefix(string infix);

// 1.3
bool ToanTu(string &c);
int getPriority(char c);
bool isOperator(string c);
string evaluatePrefix(string prefix);
string evaluatePostfix(string postfix);
string PostfixPrefixCalculator(string input);

// 2.1
int prec(char ch);
string LogicInfix2Postfix(std::string infix);

// 2.2
int prec22(char ch);
string LogicInfix2Postfix22(std::string infix);
string LogicInfix2Prefix(string infix);

//2.3
struct Node
{
	char data;
	Node* pnext;
};
char booltochar (bool a);
bool chartobool (char a);
int isope(char x);
char tinh(char a, char x, char b);
string post(string input,string varlue);
string pre(string input,string varlue);
string LogicPostfixPrefixCalculator(string input,string varlue);

