#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Item
{
    protected:
     string name, producer;
     double price;
    public:
     Item(){}
     ~Item(){}
     virtual void Nhap(){cin>>name>>price>>producer;}
     virtual double true_price()=0;
};

class Quan: public Item
{
    protected:
     double length;
    public:
     Quan():Item(){}
     ~Quan(){}
     virtual void Nhap(){Item::Nhap(); cin>>length;}
     virtual double true_price()=0;
};
    class Jean: public Quan
    {
        public:
        Jean():Quan(){}
        ~Jean(){}
        void Nhap(){Quan::Nhap();}
        double true_price(){return price*0.8;}
    };

    class Kaki:public Quan
    {
        public:
        Kaki():Quan(){}
        ~Kaki(){}
        void Nhap(){Quan::Nhap();}
        double true_price(){return price*1.5;}
    };

class Ao: public Item
{
    protected:
     string color;
    public:
     Ao():Item(){}
     ~Ao(){}
     virtual void Nhap(){Item::Nhap(); cin>>color;}
     virtual double true_price()=0;
};
    
    class Short:public Ao
    {
        private:
         bool isneck;
        public:
         Short():Ao(){}
         ~Short(){}
         void Nhap(){Ao::Nhap(); cin>>isneck;}
         double true_price(){return price;}
    };

    class Long: public Ao
    {
        private:
         double olength;
        public:
         Long():Ao(){}
         ~Long(){}
         void Nhap(){Ao::Nhap(); cin>>olength;}
         double true_price(){return price;}
    };

class Mu: public Item
{
    protected:
     int level;
     double buff;
    public:
     Mu():Item(){}
     ~Mu(){}
     virtual void Nhap(){Item::Nhap(); cin>>level;}
     virtual double true_price()=0;
};

    class Steel:public Mu
    {
        public:
         Steel():Mu(){}
         ~Steel(){}
         void Nhap(){Mu::Nhap();}
         double true_price(){return 0;}
    };

    class Silver:public Mu
    {
        public:
         Silver():Mu(){}
         ~Silver(){}
         void Nhap(){Mu::Nhap();}
         double true_price(){return price;}
    };

    class Gold: public Mu
    {
        public:
         Gold():Mu(){}
         ~Gold(){}
         void Nhap(){Mu::Nhap();}
         double true_price(){return price;}
    };

int main() {
    Item **ds;
    int n,x;
    double buff=1, sum1=0, sum2=0;
     cin>>n;
     ds= new Item* [n];
    for(int i=0; i<n; i++)
    {
        cin>>x;
        if(x==1) ds[i]=new Jean;
        else if(x==2) ds[i]=new Kaki;
        else if(x==3) ds[i]=new Short;
        else if(x==4) ds[i]=new Long;
        else if(x==5) ds[i]=new Steel;
        else if(x==6) {ds[i]=new Silver; if(buff<1.5) buff=1.5;}
        else if(x==7) {ds[i]=new Gold; if(buff<3) buff=3;}
        ds[i]->Nhap();
        if(x==1||x==2||x==3||x==4||x==5) sum1+=ds[i]->true_price();
        else sum2+=ds[i]->true_price();

    }

    double sum= sum1*buff+ sum2;
cout<<sum;
    return 0;
}
