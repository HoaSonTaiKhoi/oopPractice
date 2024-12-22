#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int le(long long x)
{
    if(x<10) return 1;
    return 1+le(x/10);
}

int hoahong(long long x)
{
    int n=le(x); int sum1=0;
    for(int i=1; i<n; i++)
     sum1+=pow(2, i);
    int temp=(int)x/pow(10,n-1);
    if(temp<9) sum1+=pow(2,n-1);
    else if(temp==9)
    return sum;

}
int main()
{
    long long x, y;
    cin>>x>>y;
int h1=hoahong(x-1);
int h2=hoahong(y);
cout<<h2-h1;

return 0;
}