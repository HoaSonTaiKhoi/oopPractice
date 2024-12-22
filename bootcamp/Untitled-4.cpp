#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

int main()
{
    std::vector<int> a1={0,1,2,3,4};
    auto a2=a1;
    std:: for_each(a2.begin(), a2.end(), [](int &x){x=x*x;});
    for(auto x: a1) std::cout<<x<<" ";
    std::cout<<"\n";
    for(std::vector<int>::iterator i=a2.begin(); i!=a2.end(); i++)
     std::cout<<*i<<" ";
return 0;
}