#include<iostream>
#include<math.h>
using namespace std;
int x[100];
int n;
void Xuat()
{
    for(int e=0; e<n; e++)
     cout<<x[e];
    cout<<"\n";
}

void Try(int c)
{
    for(int j=0; j<3; j++)
    {
        x[c]=j;
        if(c==n-1) Xuat();
        else Try(c+1);       //x[2]=0 2==2 xuất, x[2]=1 2=2 xuất, kết thúc for x[1]=1 -> x[2]=0 xuất-> x[2]=1 xuất, kết thúc for 2, kết thúc for 1, x[0]=1(for 0)........
    }
}
int main()
{
    
    cin>>n;
    Try(0);
return 0;
}