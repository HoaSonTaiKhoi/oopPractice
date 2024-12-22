#include "file.h"
int thu_tu_dau(char t)
{
    if(t=='^') return 3;
    else if(t=='*'||t=='/') return 2;
    else if(t=='+'||t=='-') return 1;
    else if(t==')') return 0;
return 0;
}

string Infix2Postfix(string infix)
{
    int i=0,n=infix.length();
    stack<char> st;
    vector<string> str;

while(i<n)
    {
        if(infix[i]=='(') {st.push(infix[i]); i++;}
        else if(infix[i]==')')
        {
            while(st.top()!='(')
            {
                string tmp; tmp.push_back(st.top());
                str.push_back(tmp);
                st.pop();
            }
            st.pop();
            i++;
        }
        else if(infix[i]>='0' && infix[i]<='9')
        {
            string tmp;
            while(infix[i]>='0' && infix[i]<='9')
            {
                tmp+=infix[i];
                i++;
            }
            str.push_back(tmp);
        }
        else
        {
            while(!st.empty() && (thu_tu_dau(st.top())>=thu_tu_dau(infix[i])) )
            {
                string tmp; tmp.push_back(st.top());
                str.push_back(tmp);
                st.pop();
            }
            st.push(infix[i]); i++;
        }
    }
 while(!st.empty())
    {
        string tmp; tmp.push_back(st.top());
        str.push_back(tmp);
        st.pop();
    }

    string answer; int n1=str.size();
    for(i=0; i<n1; i++)
    {
        if(i!=0) answer+=" ";
        answer+=str[i];
    }
    return answer;
}

string Infix2Prefix(string infix)
{
    int n=infix.length(); int i=n-1;
    stack<char> st;
    vector<string> str;
    while(i>=0)
    {
        if(infix[i]==')') {st.push(infix[i]); i--;}
        else if(infix[i]=='(')
        {
            while(st.top()!=')')
            {
                string tmp; tmp.push_back(st.top());
                str.insert(str.begin(), tmp);
                st.pop();
            }
            st.pop();
            i--;
        }
        else if(infix[i]<='9'&& infix[i]>='0')
        {
            string tmp;
            while(infix[i]<='9'&& infix[i]>='0')
            {
                tmp.insert(tmp.begin(), infix[i]);
                i--;
            }
            str.insert(str.begin(), tmp);
        }
        else
        {
            while(!st.empty() && (thu_tu_dau(st.top())>thu_tu_dau(infix[i])) )
            {
                string tmp; tmp.push_back(st.top());
                str.insert(str.begin(), tmp);
                st.pop();
            }
            st.push(infix[i]); i--;
        }
    }
    while(!st.empty())
    {
        string tmp; tmp.push_back(st.top());
        str.insert(str.begin(), tmp);
        st.pop();
    }

    string answer; int n1=str.size();
    for(i=0; i<n1; i++)
    {
        if(i!=0) answer+=" ";
        answer+=str[i];
    }
    return answer;
}

bool check(string c)
{
if(c!="*" && c!="/" && c!="+" && c!="-" && c!="^") return true;
    return false;
}

string PostfixPrefixCalculator(string input)
{
    stringstream ss(input);
    stack<double> st;
    string tmp;

    vector<string> str;
        while(ss>>tmp)
        {
            str.push_back(tmp);
        }
        
    int n=str.size();
    if(input[0]>57||input[0]<48)
    {
        for(int i=n-1; i>=0; i--)
        {
            if(check(str[i]))
            {
                st.push(atof(str[i].c_str()));
            }
          else
          {
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            if(str[i]=="*") st.push(a*b);
            else if(str[i]=="/") st.push(a/b);
            else if(str[i]=="+") st.push(a+b);
            else if(str[i]=="-") st.push(a-b);
            else if(str[i]=="^") st.push(pow(a, b));
          }
        }
    }
    else
    {
        
        //Postfix
        for(int i=0; i<n; i++)
        {
          if(check(str[i]))
            {
                st.push(atof(str[i].c_str()));
            }
          else
           {
            double b=st.top();
            st.pop();
            double a=st.top();
            st.pop();
            if(str[i]=="*") st.push(a*b);
            else if(str[i]=="/") st.push(a/b);
            else if(str[i]=="+") st.push(a+b);
            else if(str[i]=="-") st.push(a-b);
            else if(str[i]=="^") st.push(pow(a, b));
           }
        }
    }
    stringstream cc;
    cc<<fixed<<setprecision(4)<<st.top();
    string tt=cc.str();
    while(tt[tt.size()-1]=='0') tt.pop_back();
    if(tt[tt.size()-1]=='.') tt.pop_back();
    return tt;
}

int uutien(string dau)
{
     if(dau == "~") return 4;
    else if(dau == "|" || dau == "&") return 3;
    else if(dau == "->") return 2;
    else if(dau == "<->") return 1;
    else return 0;
}

string LogicInfix2Postfix(string infix)
{
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

int thu_tu(string t)
{
     if(t=="~") return 4;
    else if(t=="&"||t=="|") return 3;
    else if(t=="->") return 2;
    else if(t=="<->") return 1;
    else if(t=="("||t==")") return 0;
    return 0;
}

string LogicInfix2Prefix(string infix)
{
vector<string> ss; int i=0; int e=infix.size();
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
        else if(infix[i]==' ') {}
        else
        {
            string tmp=""; tmp.push_back(infix[i]);
            ss.push_back(tmp);
        }
        i++;
    }

    int n=ss.size();
    i=n-1;
    stack<string> st;
    string str="";
    while(i>=0)
    {
        if(ss[i]==")") {st.push(ss[i]); i--;}
        else if(ss[i]=="(")
        {
           if(!st.empty())
           {
            while(st.top()!=")")
            {
                str.insert(0, st.top());
                st.pop();
            }
            if(!st.empty()) st.pop();
            i--;
           }
        }
        else if(ss[i]>="a"&& ss[i]<="z")
        {
            str.insert(0, ss[i]);
            i--;
        }
        else
        {
          if(!st.empty())
          {
            while(thu_tu(st.top())>thu_tu(ss[i]))
            {
                str.insert(0, st.top());
                st.pop();
                if(st.empty()) break;
            }
          }
            st.push(ss[i]); i--;
        }
    }
    while(!st.empty())
        {
            str.insert(0, st.top());
            st.pop();
        }
    return str;
}

bool check1(string s)
{
if(s!="<->" && s!="->" && s!="~" && s!="|" && s!="&") return true;
return false;
}

string LogicPostfixPrefixCalculator(string input, string varlue)
{
stack<int> st;
    vector<string> str;
    vector<string> a;
    vector<int> b;

    int n=input.size();
    for(int i=0; i<n; i++)
    {
        string tmp;
        tmp=input[i];
        if(input[i]=='<'||input[i]=='-')
        {
            while(input[i]!='>'){ i++; tmp.push_back(input[i]);}
        }
        str.push_back(tmp);
    }
    
    int m=varlue.length(),k=0;

   while(true)
   {
    string tmp;
    if(varlue[k]>=97 && varlue[k]<=122)
    {
        tmp=varlue[k];
        a.push_back(tmp);
    }
    k++;
    if(varlue[k]<=57 && varlue[k]>=48) break;
   }

   while(k<m)
   {
    string tmp;
    if(varlue[k]>=48 && varlue[k]<=57) 
    {
        tmp=varlue[k];
        b.push_back(atoi(tmp.c_str()));
    }
    k++;
   }

    if(str[0]>"z" || str[0]<"a")
    {
        int i=str.size()-1;
        while(i>=0)
        {
            if(str[i]=="~")
            {
                int a1=st.top(); st.pop();
                if(a1==1) st.push(0);
                else st.push(1);
            }
            else if(check1(str[i]))
               {
                int j=0; int h=a.size();
                for( j=0; j<h; j++ ) if(a[j]==str[i]){break;}
                st.push(b[j]);
               }
            else 
               {
                int a1=st.top(); st.pop();
                int b1=st.top(); st.pop();
                if(str[i]=="<->")
                {
                    if(a1+b1==0||a1+b1==2) st.push(1);
                    else if(a1+b1==1) st.push(0);
                }
                else if(str[i]=="&") 
                {
                    if(a1*b1==1) st.push(1);
                    else st.push(0);
                }
                else if(str[i]=="|")
                {
                    if(a1==1||b1==1) st.push(1);
                    else st.push(0);
                }
                else if(str[i]>="->")
                {
                    if(a1==1&&b1==0) st.push(0);
                    else st.push(1);
                }
               }
            i--;
        }
    }
    else
    {
        int i=0; int n1=str.size();
        while(i<n1)
        {
          if(str[i]=="~")
            {
                int a1=st.top(); st.pop();
                if(a1==1) st.push(0);
                else st.push(1);
            }
          else if(check1(str[i]))
            {
                int j=0; int h=a.size();
                for( j=0; j<h; j++ ) if(a[j]==str[i]) break;
                st.push(b[j]);
            }
          else
            {
                int b1=st.top(); st.pop();
                int a1=st.top(); st.pop();
                if(str[i]=="<->")
                {
                    if(a1+b1==0||a1+b1==2) st.push(1);
                    else if(a1+b1==1) st.push(0);
                }
                else if(str[i]=="&") 
                {
                    if(a1*b1==1) st.push(1);
                    else if(a1*b1==0) st.push(0);
                }
                else if(str[i]=="|")
                {
                    if(a1+b1>=1) st.push(1);
                    else if (a1+b1==0) st.push(0);
                }
                else if(str[i]>="->")
                {
                    if(a1==1&&b1==0) st.push(0);
                    else st.push(1);
                }
            }
            i++;
        }
    }
    if(st.top()==1) return "TRUE";
    else return "FALSE";
}
