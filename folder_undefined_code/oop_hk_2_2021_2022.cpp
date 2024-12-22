
// oop2021-2022

#include<iostream>
#include<math.h>
#include<string.h>
#include<sstream>
#include<iomanip>

using namespace std;

class Sach
{
    protected:
     string ma_sach, ten_sach, nxb;
     int soluong;
     double don_gia;
    public:
     Sach();
     ~Sach();
     virtual void Nhap();
     virtual void Xuat();
     virtual double Thanh_tien()=0;
     virtual bool Phan_loai()=0;
     string get_nxb(){return this->nxb;}
};

Sach::Sach()
 {
    this->ma_sach=this->ten_sach=this->nxb="";
    this->don_gia=this->soluong=0;
 }
Sach::~Sach()
{
    this->ma_sach=this->ten_sach=this->ten_sach="";
    this->don_gia=0;
}

void Sach::Nhap()
{
    fflush(stdin);
    cout<<"Nhap ma sach: ";  getline(cin,this->ma_sach);
    cout<<"Nhap ten sach: ";getline(cin,this->ten_sach);
    cout<<"Nhap nha xuat ban: ";getline(cin,this->nxb);
    cout<<"Nhap so luong: "; cin>>soluong;
    cout<<"Nhap don gia: "; cin>>don_gia;
    fflush(stdin);
}

void Sach::Xuat()
{
    cout<<"Ma sach: "; cout<<this->ma_sach;
    cout<<"\nTen sach: "; cout<<this->ten_sach;
    cout<<"\nNha xuat ban: ";cout<<this->nxb;
    cout<<"\nSo luong: "; cout<<this->soluong;
    cout<<"\nDon gia: "; cout<<this->don_gia;
}

double Sach::Thanh_tien()
{
    return (double)soluong*don_gia;
}

class Sach_Giao_Khoa: public Sach
{
    private:
     bool tinh_trang;
    public:
    Sach_Giao_Khoa();
    ~Sach_Giao_Khoa();
     void Xuat();
     void Nhap();
     double Thanh_tien();
     bool Phan_loai();
};

Sach_Giao_Khoa::Sach_Giao_Khoa():Sach(){}
Sach_Giao_Khoa::~Sach_Giao_Khoa(){}

 void Sach_Giao_Khoa::Nhap()
 {
    Sach::Nhap();
    cout<<"Nhap tinh trang: ";cin>>tinh_trang;
 }

 void Sach_Giao_Khoa::Xuat()
 {
    Sach::Xuat();
    cout<<"\nTinh trang: "<<this->tinh_trang;
 }

 double Sach_Giao_Khoa::Thanh_tien()
 {
    if(tinh_trang!=0) return Sach::Thanh_tien();
    else return Sach::Thanh_tien()*0.5;
 }
 
 bool Sach_Giao_Khoa::Phan_loai(){ return 1;}

class Sach_Tham_Khao: public Sach
{
    private:
     double thue;
    public:
     Sach_Tham_Khao();
     ~Sach_Tham_Khao();
     void Nhap();
     void Xuat();
     double Thanh_tien();
     bool Phan_loai();
};

Sach_Tham_Khao::Sach_Tham_Khao():Sach(){}
Sach_Tham_Khao::~Sach_Tham_Khao(){}

void Sach_Tham_Khao::Nhap()
{
    Sach::Nhap();
    cout<<"Nhap thue: "; cin>>this->thue;
}

void Sach_Tham_Khao::Xuat()
{
    Sach::Xuat();
    cout<<"\nThue: "<<this->thue;
}

double Sach_Tham_Khao::Thanh_tien()
{
    return Sach::Thanh_tien()+thue;
}

bool Sach_Tham_Khao::Phan_loai(){return 0;}

class Thuvien
{
    private:
     Sach **ds;
     int n;
    public:
     Thuvien();
     ~Thuvien();
     void Nhap();
     void Xuat();
     void Thanhtien_findmin();
     void find_sach_nxb();
};

Thuvien::Thuvien(){ds=new Sach*; n=0;}
Thuvien::~Thuvien(){}

void Thuvien::Nhap()
{
    cout<<"Nhap n: "; cin>>n;
    for(int i=0; i<n ; i++)
    {
        Sach *s;
        cout<<"Nhap sach\n"
            <<"*******************\n"
            <<"1. Sach giao khoa\n"
            <<"2. Sach tham khao\n"
            <<"0. Stop.\n"
            <<"*******************\n"
            <<"Lua chon: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1)
        {
            s=new Sach_Giao_Khoa();
            s->Nhap();
            ds[i]=s;
        }
        else if(key==2)
        {
            s=new Sach_Tham_Khao();
            s->Nhap();
            ds[i]=s;
        }
        cout<<"\n";
    }
}


void Thuvien::Xuat()
{
    if(n<=0) return;
    for(int i=0; i<n; i++)
     {
        cout<<"----------------------\n";
        ds[i]->Xuat(); cout<<"\n----------------------\n\n";
     }
}

void Thuvien::Thanhtien_findmin()
{
    if(n<=0) return;

    double Thanh_tien_SGK=0, Thanh_tien_STK=0, tmp;
    double min=ds[0]->Thanh_tien();
    for(int i=0; i<n; i++) 
    {
        tmp=ds[i]->Thanh_tien();
        if(ds[i]->Phan_loai()) Thanh_tien_SGK+=tmp;
        else Thanh_tien_STK+=tmp;
        if(min>tmp) min=tmp;
    }
    cout<<"Sach giao khoa: "<<setprecision(20)<<Thanh_tien_SGK
        <<"\nSach tham khao: "<<setprecision(20)<<Thanh_tien_STK
        <<"\nSach thanh tien min: \n";
    
    for(int i=0; i<n; i++)
    {
        if(min==ds[i]->Thanh_tien()) ds[i]->Xuat();
    }
}

void Thuvien::find_sach_nxb()
{
    if(n<=0) return;
    string s;
    cout<<"Nhap nha xuat ban: "; fflush(stdin); getline(cin, s);
    for(int i=0; i<n; i++)
    {
        if(s==ds[i]->get_nxb()) ds[i]->Xuat();
        cout<<"\n";
    }
}


int main()
{
    Thuvien tv;
    while(true)
    {
        cout<<"******************\n"
            <<"1. Nhap sach.\n"
            <<"2. Xuat sach.\n"
            <<"3. Thanh tien & find min.\n"
            <<"4. Tim sach cung nxb.\n"
            <<"0. End.\n"
            <<"******************\n"
            <<"Lua chon: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1) tv.Nhap();
        else if(key==2) tv.Xuat();
        else if(key==3) tv.Thanhtien_findmin();
        else if(key==4) tv.find_sach_nxb();
    cout<<"\n";
    }
return 0;
}