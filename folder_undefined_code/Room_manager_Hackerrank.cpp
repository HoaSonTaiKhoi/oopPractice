
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d; string t;
class Room
{
    protected:
     string name;
     int floor, num, capa;
    public:
     Room(){}
     ~Room(){}
     virtual void Nhap();
     virtual void Xuat();
     string get_name(){return name;}
     int get_capa(){return this->capa;}
     int get_num(){return num;}
     int get_floor(){return floor;}
};
               void Room::Nhap()
               {
                    cin>>t>>b>>c>>d;
                    this->name=t;
                    this->floor=b;
                    this->num=c;
                    this->capa=d;
               }

               void Room::Xuat() {
                cout<<name<<" "<<floor<<" "<<num<<" "<<capa<<"\n";
               }

class LT:public Room
{
    private:
     bool is_air;
    public:
     LT():Room(){}
     ~LT(){}
     void Nhap();
     void Xuat();

};
                void LT::Nhap()
                {
                    Room::Nhap();
                    cin>>this->is_air;
                }

                void LT::Xuat(){}


class TH:public Room
{
    private:
     int num_pc;
    public:
     TH():Room(){}
     ~TH(){}
     void Nhap();
     void Xuat();

};
                void TH::Nhap()
                {
                    Room::Nhap();
                    cin>>num_pc;
                }

                void TH::Xuat(){}

class GD:public Room
{
    private:
     int maychieu;
    public:
     GD():Room(){}
     ~GD(){}
     void Nhap();
     void Xuat();
};
                void GD::Nhap()
                {
                    Room::Nhap();
                    cin>>this->maychieu;
                }

                void GD::Xuat(){}

class University
{
    private:
     Room **ds;
     int n;
    public:
     University(){}
     ~University(){delete [] ds;}
     void Nhap();
     void Xuat();
};
                void University::Nhap()
                {
                    cin>>n;
                    ds=new Room* [n];
                    for(int i=0; i<n; i++)
                    {
                        cin>>a; 
                        if(a==1) ds[i]=new LT;
                        else if(a==2) ds[i]=new TH;
                        else if(a==3) ds[i]=new GD;

                        ds[i]->Nhap(); 
                    }
                }

                void University::Xuat()
                {
                    int k, sum=0, min_num=1000, min_floor=1000, min_capa=10000, found=0; 
                    string min_name;
                    cin>>k;
                    for(int i=0; i<n; i++)
                    {
                        sum+=ds[i]->get_capa();
                        if(ds[i]->get_capa()>=k && min_capa>=ds[i]->get_capa())
                        {
                            if(ds[i]->get_floor() <=min_floor && ds[i]->get_num()<=min_num)
                            {
                                min_capa=ds[i]->get_capa();
                                min_num=ds[i]->get_num();
                                min_floor=ds[i]->get_floor();
                                min_name=ds[i]->get_name();
                                found=1;
                            }
                        }
                    }
                    if(found) cout<<sum<<"\n"<<min_name; else cout<<sum<<"\nNULL";
                }

int main()
{
    University UIT;

    UIT.Nhap();
    UIT.Xuat();
return 0;
}
