
#include<bits/stdc++.h>
using namespace std;


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

int main()
{
    string s;
    getline(cin, s);
    s=LogicInfix2Prefix(s);
    cout<<s;
}

//(t|x->~s)->~t<->(r<->q|t->(x|(~u|(t))))