#include<bits/stdc++.h>
using namespace std;

int x[100];
int n, k;
void Xuat()
{
    for(int i=0; i<k; i++)
    {
        cout<<x[i]<<" ";
    }
    cout<<"\n";
}
void Try(int c)
{
   for(int j=1; j<=n; j++)
   {
     if(c==0) x[c]=j;
     else 
     {
       x[c]=j; 
       while(x[c]<=x[c-1]&&j+1<=n) {x[c]++; j++;}
     }
     if(c==k-1) Xuat();
     else if(x[c]<n) Try(c+1);
   }
}

int main()
{
   cin>>n;
   cin>>k;
   Try(0);
return 0;
}