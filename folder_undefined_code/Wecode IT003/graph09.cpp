 
#include<iostream>
#include<map>
#include<set>
using namespace std;

void Input(map<int, set<int>> list, int n)
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        list[a].insert(b);
    }
    int x,y, check=0; cin>>x>>y;
    set<int>::iterator i;
    if(list[x].count(y)!=0) cout<<y<<" la dinh ke cua dinh "<<x;
    else if(list[y].count(x)!=0) cout<<x<<" la dinh ke cua dinh "<<y;
    else cout<<"2 dinh khong ke nhau";
}

int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
