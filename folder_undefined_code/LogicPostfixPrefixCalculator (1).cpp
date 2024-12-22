#include <iostream>
#include <stack>
#include <map>
using namespace std; 
bool isAlphabet (char a) {
   if ('a' <= a && a <= 'z') return true;
   else if ('A' <= a && a <= 'Z') return true;
   return false;
}
bool logicCalculator (bool a, char o, bool b) {
   switch (o) {
   case '&':
      return a && b;
   case '|': 
      return a || b;
   case '@': //->
      return !a || b;
   case '$': //<->
      return a == b;
   default:
      return -1;
   }
}  
string convertExpression(string input, string value) {
   int pos = 0; 
   map<char,char> map;
   string result = "";

   while (1) {
      if (value[pos] == '1' || value[pos] == '0') break;
      ++pos;
   }
   for (int i = 0; i < pos; i += 2) 
      map[value[i]] = value[i+pos];
   char i;
   for (unsigned int a = 0; a < input.length(); a++) {
      i = input[a];
      if (isAlphabet(i)) 
         result += map[i];
      else if (i == '<'){ 
         a += 2;
         result += '$';
      }
      else if (i == '-') {
         a += 1;
         result += '@';
      }
      else if (i != ' ') 
         result += i;
   }
   //cout<<result<<endl;
   return result;
}
bool LogicPostfixCalculator (string expression) {
   stack<bool> stk;
   bool a,b;
   for (char i:expression) {
      if (i == '0' || i == '1') stk.push(i-'0');
      else if (i == '~') {
         a = stk.top();
         stk.pop();
         stk.push(!a);
      }
      else{
         b = stk.top();
         stk.pop();
         a = stk.top();
         stk.pop();
         stk.push( logicCalculator(a, i, b) );
      }
   }
   return stk.top();
}
bool LogicPrefixCalculator (string expression) {
   stack<bool> stk;
   bool a,b; 
   char i;
   for (int j = expression.length()-1; j >= 0; --j) {
      i = expression[j];
      if (i == '0' || i == '1') stk.push(i-'0');
      else if (i == '~') {
         a = stk.top();
         stk.pop();
         stk.push(!a);
      }
      else{
         a = stk.top();
         stk.pop();
         b = stk.top();
         stk.pop();
         stk.push( logicCalculator(a, i, b) );
      }
   }
   return stk.top();
}
string LogicPostfixPrefixCalculator(string input,string value){
   bool result;
   if (isAlphabet(input[0])) result = LogicPostfixCalculator(convertExpression(input,value));
   else result = LogicPrefixCalculator(convertExpression(input,value));
   return (result)? "TRUE":"FALSE";
}
int main() {
   string input = "q~u~w&vq|&->";
   string value = "q u w v 1 1 1 0";
   cout<<LogicPostfixPrefixCalculator(input,value);
}
                                                                                            