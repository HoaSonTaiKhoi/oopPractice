
#include<iostream>
#include<vector>
#include<string.h>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

bool isPath(int v, map<string, int> v_index, vector<vector<int>> a, string t1,string t2)
{
    if(a[v_index[t1]][v_index[t2]]!=0) return true;
    bool path1=0, path2=0;
    for(int i=0; i<v; i++) if(a[v_index[t1]][i]!=0) {path1=1; break;}
    for(int i=0; i<v; i++) if(a[i][v_index[t2]]!=0) {path2=1; break;}

    if(path1&& path2) return true;
    return false;
}

void step(int v, int e, map<string, int> v_index, map<int, string> a_index, vector<vector<int>> a, string t1, string t2)
{
    queue<string> open;
    stack<string> path;
    map<string, queue<string>> parent;

    if(!isPath(v, v_index, a, t1, t2)) {cout<<"no_path"<<endl; return;}

    int index1=v_index[t1], index2=v_index[t2]; 
    path.push(t2);
    while(true)
    {
       int i; 
        if(a[index1][index2]!=0) {path.push(t1); break;}
        for(i=v-1; i>=0; i--)
        {
            if(a[i][index2]!=0){a[i][index2]=0; break;}
        }
        path.push(a_index[i]);
        if(i==index1) break;
        index2=i;
    }
    while(!path.empty())
    {
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<endl;
}

int main()
{
    int v,e, th;
    cin>>v>>e;
    vector<vector<int>> a(v, vector<int> (v, 0));

    map<string, int> v_index;
    map<int, string> a_index;
    vector<pair<string, string>> b;
    
    string t1, t2;
    for(int i=0; i<v; i++)
    {
        cin>>t1;
        v_index[t1]=i;
        a_index[i]=t1;
    }

    for(int i=0; i<e; i++)
    {
        string t1, t2;
        cin>>t1>>t2;
        int index1=v_index[t1], index2=v_index[t2];
        a[index1][index2]+=1;
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