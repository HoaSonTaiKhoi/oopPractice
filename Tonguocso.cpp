#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int n; cin>>n;
int sum =1;

if(n<=1) cout<<0;
else
{    for(int i=2; i<=sqrt(n); i++)
{
     if(n%i==0) 
     {
          if (i!=n/i) sum+=i+n/i;
          else sum+=i;
     }
}
cout<<sum;
}
return 0;
}