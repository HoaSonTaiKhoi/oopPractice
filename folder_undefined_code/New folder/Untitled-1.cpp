#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void Nhapdanhsach(vector<int> &v)
{
    int tmp;
    cin>>tmp;
    while(tmp>0)
    {
        v.push_back(tmp);
        cin>>tmp;
    }
}
void indanhsach(vector<int> &v)
{
    for(int i=0; i<v.size(); i++)
     cout<<v[i]<<" ";
    cout<<endl;
}
void sapxep(vector<int> v)
{
    sort(v.begin(), v.end());
    indanhsach(v);
}
void Top_5(vector<int> v)
{
    sort(v.begin(), v. end());
    if(v.size()<5) {cout<<"No!"; return ;}
    for(vector<int>::iterator i=v.end()-1; i> v.end()-6; i--)
     cout<<*i<<" ";
}
int tim_K(vector<int> v)
{
    int k;
    cin>>k;
    vector<int> ::iterator i;
    i= find(v.begin(), v.end(), k);
    if(i!=v.end()) return i-v.begin();
 return -1;
}

main()
{
    vector<int> v;
    Nhapdanhsach(v);
    indanhsach(v);
    sapxep(v);
    Top_5(v);
   cout<<tim_K(v);
return 0;
}