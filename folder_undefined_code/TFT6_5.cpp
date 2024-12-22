#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Tuong
{
    protected:
     int he, gia_tri; bool dausi;
     double atk, def;
     string name;
    public:
     Tuong(){}
     ~Tuong(){}
     virtual void Nhap(){cin>>atk>>def;}
     virtual double dame(int m)=0;
     int get_toc(){return he;}
     bool is_dausi(){return dausi;}
     void set(double a, double b){this->atk+=a; this->def+=b;}
     string get_name(){return name;}
     int get_vang(){return gia_tri;}
};


        class Jarvan:public Tuong
        {
            
            public:
             Jarvan():Tuong(){he=1; dausi=1; gia_tri=1;name="Jarvan";}
             ~Jarvan(){}
             void Nhap(){Tuong::Nhap();}
             double dame(int m){return def*2*m;}
        };

        class Reksai:public Tuong
        {
            
            public:
             Reksai():Tuong(){he=2; dausi=1;gia_tri=2;name="Reksai";}
             ~Reksai(){}
             void Nhap(){Tuong::Nhap();}
             double dame(int m){int temp=m/4; return temp*atk*2+(m-temp)*atk;}
        };

        class Sivir:public Tuong
        {
            
            public:
             Sivir():Tuong(){he=1; dausi=0; gia_tri=4;name="Sivir";}
             ~Sivir(){}
             void Nhap(){Tuong::Nhap();}
             double dame(int m){return atk*2*m;}
        };

        class Illaoi:public Tuong
        {
            
            public:
             Illaoi():Tuong(){he=2; dausi=1; gia_tri=1;name="Illaoi";}
             ~Illaoi(){}
             void Nhap(){Tuong::Nhap();}
             double dame(int m){return ((atk+def)/2)*m;}
        };

int main() {
    Tuong** ds;
    bool found[4]={};
    int n,m, x, tiencong=0, congnghe=0, dausi=0, sum_gia_tri=0;
     cin>>n>>m;

     ds=new Tuong*[n];

    for(int i=0; i<n;i++)
    {
        cin>>x;
        if(x==1) ds[i]=new Jarvan;
        else if(x==2) ds[i]= new Reksai;
        else if(x==3) ds[i]= new Sivir;
        else if(x==4) ds[i]= new Illaoi;
        ds[i]->Nhap();
        found[x-1]=1;
    }

    if(found[0]==1) {congnghe++; dausi++;}
    if(found[1]==1) {tiencong++; dausi++;}
    if(found[2]==1) {congnghe++;}
    if(found[3]==1) {tiencong++; dausi++;}

    for(int i=0; i<n; i++)
    {
            if(ds[i]->get_toc()==2&& tiencong==2) ds[i]->set(30,0);

            if(ds[i]->get_toc()==1&& congnghe==2) ds[i]->set(15,15);

            if(ds[i]->is_dausi()==1&& dausi>=2) ds[i]->set(0,(dausi-1)*15);
    }

    for(int i=0; i<n ; i++)
    {
        cout<<ds[i]->get_name()<<" - sat thuong gay ra: "<<ds[i]->dame(m)<<"\n";
        sum_gia_tri+=ds[i]->get_vang();
    }
    cout<<"Tong gia tri: "<<sum_gia_tri;

    return 0;
}
