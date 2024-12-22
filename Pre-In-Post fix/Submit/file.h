#pragma once

#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<math.h>

using namespace std;

int thu_tu_dau(char t);
string Infix2Postfix(string infix);
string Infix2Prefix(string infix);
bool check(string c);
string PostfixPrefixCalculator(string input);
int uutien(string dau);
string LogicInfix2Postfix(string infix);
int thu_tu(string t);
string LogicInfix2Prefix(string infix);
bool check1(string s);
string LogicPostfixPrefixCalculator(string input, string varlue);
