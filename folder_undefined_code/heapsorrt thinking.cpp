
#include<iostream>
using namespace std;

int heapify(int *a, int k, int n)
{
    int count=0;
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return 0;
        swap(a[k],a[j]); count++;
        k=j; j=2*k+1;
    }
return count;
}

int buildHeap(int* a,int n)
{
     int count=0;
    int i=(n-1)/2;
    while(i>=0)
    {
        count+=heapify(a, i, n);
        i--;
    }
    return count;
}

void heapsort(int*a, int n)
{

    if(n==0)
    {
        cout<<"N= "<<0<<"\n"
            <<"swap: "<<0;
        return;
    }
    int m=n, count=0;
    cout<<"N="<<m<<": "; for(int i=0; i<n; i++) cout<<a[i]<<"\t";
    count=buildHeap(a, m);
    cout<<"\nswap: "<<count<<"\n";

    while(m>0)
    {
        m--;
        swap(a[0], a[m]);
       if(m!=0) 
       {
        cout<<"N="<<m<<": ";
        for(int i=0; i<n; i++) cout<<a[i]<<"\t";
       }
        count=heapify(a, 0, m);
        if(m!=0)cout<<"\nswap: "<<count<<"\n";
    }
}

int main()
{
    int *a,x, n=0;
    cin>>x;
    while(x!=-1)
    {
        a[n]=x;
        n++;
        cin>>x;
    }
    heapsort(a,n);
return 0;
}