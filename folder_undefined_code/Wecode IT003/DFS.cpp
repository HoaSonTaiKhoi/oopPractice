
#include<bits/stdc++.h>
using namespace std;

void Input(map<string, int> v_index, map<int, string> a_index, vector<vector<int>> matran, int v, int e)
{
    stack<string> st;
    vector<bool> close(v,0);
    vector<string> path;

    string s; cin>>s;
    st.push(s);

    while(!st.empty())
    {
        string p=st.top(); st.pop();
         close[v_index[p]]=1;
        vector<string> dinhke;

        for(int i=0; i<v; i++)
        {
            if(matran[v_index[p]][i]==1) dinhke.push_back(a_index[i]);
        }
        for(int i=0; i<dinhke.size();i++)
        {
            if(close[v_index[dinhke[i]]]==0) st.push(dinhke[i]);
        }
        path.push_back(p);
    }

    for(int i=0; i<path.size(); i++)
     cout<<path[i]<<" ";
}

int main()
{
    int e,v;
    cin>>e>>v;
    vector<vector<int>> matran(v, vector<int>(v,0));
    map<string, int> v_index;
    map<int, string> a_index;
    string t1, t2;
    for(int i=0; i<v; i++)
    {
        cin>>t1;
        v_index[t1]=i;
        a_index[i]=t1;
    }

    for(int i=0; i<e; i++)
    {
        cin>>t1>>t2;
        int i1=v_index[t1], i2=v_index[t2];
        matran[i1][i2]=1;
    }

    Input(v_index, a_index, matran, v, e);

return 0;

}