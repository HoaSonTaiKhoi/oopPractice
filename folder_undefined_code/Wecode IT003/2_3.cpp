#include<bits/stdc++.h>

struct D
{
    int x, y, z ;
};
int i,j;
void H(D *a, int k, int n)
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
                else if(a[j].y==a[j+1].y)
                {
                    if(a[j].z<a[j+1].z) j=j+1;
                }
            }
        }
        if(a[k].x>a[j].x||(a[k].x==a[j].x&&a[k].y<a[j].y)||(a[k].x==a[j].x&&a[k].y==a[j].y&&a[k].z>a[j].z)) return;
        std::swap(a[k].x, a[j].x);
        std::swap(a[k].y, a[j].y);
        std::swap(a[k].z, a[j].z);
        k=j;
        j=2*k+1;
    }
}

void buildH(D *a, int n)
{
    i=(n-1)/2;
    while(i>=0)
    {
        H(a, i, n);
        i--;
    }
}

void Sapxep(D *a, int n)
{
    buildH(a, n);
    while(n>0)
    {
        n--;
        std::swap(a[0].x, a[n].x);
        std::swap(a[0].y, a[n].y);
        std::swap(a[0].z, a[n].z);
        H(a,0, n);
    }
}
int n;
int main()
{
   std::cin>>n;
   D a[n];
   for(int e=0; e<n; e++)
    std::cin>>a[e].x>>a[e].y>>a[e].z;
    Sapxep(a,n);
    for(int e=0; e<n; e++)
    std::cout<<a[e].x<<" "<<a[e].y<<" "<<a[e].z<<"\n";
return 0;
}