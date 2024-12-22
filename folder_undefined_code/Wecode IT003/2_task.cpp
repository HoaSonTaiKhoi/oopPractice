#include<bits/stdc++.h>
using std::cin;
using std::cout;

int n, k, p, q, u,v ;

int main()
{
    cin>>n>>k>>p>>q;
    int vt=2*(p-1)+q;
    if (vt>k) 
    {
        vt-=k;
      if(vt%2==0)
       cout<<vt/2<<" "<<2;
    else
     cout<<vt/2+1<<" "<<1;
    }
    else 
    {
        vt+=k;
        if(vt >n) cout<<-1;
        else if(vt%2==0) cout<<vt/2<<" "<<2;
        else cout<<vt/2+1<<" "<<1;
    }
return 0;
}