#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int>a;
int n;
int x;
int temp;
main()
{
    std::cin>>n;
    for(int i=0; i<n; i++)
    {
        std::cin>>temp;
        a.push_back(temp);
    }
    std::cin>>x;
    temp=0;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]==x) {std::cout<<i+1<<" "; temp+=1;}
    }
    if(temp==0) std::cout<<"NO";
return 0;
}