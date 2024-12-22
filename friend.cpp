#include<bits/stdc++.h>
using namespace std;


class Diem
{
    private:
     double x,y;
    public:
    Diem(){}
    Diem(double xx, double yy):x(xx), y(yy)
     {
        this->x+=10;
        this->y+=20;
     }
    inline void Set(double xx, double yy)
    {
        x=xx; y=yy;
    }
    inline void getDiem()
    {
        cout<<x<<" "<<y<<"\n";
    }
};

class TamGiac
{
    private:
     Diem A, B, C;
    public:
     TamGiac(){
        cout<<"generating.\n";
        A.Set(1,2);
        B.Set(3,4);
        C.Set(5,6);
     }
    //  TamGiac(double xa, double ya, double xb, double yb, double xc, double yc):A(xa, ya), B(xb, yb), C(xc, yc) // khai báo trong constructor là I ra sau dấu hai chấm "loai" thế cho I
    //  {
    //  }
     void getInfo()
     {
        A.getDiem();
        B.getDiem();
        C.getDiem();
     }
};

int main()
{
    int xa, xb, ya, yb, xc, yc;
    // cin>>xa>>ya>>xb>>yb>>xc>>yc;
    TamGiac tg1;
    tg1.getInfo();
return 0;
}