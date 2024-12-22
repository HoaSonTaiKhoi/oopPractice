
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Gun
{
    protected:
     string name;
     float bangdan, st, ammo_sp, reload=2, hao_mon, sl_bangdan;
    public:
     Gun(){}
    ~Gun(){}
    virtual void Nhap(){}
    virtual void Xuat(){}
    virtual float Satthuong(float time){
        float tongst=0;
        while(sl_bangdan>0)
        {
            sl_bangdan-=1;
            if(time*ammo_sp>bangdan) 
            {
                tongst+=bangdan*st;
                time=time-bangdan/ammo_sp-2;
            }
            else if(time*ammo_sp<=bangdan)
            {
                
                if((int)(time*ammo_sp)-time*ammo_sp!=0) tongst+=((int)(time*ammo_sp)+1)*st;
                else tongst+=(time*ammo_sp)*st;
                break;
            }
        }
        return tongst;
    }
    virtual string get_name(){return name;}
};

class G18: public Gun
{
    private:
     float stgoc=2;
    public:
     G18():Gun()
     {
     name="G18";
     bangdan=12;
     ammo_sp=1;
     }
     ~G18(){}
     void Nhap()
     {
       cin>>sl_bangdan>>hao_mon;
       if(hao_mon<1) {st=hao_mon*stgoc ; ammo_sp/=2;}
       else st=stgoc;
     }
     float Satthuong(float time){
        return Gun::Satthuong(time);
     }
     string get_name(){return name;}
};

class M500:public Gun
{
    private:
      float stgoc=4;
    public:
     M500():Gun()
     {
     name="M500";
     bangdan=5;
     ammo_sp=0.5;
     }
     ~M500(){}
     void Nhap()
     {
       cin>>sl_bangdan>>hao_mon;
       if(hao_mon<1) {st=hao_mon*stgoc ; ammo_sp/=2;}
       else st=stgoc;
     }
     float Satthuong(float time){
        return Gun::Satthuong(time);
     }
     string get_name(){return name;}
};

class MP40:public Gun
{
    private:
     float stthem;
     float stgoc=3;
    public:
     MP40():Gun()
      {
        name="MP40";
     bangdan=20;
     
     ammo_sp=5;
      }
     ~MP40(){}
    void Nhap()
     {
       cin>>sl_bangdan>>hao_mon>>stthem;
       if(hao_mon<1) {st=hao_mon*stgoc ; ammo_sp/=2;}
       else st=stgoc;
       st+=stthem;
     }
    float Satthuong(float time)
    {
        return Gun::Satthuong(time);
    }
    string get_name(){return name;}
};

class AK: public Gun
{
    private:
     float stthem;
     float stgoc=5;
    public:
     AK():Gun()
      {
        name="AK";
        bangdan=30;
        ammo_sp=1;
      }
     ~AK(){}
    void Nhap()
     {
       cin>>sl_bangdan>>hao_mon>>stthem;
       if(hao_mon<1) {st=hao_mon*stgoc; ammo_sp/=2;}
       else st=stgoc;
        st+=stthem;
     }
    float Satthuong(float time)
    {
        return Gun::Satthuong(time);
    }
    string get_name(){return name;}
};

class SVD: public Gun
{
    private:
     float stgoc=5;
    public:
     SVD():Gun()
      {
        name="SVD";
     bangdan=10;
     ammo_sp=0.5;
      }

     ~SVD(){}
     void Nhap()
     {
       cin>>sl_bangdan>>hao_mon;
       if(hao_mon<1) {st=hao_mon*stgoc ; ammo_sp/=2;}
       else st=stgoc;
     }
     float Satthuong(float time){
        return Gun::Satthuong(time);
     }   
    string get_name(){return name;}
};

class AWM: public Gun
{
    private:
     float stgoc=10;
    public:
     AWM():Gun()
      {
        name="AWM";
        bangdan=5;
        ammo_sp=0.5;
      }
     ~AWM(){}
     void Nhap()
     {
       cin>>sl_bangdan>>hao_mon;
       if(hao_mon<1) {st=hao_mon*stgoc ; ammo_sp/=2;}
       else st=stgoc;
     }
     float Satthuong(float time){
        return Gun::Satthuong(time);
     }
    string get_name(){return name;}
};

class DS_Gun
{
    private:
     vector<Gun*> ds;
     float time;
    public:
     void Nhap()
     {
        int n,x ; cin>>n; Gun* a;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            if(x==1) a=new G18();
            else if(x==2) a=new M500();
            else if(x==3) a=new MP40();
            else if(x==4) a=new AK();
            else if(x==5) a=new SVD();
            else if(x==6) a=new AWM();
            a->Nhap();
            ds.push_back(a);
        }
        cin>>time;
     }

     void Xuat()
     {
        for(int i=0; i<ds.size(); i++)
        {
            cout<<ds[i]->get_name()<<": "<< ds[i]->Satthuong(time)<<"\n";
        }
     }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    DS_Gun DS_gun;
    DS_gun.Nhap();
    DS_gun.Xuat();
    return 0;
}
