#include<bits/stdc++.h>
#include<sstream>
#include<string>
using namespace std;

void H(string &s, int k, int n)
{
   int j=2*k+1;
   while(j<n)
   {
    if(j+1<n) if(s[j]>s[j+1]) j=j+1;
    if(s[k]<=s[j]) return;
    swap(s[k], s[j]);
    k=j;
    j=2*k+1;
   }
}

void buildH(string &s)
{
    int n=s.size();
   int i=(n-1)/2;
   while(i>=0)
   {
    H(s, i,  n);
    i--;
   }
}
void heapsort(string &s)
{
    buildH(s);
    int n=s.size();
    while(n>0)
    {
        n--;
        swap(s[0],s[n]);
        H(s, 0, n);
    }
}

int SUM(string s)
{
    int sum=0;
    for(int i=0; i< s.size(); i++)
    {
       sum+=(int)(s[i])-48; 
    }
    return sum;
}

void fix(string &s)
{
  if(SUM(s)%3==0) return;

  while(SUM(s)%3!=0)
  {
    int n=s.size();
     if(SUM(s)%3==2)
     {
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]%3==2)
            {
                for(int j=i; j<=n-2; j++)
                 s[j]=s[j+1];
                s.resize(--n);
                break;
            }
        }
     }
     if(SUM(s)%3==1)
     {
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]%3==1)
            {
                for(int j=i; j<=n-2; j++)
                 s[j]=s[j+1];
                 check=1;
                s.resize(--n);
                break;
            }
        }
     }
     if(SUM(s)%3==1||SUM(s)%3==2)
     {
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]%3==1||s[i]%3==2)
            {
                for(int j=i; j<=n-2; j++)
                 s[j]=s[j+1];
                s.resize(--n);
                break;
            }
        }
     }
  }
}

int main()
{
    string s;
    cin>>s;
    heapsort(s);
    fix(s);
    cout<<s;
}