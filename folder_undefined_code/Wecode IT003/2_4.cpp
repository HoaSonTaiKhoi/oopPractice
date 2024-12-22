#include<bits/stdc++.h>
#include<string>

using namespace std;
string s,t;
int i=0; int ct=0; vector<int>a;
size_t f=0;
int main()
{
    
    cin>>s;
    cin.ignore();
    cin>>t;
    while(true)
    {
        f=s.find(t, f);
        if(f!=string::npos)
        {
           a.push_back(f+1);
           ct++;
           f+=1;
        }
        else break;
    }
    if(ct !=0)
    {
        cout<<"YES\n";
        for(i=0; i<a.size(); i++) cout<<a[i]<<" ";
    }
    else cout<<"NO";
return 0;
}