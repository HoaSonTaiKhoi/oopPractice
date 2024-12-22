#include<bits/stdc++.h>

std::string a;
std::string b;
int m, n,i;
main()
{
   std::cin>>a>>b;
   m=a.size();
   n=b.size();
    if(m<n) std::cout<<n;
    else
    {
        int s=-2;
        for(i=0; i<n; i++)
        {
            if(a[i]!=b[i]) {s=i;break;}
        }    
        if(s<0) std::cout<<0;
        else std::cout<<n-i;
    }
return 0;
}