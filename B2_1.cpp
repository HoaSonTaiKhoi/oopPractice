#include<bits/stdc++.h>    

class PhanSo
{
   private:
    int tuso;
    int mauso;
   public:
    void Nhap();
    void Xuat_Rutgon_Dinhgiatri();
    static void Cong(PhanSo ps1, PhanSo ps2);
    static void Hieu(PhanSo ps1, PhanSo ps2);
    static void Tich(PhanSo ps1, PhanSo ps2);
    static void Thuong(PhanSo ps1, PhanSo ps2);
};

// Nhap mot phan so
void PhanSo::Nhap()     
     {
      std::cin>>tuso>>mauso;
      if(mauso==0) 
      {
         std::cout<<"Phan So khong hop le!. Nhap lai: ";
         return Nhap();
      }
     }
// Tìm ucln của mẫu số và tử số
int ucln(int x, int y)
     { 
        x=abs(x); y=abs(y);
        if(x*y==0) return x+y;
        if(x>y) return ucln(x%y, y);
        else return ucln(y%x, x);
     }

//Rút gọn Phân số, Định giá trị và Xuất Phân Số
void PhanSo::Xuat_Rutgon_Dinhgiatri()
     {
        if(tuso==0) std::cout<<0;
        else if(mauso==0) std::cout<<"Phan So khong hop le!";
        else if(tuso%mauso==0) std::cout<<tuso/mauso;
        else
        {
         int x=ucln(abs(tuso), abs(mauso));
         if(tuso>0 && mauso>0||tuso<0 && mauso<0) std::cout<<abs(tuso)/x<<"/"<<abs(mauso)/x;
         else if((tuso<0 && mauso>0) ||(tuso>0 && mauso<0)) 
            std::cout<<"-"<<abs(tuso)/x<<"/"<<abs(mauso)/x;
        }
     }

//Cộng hai phân số
void PhanSo::Cong(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.mauso+ps1.mauso*ps2.tuso;
        ps.Xuat_Rutgon_Dinhgiatri();
     }

//Hiệu của phân số 1 trừ cho phân số 2
void PhanSo::Hieu(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.mauso-ps2.tuso*ps1.mauso;
        ps.Xuat_Rutgon_Dinhgiatri();
     }

// Tích hai phân số
void PhanSo::Tich(PhanSo ps1, PhanSo ps2)
     {
        PhanSo ps;
        ps.mauso=ps1.mauso*ps2.mauso;
        ps.tuso=ps1.tuso*ps2.tuso;
        ps.Xuat_Rutgon_Dinhgiatri();
     }

//Thuong ps1 cho ps2
void PhanSo::Thuong(PhanSo ps1, PhanSo ps2)
     {
      PhanSo ps;
        ps.mauso=ps1.mauso*ps2.tuso;
        ps.tuso=ps1.tuso*ps2.mauso;
        ps.Xuat_Rutgon_Dinhgiatri();
     }


int main()
{
    PhanSo ps1; PhanSo ps2;
    std::cout<<"Nhap phan so thu nhat: "; ps1.Nhap();

    std::cout<<"Nhap phan so thu hai: ";  ps2.Nhap();
    
    std::cout<<"Phan so thu 1: ";         ps1.Xuat_Rutgon_Dinhgiatri();
    
    std::cout<<"\n"<<"Phan So thu 2: ";   ps2.Xuat_Rutgon_Dinhgiatri();

   //Dòng kết quả các phép tính
    std::cout<<"\nCong: ";        PhanSo::Cong(ps1, ps2);
    
    std::cout<<"\n"<<"Hieu: ";    PhanSo::Hieu(ps1, ps2);
    
    std::cout<<"\n"<<"Tich: ";    PhanSo::Tich(ps1,ps2);
    
    std::cout<<"\n"<<"Thuong: ";  PhanSo::Thuong(ps1, ps2);
return 0;
}