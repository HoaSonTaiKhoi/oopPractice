
#include<bits/stdc++.h>
using namespace std;


class P
{
    private:
     int x;
     
    public:
    friend class M;
     P()
     {
        this->x=4;
        cout<<"Hi.\n";
     }
    ~P()
    {
        cout<<"Destroy.\n";
    }
   inline void Xuat()
    {
        cout<<"Lỏ vc.\n";
    }
};

class M
{
    private:
     int e;
     P p;
    public:
      M(){this->e=p.x; cout<<p.x<<"\n";}
    //  M(int m=3)
    //  {
    //     p.x=m;
    //     cout<<p.x<<"\n";
    //     this->e=p.x;
    //  }
    ~M(){cout<<"END."<<this->e<<"\n";}
    void Xuat()
    {
        cout<<"Wow.\n";
    }
};

class B
{
    private:
     int x,y;
    public:
     B(double xx, double yy):x(xx), y(yy)
     {
        cout<<x*y;
     }
    void Set(double xx, double yy)
    {
        x=xx; y==yy;
    }
}
class A
{
    private:
     B a,b,c;
    public:
     
};
inline void He()
{
    P p;
    cout<<"HoHo.\n";
    return;
}
int main()
{
    M m();
    M().Xuat();
}