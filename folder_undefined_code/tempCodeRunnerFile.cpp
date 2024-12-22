#include<iostream>
#include<vector>

int n, i=0, j=0, maxi=-1;
long long *a;

int main()
{
    std::cin>>n;
    a=new long long [n];
    std::vector<int> L(n, 0);
    for(i=0; i<n; i++) std::cin>>a[i];

    maxi=1;
    L[0]=a[0];
    for(i=1; i<n ; i++)
    {
        if(a[i]>L[maxi-1]){ L[maxi]=a[i]; maxi++;}
        else if (a[i]<=L[0]) L[0]=a[i];
        else
        {
            int u=1, v=maxi, r;
            while(v-u>1)
            {
                r=(u+v)/2;
                if(a[i]>L[r]) u=r;
                else v=r;
            }
            L[v]=a[i];
        }
    }

    std::cout<<maxi-1;
return 0;
}