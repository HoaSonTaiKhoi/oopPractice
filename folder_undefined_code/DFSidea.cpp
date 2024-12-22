// DFS idea
#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
bool check_stack(stack<char> a , char s)
{
    while(!a.empty())
    {
        if(a.top()==s) return false;
        a.pop();
    }
    return true;
}

void step(int v, int e, map<char, int> v_index, map<int, char> a_index, vector<vector<int>> a, char t2, char t1)
{
    queue<char> open;
    vector<bool> close(v, 0);
    vector<int> dis(v,-1);
    map<char, vector<char>> parent;

    open.push(t1);
    close[v_index[t1]]=1;
    dis[v_index[t1]]=0;
    while(!open.empty())
    {
        char p=open.front(); open.pop();

        close[v_index[p]]=1;

        for(int i=0; i<v; i++)
        {
            if(close[i]==0&& a[v_index[p]][i]==1) 
            {
            a[v_index[p]][i]=0;
             //if(check_stack(open, a_index[i]))
             open.push(a_index[i]);
              parent[a_index[i]].push_back(p);
              dis[i]=dis[v_index[p]]+1;
              //cout<<p<<"->"<<a_index[i]<<"\n";
            }
        }
    }
    //if(found==0){cout<<"no_path\n"; return;}
    vector<char> path;
    if(dis[v_index[t2]]==-1) cout<<"no_path"<<endl;
    else
    {
        char p=t2;
        while(p!=t1)
        {
            path.push_back(p);
            p=parent[p][0];
        }
        path.push_back(t1);

        for(int i: path) cout<<(char)i<<" ";
        cout<<endl;
    }
}

int main()
{
    int v,e, th;
    cin>>v>>e;
    vector<vector<int>> a(v, vector<int> (v, 0));

    map<char, int> v_index;
    map<int, char> a_index;
    vector<pair<char, char>> b;
    
    char t1, t2;
    for(int i=0; i<v; i++)
    {
        cin>>t1;
        v_index[t1]=i;
        a_index[i]=t1;
    }

    for(int i=0; i<e; i++)
    {
        char t1, t2;
        cin>>t1>>t2;
        int index1=v_index[t1], index2=v_index[t2];
        a[index2][index1]+=1;
    }

    cin>>th;
    for(int i=0; i<th; i++)
    {
        cin>>t1>>t2;
        b.push_back({t1, t2});
    }
    
    for(int i=0; i<th; i++)
    {
        step(v,e,v_index, a_index, a, b[i].first, b[i].second);   
    }
    // for(int i=0; i<v; i++)
    // {
    //     for(int j=0; j<v; j++)
    //      cout<<a[i][j]<<" ";
    // cout<<"\n";
    // }
}