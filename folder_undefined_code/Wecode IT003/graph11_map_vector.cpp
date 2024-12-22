#include<bits/stdc++.h>
using namespace std;

void Input(int v, map<string, int>v_index, int e,vector<vector<int>> G)
{
string tmp;
    for(int i=0; i<v; i++)
    {
        cin>>tmp;
        v_index[tmp]=i;
    }
    for(int i=0; i<e;i++)
    {
        string t1, t2; int e;
        cin>>t1>>t2>>e;
        int index1=v_index[t1], index2=v_index[t2]; 
        G[index1][index2]=e;
    }

    for(int i=0;i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cout<<G[i][j]<<" ";
        }
        cout<<"\n";
    }
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
