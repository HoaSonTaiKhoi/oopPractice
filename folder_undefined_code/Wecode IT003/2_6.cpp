#include<bits/stdc++.h>
#include<algorithm>
#include<vector>

struct DIEM
{
    int x, y;
};
int i, j, min;
void H(DIEM *a, int k, int n)
{
    j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
        {
            if(a[j].x<a[j+1].x) j=j+1;
            else if(a[j].x==a[j+1].x)
            {
                if(a[j].y>a[j+1].y) j=j+1;
            }
        }
        if(a[k].x>a[j].x||(a[k].x==a[j].x&& a[k].y<=a[j].y)) return;
        std::swap(a[k].x,a[j].x);
        std::swap(a[k].y,a[j].y);
        k=j;
        j=2*k+1;
    }
}
void buildH(DIEM *a, int n)
{
    i=(n-1)/2;
    while(i>=0)
    {
        H(a, i,n);
        i--;
    }
}
void Sapxep(DIEM *a, int n)
{
    buildH(a, n);
    while(n>0)
    {
        n=n-1;
        std::swap(a[0].x, a[n].x);
        std::swap(a[0].y, a[n].y);
        H(a, 0, n);
    }
}
int n;
int main()
{
    
    std::cin>>n;
    DIEM a[n];
    for(int i=0; i< n; i++)
     {
        std::cin>>a[i].x>>a[i].y;
     }
    Sapxep(a,n);
    for(int i=0; i<n; i++)
    {
        std::cout<<a[i].x<<" "<<a[i].y<<"\n";
    }
return 0;
}