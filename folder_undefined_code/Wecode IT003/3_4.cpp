#include<bits/stdc++.h>
using namespace std;

map<string, string> H;
    int n,m,q, i;
    string tmp, t1, t2;
    vector<string> a;
int main()
{
    
    cin>>n>>q;
    getchar();
    for(i=0; i<n; i++)
    {
        cin>>t1;
        getchar();
        cin>>t2;
        H[t1]=t2;
        getchar();
    }

    for(i=0; i<q; i++)
    {
        cin>>t1;
        a.push_back(t1);
        getchar();
    }
    for(i=0; i<q; i++)
     {
        if(H.count(a[i])>0) 
        {
            cout<<H[a[i]]<<"\n";
        }
        else cout<<"Chua Dang Ky!\n";
     }
    return 0;
}