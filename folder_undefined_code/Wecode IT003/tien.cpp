
#include<bits/stdc++.h>

using namespace std;

int main()
{
    set<long long> tien;

    int  n; cin>>n;
    for(int i=0; i< n; i++)
    {
        long long x; cin>>x;
        tien.insert(x);
    }
    cout<<tien.size()<<"\n";
    for(set<long long>::iterator i= tien.begin(); i!=tien.end(); i++)
    {
        cout<<*i<<" ";
    }
return 0;
}