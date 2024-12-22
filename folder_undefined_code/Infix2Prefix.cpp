// Infix2Prefix
#include<bits/stdc++.h>

using namespace std;

int thu_tu_dau(char t)
{
    if(t=='^') return 3;
    else if(t=='*'||t=='/') return 2;
    else if(t=='+'||t=='-') return 1;
    else if(t==')') return 0;
return 0;
}


string Infix2Prefix(string infix)
{
    int n=infix.size(); int i=n-1;
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

int main()
{
    string s;
    getline(cin, s);
    s=Infix2Prefix(s);
    cout<<s;
}