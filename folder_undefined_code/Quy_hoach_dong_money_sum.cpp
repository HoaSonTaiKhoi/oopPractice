
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int main()
{
    int n, i, j, temp, sum=0;
    vector<int> value;

cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>temp;
        sum+=temp;
        value.push_back(temp);
    }
    //sort(value.begin(), value.end());


    vector<vector<int>> d(n+1, vector<int>(sum+1, 0));
    set<int> ans;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=sum; j++)
        {
            if(j<value[i-1])
            {
                d[i][j]=d[i-1][j];
            }
            else
            {
                d[i][j]=max(d[i-1][j], d[i-1][j-value[i-1]]+value[i-1]);
             if(d[i][j]!=j) d[i][j]=0;
            }
            if(d[i][j]!=0) ans.insert(j);
        }
    }

    cout<<ans.size()<<"\n";
    for(set<int>::iterator e= ans.begin(); e!=ans.end(); e++) cout<<*e<<" ";
return 0;
}