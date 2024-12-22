#include<iostream>

using std::cin;
using std::cout;

int main()
{
    int n,  m , i, k, l;
    cin>>n>>m;

    long *a=new long[n];
    for(i=0; i<n; i++) cin>>a[i];

    while(m--)
    {
        cin>>k>>l;
        long min=a[k-1];
        for(i=k; i<l; i++)
        if(a[i]<min) min=a[i];

        cout<<min<<"\n";
    }

}