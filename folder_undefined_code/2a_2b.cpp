

#include<bits/stdc++.h>
using namespace std;

int thu_tu(string t)
{
    if(t=="<->" || t=="->") return 2;
    else if(t=="&"||t=="|"||t=="~") return 1;
    else if(t=="("||t==")") return 0;
    return 0;
}

vector<string> Prefix(string s)
{
    vector<string> ss; int i=0;
    while(i<s.size())
    {
        
        if(s[i]=='-'||s[i]=='<')
        {
            string tmp;
            while(s[i]!='>')
            {
                tmp.push_back(s[i]);
                i++;
            }
            tmp.push_back(s[i]);
            ss.push_back(tmp);
        }
        else
        {
            string tmp; tmp.push_back(s[i]);
            ss.push_back(tmp);
        }
        i++;
    }

    int n=ss.size();
    i=n-1;
    stack<string> st;
    vector<string> str;
    while(i>=0)
    {
        if(ss[i]==")") {st.push(ss[i]); i--;}
        else if(ss[i]=="(")
        {
            while(st.top()!=")")
            {
                str.insert(str.begin(), st.top());
                st.pop();
            }
            st.pop();
            i--;
        }
        else if(ss[i]>="a"&& ss[i]<="z")
        {
            str.insert(str.begin(), ss[i]);
            i--;
        }
        else
        {
            while(!st.empty()&&(thu_tu(st.top())>thu_tu(ss[i])))
            {
                str.insert(str.begin(), st.top());
                st.pop();
            }
            st.push(ss[i]); i--;
        }
    }
    while(!st.empty())
    {
        str.insert(str.begin(), st.top());
        st.pop();
    }
    return str;
}

int main()
{
    string s;
    getline(cin, s);
    vector<string> ss=Prefix(s);
    for(int i=0; i<ss.size(); i++) cout<<ss[i]<<" ";
}