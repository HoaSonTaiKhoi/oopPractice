#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Hang
{
    string x;
    int y;
};

int c(string s1, string s2)
{
    if(s1.size()<s2.size()) return -1;
    else if(s1.size()==s2.size()) 
    {
        if(s1<s2) return -1;
        else return 1;
    }
    else return 1;
}
void H(vector<string>&a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(c(a[j], a[j+1])<0) j=j+1;
        if(c(a[k],a[j])>=0) return;
        swap(a[k],a[j]);
        k=j;
        j=2*k+1;
    }
}
void build(vector<string> &a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        H(a, i, n);
        i--;
    }
}

void s1(vector<string>&a, int n)
{
    build(a, n);
    while(n>0)
    {
        n--;
        swap(a[0], a[n]);
        H(a, 0, n);
    }
}

void HH(Hang *b, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) 
        {
            if(b[j].y>b[j+1].y) j=j+1;
            else if(b[j].y==b[j+1].y) if(c(b[j].x, b[j+1].x)<0)j=j+1;
        }
        if(b[k].y<b[j].y||(b[k].y==b[j].y&& c(b[k].x, b[j].x)>=0)) return;
        swap(b[k].x, b[j].x);
        swap(b[k].y, b[j].y);
        k=j;
        j=2*k+1;
    }
}
void build1(Hang*b, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        HH(b, i, n);
        i--;
    }
}
void s2(Hang *b, int n)
{
    build1(b, n);
    while(n>0)
    {
        n--;
        swap(b[0].x, b[n].x);
        swap(b[0].y, b[n].y);
        HH(b, 0, n);
    }
}

string temp;
int main()
{
    int n; cin>>n;
    vector<string>a;
    for(int i=0;i<n; i++)
    {
     cin>>temp; a.push_back(temp);
    }
    s1(a, n);
    Hang *b=new Hang[n];
    int k=1;
    temp=a[0]; b[0].x=a[0]; b[0].y=1;
    for(int i=1; i<n; i++)
    {
        if(a[i]!=temp)
        {
            b[k].x=a[i];
            b[k].y=1;
            temp=a[i];
            k++;
        }
        else b[k-1].y++;
    }
    s2(b, k);
    for(int i=0; i<k;i++)
    {
        cout<<b[i].x<<" "<<b[i].y<<"\n";
    }
return 0;
}