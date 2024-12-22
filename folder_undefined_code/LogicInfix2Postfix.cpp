#include<bits/stdc++.h>
#include<string>
#include<stack>

using namespace std;

int thu_tu(string t)
{
    if(t=="~") return 3;
    else if(t=="&"||t=="|") return 2;
    else if(t=="<->" || t=="->") return 1;
    else if(t==")") return 0;
    return 0;
}

string LogicInfix2Postfix(string infix)
{
    stack<string>st;
    string str="";
    vector<string> ss;
    int i=0;
    int e=infix.length();

    while(i<e)
    {
        
        if(infix[i]=='-'||infix[i]=='<')
        {
            string tmp="";
            while(infix[i]!='>')
            {
                tmp.push_back(infix[i]);
                i++;
            }
            tmp.push_back(infix[i]);
            ss.push_back(tmp);
        }
        else
        {
            string tmp=""; tmp.push_back(infix[i]);
            ss.push_back(tmp);
        }
        i++;
    }

    i=0;
    int n=ss.length();
    while(i<n)
    {
        if(ss[i]=="(") {st.push(ss[i]); i++;}
        else if(ss[i]==")")
        {
            if(!st.empty())
            {
             while(st.top()!="(")
             {
                str+=st.top();
                st.pop();
             }
            if(!st.empty()) if(st.top()=="(") st.pop();
            i++;
            }
        }
        else if(ss[i]>="a"&& ss[i]<="z")
        {
            str+=ss[i];
            i++;
        }
        else
        {
            if(!st.empty())
            {
             while(thu_tu(st.top())>=thu_tu(ss[i]))
             {
                str+=st.top();
                st.pop();
             if(st.empty()) break;
             }
            }
            st.push(ss[i]);
            i++;
        }
    }
    while(!st.empty())
        {
            str+=st.top();
            st.pop();
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