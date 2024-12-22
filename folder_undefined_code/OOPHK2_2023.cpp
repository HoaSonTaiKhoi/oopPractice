#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

class Giaidoan
{
    public:
     int x,y;
     Giaidoan(int x, int y){this->x=x; this->y=y;}
     Giaidoan(){}
};

class Dongvat
{
    protected:
     int* ct;
     Giaidoan **gd;
     int n;
    public:
     Dongvat(){}
     ~Dongvat(){}
     virtual void Nhap()
     {
        for(int i=0; i<n;i++)
        {
            cin>>ct[i];
        }
     }
     virtual int phanloai()=0;
     virtual bool tuan_theo()
     {
        for(int i=0; i<n ; i++)
        {
            if(ct[i]>gd[i]->y || ct[i]<gd[i]->x) return false;
        }
        return true;
     }
};

            class Muoi:public Dongvat
            {
                public:
                 Muoi():Dongvat()
                 {
                    n=4; 
                    gd=new Giaidoan*[n]; 
                    ct=new int[n];
                 gd[0]=new Giaidoan(1,3);
                 gd[1]=new Giaidoan(4,10);
                 gd[2]=new Giaidoan(2,3);
                 gd[3]=new Giaidoan(5,8);
                 }

                 ~Muoi(){}
                 void Nhap(){Dongvat::Nhap();}
                 int phanloai(){return 1;}
                 bool tuan_theo(){return Dongvat::tuan_theo();}
            };

            class Ech:public Dongvat
            {
                public:
                Ech():Dongvat()
                {
                    n=5; 
                    gd=new Giaidoan*[n]; 
                    ct=new int[n];
                 gd[0]=new Giaidoan(1,3);
                 gd[1]=new Giaidoan(4,4);
                 gd[2]=new Giaidoan(6,9);
                 gd[3]=new Giaidoan(1,4);
                 gd[4]=new Giaidoan(2*52, 4*52);
                }

                ~Ech(){}

                void Nhap(){Dongvat::Nhap();}
                int phanloai(){return 2;}
                bool tuan_theo(){return Dongvat::tuan_theo();}
            };

            class Buom:public Dongvat
            {
                public:
                Buom():Dongvat()
                {
                    n=4; 
                    gd=new Giaidoan*[n]; 
                    ct=new int[n];
                 gd[0]=new Giaidoan(3,8);
                 gd[1]=new Giaidoan(15,16);
                 gd[2]=new Giaidoan(10,10);
                 gd[3]=new Giaidoan(2,3);
                }

                ~Buom(){}

                void Nhap(){Dongvat::Nhap();}
                int phanloai(){return 3;}
                bool tuan_theo(){return Dongvat::tuan_theo();}
            };

    class Danhsach
    {
        private:
         Dongvat** ds;
         int n;

        public:
         Danhsach(){}
         ~Danhsach(){}
         void Nhap()
         {
            cin>>n;
            ds=new Dongvat*[n];
            for(int i=0;i<n; i++)
            {
                int x; cin>>x;
                if(x==1) ds[i]=new Muoi;
                else if(x==2) ds[i]=new Ech;
                else if(x==3) ds[i]=new Buom;
                ds[i]->Nhap();
            }
         }
         void index_bool()
         {
            for(int i=0; i<n; i++)
            {
                if(!ds[i]->tuan_theo()) cout<<i+1<<" ";
            }
            cout<<"\n";
         }
         void da_dang()
         {
            bool muoi=0, ech=0, buom=0;
            for(int i=0; i<n; i++)
            {
                if(ds[i]->phanloai()==1) muoi=1;
                if(ds[i]->phanloai()==2) ech=1;
                if(ds[i]->phanloai()==3) buom=1;
            }
            if(muoi&&ech&&buom) cout<<"Co da dang";
            else cout<<"Khong da dang";
         }
    };

int main()
{
    Danhsach d;
    d.Nhap();
    d.index_bool();
    d.da_dang();
return 0;
}