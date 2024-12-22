#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<stack>
#include<vector>

using namespace std;

bool check(string s)
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
            else if(check(str[i]))
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
          else if(check(str[i]))
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

int main()
{
    string s,x;
    getline(cin, s); getline(cin, x);
    cout<<LogicPostfixPrefixCalculator(s,x);
return 0;
}