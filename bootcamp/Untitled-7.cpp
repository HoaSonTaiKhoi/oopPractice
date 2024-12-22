#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<string>

using namespace std;




int main()
{
  int x=0, y=0;
    vector<int> a;

    vector<string> b;
    string e; string s;
    string temp;
    getline(cin, temp);
    stringstream in(temp);
while(!in.eof())
   {
     getline(in, e, ' ');
     getline(in, s,' ');
     int t=atoi(e.c_str());
     if(s=="-4") x+=t;
     else if(s=="-3") y-=t;
     else if(s=="-2") x-=t;
     else if(s=="-1") y+=t; 
   }
    if(y>0) cout<<abs(y)<<" -1"<<" ";
    else if(y<0) cout<<abs(y)<<" -3"<<" ";
    if(x>0) cout<<abs(x)<<" -4";
    else if(x<0) cout<<abs(x)<<" -2";
return 0;
}