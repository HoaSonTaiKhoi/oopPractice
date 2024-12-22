
#include<bits/stdc++.h>

using namespace std;

class heap_sort
{
    private:
     int *a;
     int n;
    public:
    heap_sort(int *a, int n);
    friend istream& operator >>(istream &in, heap_sort& h1);
    friend ostream& operator <<(ostream &out,const heap_sort& h1);
     void Heap(int k, int n);
     void buildHeap();
     void main();
     friend void heapsort(int *a, int n);
};

heap_sort::heap_sort(int *a, int n)
{
    this->a=a;
    this->n=n;
}

istream& operator >>(istream&in, heap_sort& h1)
{
    in>>h1.n;
    h1.a=new int[h1.n];
    for(int i=0; i<h1.n; i++)
    {
        in>>h1.a[i];
    }
    return in;
}

ostream& operator << (ostream &out,const heap_sort& h1)
{
    for(int i=0; i<h1.n; i++)
    {
        out<<h1.a[i]<<" ";
    }
    return out;
}


void heap_sort::Heap(int k, int m)
{
    int j=2*k+1;
    while(j<m)
    {
        if(j+1<m) if( a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        swap(a[k], a[j]);
        k=j;
        j=2*k+1;
    }
    return;
}

void heap_sort::buildHeap()
{
    int i=(this->n-1)/2;
    while(i>=0)
    {
        Heap(i, this->n);
        i--;
    }
    return;
}

void heap_sort::main()
{
    int m=n;
    buildHeap();
    while(m>0)
    {
        m--;
        swap(a[0], a[m]);
        Heap(0, m);
    }
   return;
}

void heapsort(int *a, int n)
{
    heap_sort h(a, n);
    cout<<h<<"\n";
    h.main();
    cout<<h;
}

// viết thông thường :))

void heapify(int *a, int k, int n)
{
    int j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if( a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) return;
        swap(a[k], a[j]);
        k=j;
        j=2*k+1;
    }
    return;
}

void build(int *a, int n)
{
    int i=(n-1)/2;
    while(i>=0)
    {
        heapify(a, i, n);
        i--;
    }
}
void heap_Sort(int *a, int n)
{
    build(a,n);
    while(n>0)
    {
        n--;
        swap(a[0],a[n]);
        heapify(a, 0, n);
    }
}

int main()
{
    int *a, n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    heapsort(a,n);
    // heap_Sort(a,n);
    // for(int i=0; i<n; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
return 0;
}