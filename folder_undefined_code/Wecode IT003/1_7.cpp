#include<iostream>
#include<vector>
#include<algorithm>
std::vector<std::pair<int, int>> a;
int n;
int temp1, temp2;
int i;
bool cmp(std::pair<int, int>a, std::pair<int, int>b)
{
    if(a.first==b.first)
    {
       return a.second>b.second;
    }
    else return a.first<b.first;
}
main()
{
   std::cin>>n;
   for(i=0; i< n; i++)
   {
    std::cin>>temp1;
    std::cin>>temp2;
    a.push_back({temp1, temp2});
   }
   sort(a.begin(), a.end(), cmp);
   for(i=0; i<a.size(); i++) std::cout<<a[i].first<<" "<<a[i].second<<"\n";
   return 0;
   
}
//struct cũng được