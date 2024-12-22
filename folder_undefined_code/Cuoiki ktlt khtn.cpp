
#include<iostream>
#include<string.h>
#include<sstream>
#include<algorithm>
#include<math.h>
#include<vector>
#define ll long long
using namespace std;

void tach(int&a, int &b)
{
    b=a%10;
    a/=10;
}

int main()
{
    string s, tmp;
    int *a=new int(0), k=0;
    getline(cin, s);

    stringstream input(s);
    while(input>>tmp)
    {
        if(tmp=="+") continue;
        a[k]=(atoi(tmp.c_str())); k++;
    }
    int b[k];
    ll sum=0;
    for(int i=0; i<k; i++)
    {
        tach(a[i], b[i]);
        sum+=pow(a[i], b[i]);
    }
    cout<<sum;
return 0;
}