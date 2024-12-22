#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::swap;

void H(int* a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        swap(a[k],a[j]);
        k=j;
        j=2*k+1; 
    }
}
void build(int *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        H(a, i, n);
        i--;
    }
}

void sapxep(int *a , int n)
{
    build(a,n);
    while(n>0)
    {
        n--;
        swap(a[0], a[n]);
        H(a, 0, n);
    }
}



int e=0;
int k;
int n;
int j, count, temp;
void Xuat(int *x)
{
    for(int i=0; i<k; i++)
    {
        cout<<x[i]<<" ";
    }
}
void loop(int *a, int m, int*x)
{
    int y[m];
     j=0;
     count=0;
     temp=a[0];x[e++]=a[0];
    for(int i=1; i<m ; i++)
    {
        if(a[i]==temp) y[j++]=a[i];
        else
        { 
            if(e==k) break;
            x[e++]=a[i];
            temp=a[i];
        }
    }
    if(e>=k)
    {
        sapxep(x,e);
        Xuat(x);
        return;
    }
    loop(y, j, x);
return;
}


int main()
{
   cin>>n>>k;
   int a[n]; int x[n];
   for(int i=0; i<n; i++) cin>>a[i];
   sapxep(a, n);
   loop(a,n,x);
}