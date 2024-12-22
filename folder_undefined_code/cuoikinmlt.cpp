#include <iostream>
using namespace std;
#define N 300
struct POINT
{
    int x,y,z;
};
struct POLYGON
{
   POINT  a[100];
   int n;
};

void Nhap(POLYGON &B)
{
    cin>>B.n;
    for(int i=0; i< B.n; i++)
     
     {
        cin>>B.a[i].x;
        cin>>B.a[i].y;
        cin>>B.a[i].z;
     }
}
main()
{
    POLYGON B;
    Nhap(B);
    for(int i=0; i< B.n; i++)
     {
        cout<<B.a[i].x<<endl;
     }
 return 0;    
}