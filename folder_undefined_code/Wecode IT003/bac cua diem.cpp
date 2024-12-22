 
#include<iostream>
#include<map>
#include<set>
using namespace std;

void Input(map<int,set<int>> number_list, int n)
{
    cin>>n;

    int a,b;
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        number_list[a].insert(b);
    }
int x; cin>>x;
    int num=0;
    for(map<int,set<int>>::iterator i=number_list.begin(); i!=number_list.end(); i++)
    {
        cout<<i->first<<"\t";
        for(set<int>::iterator j= i->second.begin(); j!=i->second.end(); j++)
        {
        if(x==*j) num++;
        cout<<*j<<" ";
        if(i->first==x) num++;
        }
        cout<<"\n";
    }
cout<<num<<endl;
}

int main()
{
	map<int,set<int>> number_list;
	int n;
	Input(number_list,n);
	return 0;
}
