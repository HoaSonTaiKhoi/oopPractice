#include<bits/stdc++.h>
using namespace std;

void Input(int v, map<string, int> v_index, int e, vector<vector<int>>G)
{
    map<int, string> b_index;
    string tmp;
    for(int i=0; i<v; i++)
    {
        cin>>tmp;
        v_index[tmp]=i;
        b_index[i]=tmp;
    }

string t1,t2; int g;
    for(int i=0; i<e; i++)
    {
        cin>>t1>>t2>>g;
        int id1=v_index[t1], id2=v_index[t2];
        G[id1][id2]=1;
    }

    int k; cin>>k;
    vector<int> a(v,0);
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
         {a[i]+=G[i][j]; a[i]+=G[j][i];}
    }
    // for(int i=0; i<v; i++)
    // cout<<a[i]<<" ";

    if(find(a.begin(), a.end(), k)!=a.end())
    {
      for(int i=0; i<v; i++)
      {
        if(k==a[i]) cout<<b_index[i]<<" ";
      }
    }
    else cout<<"No find";
}

int main()
{
    	int v,e; //v là số đỉnh, e là số cạnh
	cin>>e>>v;
	vector<vector<int>> G (v,vector<int>(v,0)); // ma trận kề
	map<string, int> v_index; // Danh sách ánh xạ tên đỉnh --> index
	Input(v,v_index,e,G);
	return 0;
}
