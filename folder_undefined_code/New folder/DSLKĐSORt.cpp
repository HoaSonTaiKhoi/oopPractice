#include<bits/stdc++.h>
#include<algorithm>
#include<time.h>


void heap(int a[], int i, int n)
{
    int e=2*i+1;
    while(e<n)
    {
        if(e+1<n) if(a[e]<a[e+1]) e=e+1;
        if(a[i]<a[e]) std::swap(a[i], a[e]);
        i=e;
        e=2*i+1;
    }
}

void HeapSort(int a[], int n)
{
    int i=n/2-1;
    while(i>=0)
    {
        heap(a, i, n);
        i--;
    }
    int N=n;
    while(N>=2)
    {
        for(int j=0; j<n; j++) std::cout<<a[j]<<" ";
        std::cout<<"\n";
        N-=1;
        std::swap(a[0], a[N]);
        heap(a, 0, N);
    }
}

void QuickSort(int a[], int left, int right)
{
   int x=a[(left+right)/2];
   int i=left; int j=right;
   while (i<j)
   {
     while(a[i]<x) i++;
     while(a[j]>x) j--;
     if(i<=j) 
     {
        std::swap(a[i],a[j]);
        i++;
        j--;
     }
   }
   if(left<j) QuickSort(a, left, j); 
   if(right>i) QuickSort(a, i, right);
   if(left>j||right<=i) return;
}
main()
{
    clock_t start, end;

    int n;
    std::cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    std::cin>>a[i];
    start=clock();
    QuickSort(a,0, n-1);
    for(auto x:a) std::cout<<x<<" ";
    end=clock();
    double time_used=(end-start);
    std::cout<<"\n"<<time_used;
return 0;
}