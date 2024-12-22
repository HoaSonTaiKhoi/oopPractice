#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
std::vector<pair<int, int>> a;
int  n;
int temp;
int temp1;

bool cmp(vector<pair<int,int>> a, int i)
{
    if(a[i].first>a[i+1].first) return true;
    else if(a[i].first==a[i+1].first)
    {
        if(a[i].second>a[i+1].second) return true;
        else return false;
    }
    return false;
}


int main()
{
    std::cin>>n;
    for(int i=0;i<n ;i++)
    {
        std::cin>>temp>>temp1; 
        a.push_back({temp, temp1});
    }
    sort(a.begin(), a.end(), cmp(a, 0));
    for(auto x:a) std::cout<<x.first<<" "<<x.second<<" ";
return 0;


}