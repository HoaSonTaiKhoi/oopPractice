//sort
#include<bits/stdc++.h>
using namespace std;

void selectionsort(int *a, int n)
{
   int i, j, min;
   for(i=0; i<n; i++)
   {
     min=i;
     for(j=i+1; j<n; j++)
     if(a[min]>a[j]) min=j;
    swap(a[min], a[i]);
   }
}

void insertionsort(int *a, int n)
{
    int i=1, j, key;
    while(i<n)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>=key) {a[j+1]=a[j]; j--;}
 
        a[j+1]=key;
        i++;
    }
}

void inline heapify(int *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(a[j]>a[j+1]) j=j+1;
        if(a[k]<=a[j]) return;
        swap(a[k], a[j]);
        k=j; j=2*k+1;
    }
}

void buildheap(int *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        heapify(a, i, n);
        i--;
    }
}

void heapsort(int *a, int n)
{
    buildheap(a, n);
    while(n>0)
    {
        n--;
        swap(a[0], a[n]);
        heapify(a, 0, n);
    }
}

void quicksort(int *a, int l, int r)
{
    int e=a[(l+r)/2], i=l, j=r;
    while(i<=j)
    {
        while(a[i]<e) i++;
        while(a[j]>e) j--;
        if(i<=j) {swap(a[i], a[j]); i++; j--;} // phải có dấu = vì trường hợp nó trùng nhau
    }
    if(l<j) quicksort(a, l, j);
    if(i<r) quicksort(a, i, r);
}

int main()
{
    int n;
    cin>>n;
    int *a=new int [n];
    for(int i=0; i<n; i++) cin>>a[i];

    quicksort(a, 0, n-1);
    for(int i=0;i<n; i++) cout<<a[i]<<" ";
}