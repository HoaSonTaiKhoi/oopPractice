#include<bits/stdc++.h>
using namespace std;
class POINT 
{
    public:
     int nx, ny;
    void Init(int x, int y);
    void printt();
    void goLeft();
    void goRight();
};
void POINT::Init(int x, int y)
{
    nx=x;
    ny=y;
}
void POINT::printt()
{
    cout<<"A("<<nx<<", "<<ny<<")";
}
void POINT::goLeft()
{
    nx-=1;
}
void POINT::goRight()
{
    nx+=1;
}
main()
{
    int x,y ;
    cin>>x>>y;
    POINT a;
    a.Init(x,y);
    a.printt();
    a.goLeft();
    cout<<endl;
    a.printt();
 return 0;   
}