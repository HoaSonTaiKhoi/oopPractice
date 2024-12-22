#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
bool cmp(int a, int b)
{
    return a>b;
}
int main(){
    std::vector<int> a;
    int temp;std::cin>>temp;
    while(temp!=0)
    {
        a.push_back(temp);
        std::cin>>temp;
    }
    sort(a.begin(), a.end(), cmp);
    std::vector<std::pair<int, int>> b;
    b.push_back({a[0], 1});
    int k=0;
    for(int i=1; i< a.size(); i++)
    {
        if(a[i]==b[k].first)
        {
           b[k].second+=1;
        }
        else if(a[i]!=b[k].first)
        {
            k++;
            b.resize(k+1);
            b[k].first=a[i];
            b[k].second=1;
        }
    }
    for(auto x:b) std::cout<<x.first<<" "<<x.second<<"\n";
return 0;
}