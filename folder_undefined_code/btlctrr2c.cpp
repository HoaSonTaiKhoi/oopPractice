
#include<bits/stdc++.h>
using namespace std;

bool check(string s)
{
if(s!="<->" && s!="->" && s!="~" && s!="|" && s!="&") return true;
return false;
}


string Infix(string s)
{
    stack<int> st;
    vector<string> str;

    vector<string> a;
    vector<int> b;
    for(int i=0; i<s.size(); i++)
    {
        string tmp;
        if(s[i]=='<'||s[i]=='-')
        {
            while(s[i]!='>'){ tmp+=s[i]; i++;}
            tmp+=s[i];
            i++;
        }
        else 
        {
            tmp+=s[i];
        }
        str.push_back(tmp);
    }

    getline(cin, s);
    string tmp;
    stringstream ss(s);
    while(ss>>tmp&&tmp>="a" && tmp<="z")
    {
        a.push_back(tmp);
    }
    while(ss>>tmp&& tmp>="0"&&tmp<="1")
    {
        b.push_back(atoi(tmp.c_str()));
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
                else st.push(0);
            }
            else
            {
              if(check(str[i]))
               {
                int j=0;
                for( j=0; j<a.size(); j++ ) if(a[j]==str[i]) break;
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
            }
            i--;
        }
    }
    else
    {
        int i=0;
        while(i<str.size())
        {
          if(str[i]=="~")
            {
                int a1=st.top(); st.pop();
                if(a1==1) st.push(0);
                else st.push(0);
            }
          else
          {
            if(check(str[i]))
            {
                int j=0;
                for( j=0; j<a.size(); j++ ) if(a[j]==str[i]) break;
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
          }
            i++;
        }
    }


    if(st.top()==1) return "TRUE";
    else return "FALSE";
}

int main()
{
    string s;
    getline(cin , s);
cout<<Infix(s);
}