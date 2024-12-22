
#include<bits/stdc++.h>
#include<string.h>
#include<sstream>
#include<iomanip>
using namespace std;


bool check(string c)
{
    if(c!="*" && c!="/" && c!="+" && c!="-" && c!="^") return true;
    return false;
}

string PostfixPrefixCalculator(string input){
    stringstream ss(input);
    stack<double> st;
    string tmp;

    vector<string> str;
        while(ss>>tmp)
        {
            str.push_back(tmp);
        }
        
    int n=str.size();
    if(input[0]>'9'||input[0]<'0')
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

int main()
{
    string s;
    getline(cin, s);
    
    cout<<PostfixPrefixCalculator(s);
}