// Infix
#include<bits/stdc++.h>
#include<string.h>
#include<sstream>

using namespace std;


bool check(string c)
{
    if(c!="*" && c!="/" && c!="+" && c!="-") return true;
    return false;
}

void Infix(string s)
{
    int n=s.size();
    stringstream ss(s);
    stack<string> st;
    string tmp;

    vector<string> str;
        while(ss>>tmp)
        {
            str.push_back(tmp);
        }
    if(s[0]>'9'||s[0]<'0')
    {
        for(int i=str.size()-1; i>=0; i--)
        {
            if(check(str[i])) st.push(str[i]);
          else
          {
            int a=atoi(st.top().c_str());
            st.pop();
            int b=atoi(st.top().c_str());
            st.pop();
            if(str[i]=="*") st.push(to_string(a*b));
            else if(str[i]=="/") st.push(to_string(a/b));
            else if(str[i]=="+") st.push(to_string(a+b));
            else if(str[i]=="-") st.push(to_string(a-b));
          }
        }
    }
    else
    {
        
        //Postfix
        for(int i=0; i<str.size(); i++)
        {
          if(check(str[i])) st.push(str[i]);
          else
           {
            int a=atoi(st.top().c_str());
            st.pop();
            int b=atoi(st.top().c_str());
            st.pop();
            if(str[i]=="*") st.push(to_string(a*b));
            else if(str[i]=="/") st.push(to_string(b/a));
            else if(str[i]=="+") st.push(to_string(a+b));
            else if(str[i]=="-") st.push(to_string(b-a));
          }
        }
    }
    cout<<st.top();
    
}

int main()
{
    string s;
    getline(cin, s);
    Infix(s);
}