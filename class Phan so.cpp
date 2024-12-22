#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int PhanSo::countps=0;
class PhanSo
{
    public:
      static int countps;
      int tuso;
      int mauso;
    public: 
      PhanSo()
      {
        cin>>tuso>>mauso;
      }
      int ucln(int a, int b)
      {
         if(a==0 || b==0) return a+b;
         if(a>b) return ucln(a%b, b);
         else return ucln(b%a, a);
      }
      void RutgonPhanso()
      {
            int x=ucln(tuso, mauso);
            tuso/=x;
            mauso/=x;
            cout<<tuso<<"/"<<mauso;
      }

};

void Sosanh_Out(PhanSo ps1, PhanSo ps2)
{
    int mauchung=ps1.mauso*ps2.mauso;
    if(ps1.tuso*mauchung>=ps2.tuso*mauchung) ps1.RutgonPhanso();
    else ps2.RutgonPhanso();
       
}

int main()
{
    PhanSo      

    Sosanh_Out(ps1, ps2);
}