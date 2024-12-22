#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
int n;
std::vector<int> a;
int mark=0;
int t=-999;
int x, temp;
void maxxx(std::vector<int> a, int n, int x)
{
    int i=n-1;
    int j=0;
    while(i>=mark)
    {
        j=0;
        int sum=0;
        while(j<i)
        {
            sum=a[i]+a[j]; 
            if(sum>x) break;
            j++;
        }
        sum=a[i]+a[j-1];

        if(sum==x) {std::cout<<x; return;}
        else if(sum<x) 
        {
            if(t<sum) t=sum;
        } 
        i--;
        mark=j-1;
    }
    std::cout<<t;
return;
}

main()
{
    std::cin>>n; std::cin>>x;
    for(int i=0; i< n; i++) 
    {
        std::cin>>temp;
        a.push_back(temp);
    }
    std::sort(a.begin(), a.end());
    maxxx(a, n, x);
return 0;
}