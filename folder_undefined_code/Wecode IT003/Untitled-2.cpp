
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> a (n, vector<int> (n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x; cin>>x;
            a[i][j]=x;
        }
    }

    map<int, vector<int>> b;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j]==1) b[i+1].push_back(j+1);
        }
    }

    for(map<int, vector<int>>::iterator i=b.begin(); i!=b.end(); i++)
    {
        cout<<i->first<<"->";
        for(int j=0; j<i->second.size(); j++)
         cout<<i->second[j]<<" ";
        cout<<endl;
    }
    return 0;
}