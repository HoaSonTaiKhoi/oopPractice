#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, temp;
    cin>>n>>m;
    int *a=new int [n+1];
    int *b=new int [m];
    int *c=new int [m];
    for(int i=0; i<n+1; i++) a[i]=0;
    for(int i=0; i<m; i++)
     {
        cin>>b[i];
     }
    int k=0;
    for(int i=m-1; i>=0; i--)
    {
        if(a[b[i]]==0) 
        {
          c[k++]=b[i];
          a[b[i]]++;
        }

    }
    for(int i=0; i<k; i++)
    {
        cout<<c[i]<<" ";
    }
    for(int i=1; i< n+1 ; i++)
    {
        if(a[i]==0) cout<<i<<" ";
    }
     return 0;

}