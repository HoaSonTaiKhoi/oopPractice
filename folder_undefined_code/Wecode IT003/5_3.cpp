
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;

    map<string,vector<string>> m;

    for(int i=0; i<n; i++)
    {
        string t1, t2;
        cin>>t1>>t2;
        m[t1].push_back(t2);
    }


string tmp;
vector<string> t;
for(int i=0; i<q; i++)
    {
        cin>>tmp;
        t.push_back(tmp);
    }

for(int i=0; i<q; i++)
    {
        if(m.count(t[i])>0)
        {
            for(int j=0; j<m[t[i]].size(); j++)
            {
                cout<<m[t[i]][j];
                if(j!=m[t[i]].size()-1) cout<<" ";
            }
        }
        else cout<<"Chua Dang Ky!";
cout<<endl;
    }
    return 0;
}