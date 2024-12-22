#include<bits/stdc++.h>
#include<string>
#include<sstream>

using std::cin;
using std::cout;
using std::swap;
using std::string;

void H(string *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        swap(a[k], a[j]);
        k=j;
        j=2*k+1;
    }
}
void build(string *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        H(a, i, n);
        i--;
    }
}

void sapxep(string *a, int n)
{
    build(a, n);
    while(n>0)
    {
        n--;
        swap(a[0], a[n]);
        H(a, 0, n);
    }
}
int ct=1;
int main()
{
   int n; cin>>n; string a[n];
   for(int i=0; i< n; i++)
   {
     cin>>a[i];
   }
   sapxep(a, n);
   string temp;
   temp =a[0];
   for(int i=0; i<n; i++)
   {
      if(a[i]!=temp) 
      {
        ct++;
        temp=a[i];
      }
   }
   cout<<ct;
return 0;

}