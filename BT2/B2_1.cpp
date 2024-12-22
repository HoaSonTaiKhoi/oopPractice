#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
class PhanSo
{
    public:
     int tuso;
     int mauso;
    public:
     // Tìm ucln của mẫu số và tử số
     static int ucln(int x, int y)
     {
        if(x*y==0) return x+y;
        if(x>y) return ucln(x%y, y);
        else return ucln(y%x, x);
     }

     //Rút gọn Phân số
     static void RutgonPhanSo(PhanSo ps)
     {
        if(ps.tuso%ps.mauso==0) std::cout<<ps.tuso/ps.mauso;
        else
        {
        int x=PhanSo::ucln(abs(ps.tuso), abs(ps.mauso));
        if(ps.tuso*ps.mauso<0) std::cout<<"-"<<abs(ps.tuso)/x<<"/"<<abs(ps.mauso)/x;
        else std::cout<<ps.tuso/x<<"/"<<ps.mauso/x;
        }
     }

     //So sánh hai phân số
     static void Sosanh(PhanSo ps1, PhanSo ps2)
     {
         if(ps1.tuso*ps2.mauso<ps2.tuso*ps1.mauso) PhanSo::RutgonPhanSo(ps2);
         else PhanSo::RutgonPhanSo(ps1);
     }

     //Cộng hai phân số
     static void Plus(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.mauso+ps1.mauso*ps2.tuso;
        PhanSo::RutgonPhanSo(ps);
     }

     //Hiệu của phân số 1 trừ cho phân số 2
     static void Hieu(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.mauso-ps2.tuso*ps1.mauso;
        PhanSo::RutgonPhanSo(ps);
     }

     // Tích hai phân số
     static void Tich(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.tuso;
        PhanSo::RutgonPhanSo(ps);
     }

     //Thuong ps1 cho ps2
     static void Thuong(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.tuso;
        ps.tuso=ps1.tuso*ps2.mauso;
        PhanSo::RutgonPhanSo(ps);
     }
};

int main()
{
    PhanSo ps1; PhanSo ps2;
    std::cin>>ps1.tuso>>ps1.mauso>>ps2.tuso>>ps2.mauso;
    // BT1.1
    std::cout<<"Phan So thu 1 sau rut gon: ";
    PhanSo::RutgonPhanSo(ps1);
    std::cout<<"\n";

    //BT1.2
    std::cout<<"Phan So lon hon trong hai phan so 1, 2: ";
    PhanSo::Sosanh(ps1, ps2);
    std::cout<<"\n";

    //BT1.3
    PhanSo::Plus(ps1, ps2);
    std::cout<<"\n";
    PhanSo::Hieu(ps1, ps2);
    std::cout<<"\n";
    PhanSo::Tich(ps1,ps2);
    std::cout<<"\n";
    PhanSo::Thuong(ps1, ps2);
return 0;
}