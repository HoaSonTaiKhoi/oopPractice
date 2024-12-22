#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void Data(vector<int> &a)
{
    ifstream in("chuoi.txt");
    while(!in.eof())
    {
        int s;
        in>>s;
        a.push_back(s);
    }
}

void Data_out(vector<int> a)
{
    for(int i=0; i< a.size(); i++)
    cout<<a[i]<<" ";

cout<<endl;
    sort(a.begin(), a.end());
    for(vector<int>:: iterator i=a.begin(); i<a.end(); i++)
     cout<<*i<<" ";
}
void Top_5(vector<int> a)
{
    sort(a.begin(), a.end());
    for(vector<int>::iterator i=a.end()-1; i>a.end()-6; i--) cout<<*i<<" ";
}

int TimKiem_TuyenTinh(vector<int> a, int k)
{
    int i=0;
    while(i<a.size())
    {
        if(a[i]==k) return i;
        i++;
    }
    return -1;
}
int TimKiem_TuyenTinhNew(vector<int> a, int k)
{
    int i=0;
    a.push_back(k);
    while(a[i]!=k)
    {
        i++;
    }
    if(i<a.size()-1) return i;
    else return -1;
}

int TimKiem_NhiPhan(vector<int>a, int k)
{
    sort(a.begin(), a.end());
    int l=0; int r=a.size()-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(k==a[m]) return m; 
        else if (k>a[m]) {l=m+1;  if(a[r]==k) return r;}
        else if(k<a[m]) {r=m-1; if(a[l]==k) return l;}
    }
    return -1;
}

void sapxep_nhiphan(vector<int>a)
{

}

int TimKiem_NoiSuy(vector<int> a, int k)
{
    sort(a.begin(), a.end());
    int l=0; int r=a.size()-1;
    while(l<=r)
    {
        int m=l+(r-l)*(k-a[l])/(a[r]-a[l]);
        if(a[m]==k) return m;
        else if(a[m]<k) l=m+1;
        else r=m-1;
    }
    return -1;
}
main()
{
    vector<int> a;
    Data(a);
    Data_out(a);
    cout<<endl;
    Top_5(a);
    cout<<endl;
    int k;
    cin>>k;
    cout<<TimKiem_NhiPhan(a,k);
    cout<<endl;
    cout<<TimKiem_NoiSuy(a, k);
}