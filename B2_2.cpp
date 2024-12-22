#include<bits/stdc++.h>

class SoPhuc
{
  private:
   double a;
   double b;
  public:
   void Nhap();
   void Xuat();
   static void Cong(SoPhuc sp1, SoPhuc sp2);
   static void Hieu(SoPhuc sp1, SoPhuc sp2);
   static void Tich(SoPhuc sp1, SoPhuc sp2);
   static void Thuong(SoPhuc sp1, SoPhuc sp2);
};

// Nhap số phức
void SoPhuc::Nhap(){ std::cin>>this->a>>this->b; }

//Xuất số phức (có các trường hợp đặc biệt)
void SoPhuc::Xuat()
      {
        if(a!=0)
        {
          if (b==1)      std::cout<<a<<"+i";
          else if(b==-1) std::cout<<a<<"-i";
          else if(b<0)   std::cout<<a<<b<<"i";
          else if(b==0)  std::cout<<a;
          else           std::cout<<a<<"+"<<b<<"i";
        }
        else
        {
          if (b==1)      std::cout<<"i";
          else if(b==-1) std::cout<<"-i";
          else if(b==0)  std::cout<<0;
          else           std::cout<<b<<"i";
        }
      }

//Tổng 2 số phức
void SoPhuc::Cong(SoPhuc sp1, SoPhuc sp2)
      {
         SoPhuc sp;
         sp.a=sp1.a+sp2.a;
         sp.b=sp1.b+sp2.b;
         sp.Xuat();
      }

//Hiệu 2 số phức
void SoPhuc::Hieu(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        sp.a=sp1.a-sp2.a;
        sp.b=sp1.b-sp2.b;
        sp.Xuat();
      }

//Tich hai so phuc
void SoPhuc::Tich(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        sp.a=sp1.a*sp2.a-sp1.b*sp2.b;
        sp.b=sp1.a*sp2.b+sp1.b*sp2.a;
        sp.Xuat();
      }

//Thương hai số phức
void SoPhuc::Thuong(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        if ((sp1.b==0&&sp2.b==0)||(sp2.b==0&&sp2.a==0)) 
        {
          std::cout<<"So Phuc khong hop le!";
          return;
        }
        sp.a=(sp1.a*sp2.a+sp1.b*sp2.b)/(sp2.a*sp2.a+sp2.b*sp2.b);
        sp.b=(sp2.a*sp1.b-sp1.a*sp2.b)/(sp2.a*sp2.a+sp2.b*sp2.b);
        sp.Xuat();
      }

int main()
{
    SoPhuc sp1, sp2;
    std::cout<<"Nhap so phuc thu nhat: ";         sp1.Nhap();

    std::cout<<"\nNhap so phuc thu hai: ";        sp2.Nhap();
    
    std::cout<<"\nKet qua: \nSo phuc thu nhat: "; sp1.Xuat();
    
    std::cout<<"\nSo phuc thu hai: ";             sp2.Xuat();
    
    // Dong kết quả các phép tính
    std::cout<<"\nCong: ";                        SoPhuc::Cong(sp1, sp2);                       
    
    std::cout<<"\nTru: ";                         SoPhuc::Hieu(sp1, sp2); 
    
    std::cout<<"\nNhan: ";                        SoPhuc::Tich(sp1, sp2);          
                 
    std::cout<<"\nChia: ";                        SoPhuc::Thuong(sp1, sp2);
return 0;
}