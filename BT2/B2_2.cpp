#include<bits/stdc++.h>
class SoPhuc
{
    private:
     double a;
     double b;
    public:
      void Nhap()
      {
        std::cin>>a>>b;
      }
      void Xuat()
      {
        if(a!=0){
            if (b==1) std::cout<<a<<"+i";
            else if(b==-1) std::cout<<a<<"-i";
        else if(b<-1) std::cout<<a<<b<<"i";
        else if(b==0) std::cout<<a;
        else std::cout<<a<<"+"<<b<<"i";
        }
        else{
            if (b==1) std::cout<<"i";
            else if(b==-1) std::cout<<"-i";
            else if(b==0) std::cout<<0;
             else {
                std::cout<<b<<"i";
             }
        }
      }

      //Tổng 2 số phức
      static void Cong(SoPhuc sp1, SoPhuc sp2)
      {
         SoPhuc sp;
         sp.a=sp1.a+sp2.a;
         sp.b=sp1.b+sp2.b;
         sp.Xuat();
      }

      //Hiệu 2 số phức
      static void Tru(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        sp.a=sp1.a-sp2.a;
        sp.b=sp1.b-sp2.b;
        sp.Xuat();
      }

      //Tich hai so phuc
      static void Tich(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        sp.a=sp1.a*sp2.a-sp1.b*sp2.b;
        sp.b=sp1.a*sp2.b+sp1.b*sp2.a;
        sp.Xuat();
      }

      //Thương hai số phức
      static void Thuong(SoPhuc sp1, SoPhuc sp2)
      {
        SoPhuc sp;
        sp.a=(sp1.a*sp2.a+sp1.b*sp2.b)/(sp2.a*sp2.a+sp2.b*sp2.b);
        sp.b=(sp2.a*sp1.b-sp1.a*sp2.b)/(sp2.a*sp2.a+sp2.b*sp2.b);
        sp.Xuat();
      }
};

int main()
{
    SoPhuc sp1, sp2;
    sp1.Nhap(); sp2.Nhap();
    SoPhuc::Cong(sp1, sp2);
    std::cout<<"\n";
    SoPhuc::Tru(sp1, sp2);
    std::cout<<"\n";
    SoPhuc::Tich(sp1, sp2);
    std::cout<<"\n";
    SoPhuc::Thuong(sp1, sp2);
return 0;
}