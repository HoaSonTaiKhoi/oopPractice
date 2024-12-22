#include<iostream>

using namespace std;

int main()
{
    int a[6]={1,2,3,4,5,6};
    int n; cin>>n;
    long long d[n+1]={0};
    d[0]=1;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(i>=a[j]) d[i]=d[i]+d[i-a[j]];
        }
    }

    cout<<d[n];
return 0;
}