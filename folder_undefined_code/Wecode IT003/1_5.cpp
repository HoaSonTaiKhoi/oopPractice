#include<bits/stdc++.h>
#include<vector>

std::vector<int> a;
int n;
int i;
int H=0;
int temp;
    
int main()
{
    std::cin>>n;
    for(i=0; i< n; i++)
    {
        std::cin>>temp;
        a.push_back(temp);
    }
    
    std::vector<int>b(n+1);
    for(i=0; i<n; i++)
    {
        temp=a[i];
        if(temp>=n) b[n]++;
        else b[temp]++;
    }
    for(i=n; i>=0; i--)
    {
        H+=b[i];
        if(H>=i) {break;}
    }
   std::cout<<i;
return 0;
}
