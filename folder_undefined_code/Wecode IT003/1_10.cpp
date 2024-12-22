#include<iostream>
#include<vector>
#include<algorithm>

std::vector<int> a;
std::vector<int> x;
int n, q, e;
int l=0; int check=0;
int r=a.size()-1;
void  binarySearch(std::vector<int> a, std::vector<int>x)
{
    for(int i=0; i<x.size(); i++)
    {
    l=0; r=a.size()-1;
    check=0;
    while(l<=r)
    {
        if(a[l]==x[i]) {check=1; break;}
        else if(a[r]==x[i]) {check=1; break;}
        int m=(l+r)/2;
        if(a[m]==x[i]) {check=1; break;}
        else if(a[m]>x[i]) r=m-1;
        else l=m+1;
    }
     if(check==1) std::cout<<"YES"<<"\n";
     else std::cout<<"NO"<<"\n";
    }
}



int main()
{
    
    std::cin>>n>>q;
    for(int i=0; i<n; i++)
     {
         std::cin>>e;
        a.push_back(e);
     }
    for(int i=0; i<q; i++)
     {
        std::cin>>e;
        x.push_back(e);
     }
    sort(a.begin(), a.end());
    binarySearch(a,x);
return 0;
}