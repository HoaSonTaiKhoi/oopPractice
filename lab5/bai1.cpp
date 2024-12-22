
#include<bits/stdc++.h>
#include<string.h>
#include<sstream>
#include<iostream>
using namespace std;



class Nhanvien
{
    private:
     string hoten;
     string ngaysinh;
     long long salary;
    public:
     Nhanvien();
     ~Nhanvien();
     virtual void Nhap();
     virtual void Xuat();
     void set_hoten(string hoten);
     void set_ngaysinh(string ngaysinh);
     void set_salary(long long salary);
     string get_hoten();
     string get_ngaysinh();
     long long get_salary();
     bool check_ngay_sinh();
};

Nhanvien::Nhanvien()
{
    this->hoten="";
    this->ngaysinh="";
    this->salary=0;
}

Nhanvien::~Nhanvien(){}

void Nhanvien::Nhap()
{
    cout<<"Nhap ho va ten: "; getline(cin, this->hoten);
    cout<<"Nhap ngay sinh: "; getline(cin, this->ngaysinh);
    while(check_ngay_sinh()==0) {cout<<"Nhap lai ngay sinh: "; getline(cin, this->ngaysinh);}
}

void Nhanvien::Xuat()
{
    cout<<this->hoten<<" "<<this->ngaysinh<<" "<<this->salary<<"\n";
}

void Nhanvien::set_hoten(string hoten) {this->hoten=hoten;}

void Nhanvien::set_ngaysinh(string ngaysinh){this->ngaysinh=ngaysinh;}

void Nhanvien::set_salary(long long salary) {this->salary=salary;}

string Nhanvien::get_hoten(){ return this->hoten;}

string Nhanvien::get_ngaysinh() {return this->ngaysinh;}

long long Nhanvien::get_salary(){ return this->salary;}

bool Nhanvien::check_ngay_sinh()
{
    int a,b,c, nam_nhuan=0;
    string tmp;
    stringstream temp(this->ngaysinh);
    getline(temp, tmp, '/'); a=atoi(tmp.c_str());
    getline(temp, tmp, '/'); b=atoi(tmp.c_str());
    getline(temp, tmp); c=atoi(tmp.c_str());

    if(c%400==0 ||(c%4==0 && c%100!=0)) nam_nhuan=1;

    if(b<1||b>12) return false;
    else if((b==1||b==3||b==5||b==7||b==8||b==10||b==12)&&(a>31||a<1)) return false;
    else if((b==4||b==6||b==9||b==11)&&(a>30||a<1)) return false;
    else if((b==2&&nam_nhuan==1&&(a>29||a<1))||(b==2&&nam_nhuan==0&&(a>28||a<1))) return false;
    return true;
}

class Nhanvienvanphong: public Nhanvien
{
    private:
     int so_ngay_lam_viec;
    public:
     Nhanvienvanphong();
     ~Nhanvienvanphong();
     void Nhap();
     void sum_salary();
     void Xuat();
};



Nhanvienvanphong::Nhanvienvanphong():Nhanvien(){}

Nhanvienvanphong::~Nhanvienvanphong(){}

void Nhanvienvanphong::Nhap()
{
    string s,x;
    cin.ignore();
    cout<<"Nhap ho va ten: "; getline(cin,s); this->set_hoten(s);
    cout<<"Nhap ngay sinh(dd/mm/yyyy): "; getline(cin,x); this->set_ngaysinh(x);

    while(check_ngay_sinh()==false)
    {
        cout<<"Nhap lai ngay sinh: ";
        getline(cin,x);
        this->set_ngaysinh(x);
    }
    cout<<"Nhap so ngay lam viec: "; cin>>this->so_ngay_lam_viec;
    this->sum_salary();
}

void Nhanvienvanphong::sum_salary()   {this->set_salary(this->so_ngay_lam_viec*100000);}


void Nhanvienvanphong::Xuat() 
{
    cout<<"\tHo va ten: "
        <<this->get_hoten()<<"\n"
        <<"\tNgay sinh: "
        <<this->get_ngaysinh()<<"\n"
        <<"\tLuong: "
        <<this->get_salary()<<"vnd\n";
}

class Nhanviensanxuat: public Nhanvien
{
    private:
     double base_salary;
     int product_num;
    public:    
    Nhanviensanxuat();
    ~Nhanviensanxuat();
     void Nhap();
     void sum_salary();
     void Xuat();
};

Nhanviensanxuat::Nhanviensanxuat(): Nhanvien() {}

Nhanviensanxuat::~Nhanviensanxuat(){}

void Nhanviensanxuat::Nhap()
{
    string s,x;
    cin.ignore();
    cout<<"Nhap ho va ten: "; getline(cin,s); this->set_hoten(s);
    cout<<"Nhap ngay sinh(dd/mm/yyyy): "; getline(cin,x); this->set_ngaysinh(x);
    
    while(check_ngay_sinh()==false) {
        cout<<"Nhap lai ngay sinh: "; getline(cin,x); this->set_ngaysinh(x);
    }
    
    cout<<"Nhap luong can ban: "; cin>>this->base_salary;
    cout<<"Nhap so san pham: "; cin>>this->product_num;
    this->sum_salary();
}

void Nhanviensanxuat::sum_salary()
{
    Nhanvien::set_salary(this->base_salary+this->product_num*5000);
}


void Nhanviensanxuat::Xuat()
{
    cout<<"\tHo va ten: "
        <<this->get_hoten()
        <<"\n\tNgay sinh: "
        <<this->get_ngaysinh()
        <<"\n\tLuong: "
        <<this->get_salary()<<"vnd\n";
}

class DS_Nhanvien
{
    private:
     vector<Nhanvien*> ds;
    public:
     void Nhap_1();
     void Nhap_n();
     void Duyet_all();
};

void DS_Nhanvien::Nhap_1()
{
    cout<<"<><><><><><><><><><><><>\n"
        <<"1. Nhan vien van phong.\n"
        <<"2. Nhan vien san xuat.\n"
        <<"<><><><><><><><><><><><>\n"
        <<"Your choice: ";
    int key; 
    cin>>key; while(key!=1&&key!=2) {cout<<"Your choice: ";cin>>key;}
    if(key==1) 
    {
        Nhanvien *a;
        a=new Nhanvienvanphong();
        a->Nhap();
        ds.push_back(a);
    }
    else if(key==2)
    {
        Nhanvien *a;
        a=new Nhanviensanxuat();
        a->Nhap();
        ds.push_back(a);
    }
}

void DS_Nhanvien::Nhap_n()
{
    int n;
    cout<<"Nhap so nhan vien can nhap: "; cin>>n;
    while(n>0)
    {
        this->Nhap_1();
        n--;
    }
}

void DS_Nhanvien::Duyet_all()
{
    int n=ds.size();
    cout<<"\n\n""""""""""""""""""""""""""""\n";
    for(int i=0; i<n; i++)
    {
        cout<<"Nhan vien "<<i+1<<": \n";
        ds[i]->Xuat();
    }
    cout<<"\n""""""""""""""""""""""""""""\n";
}



int main()
{
    DS_Nhanvien nv;
    while(true)
    {
        cout<<"\n\t\tQUAN Li NHAN VIEN\n"
            <<"_______________________________\n"
            <<"1. Nhap 1 nhan vien.\n"
            <<"2. Nhap n nhan vien.\n"
            <<"3. Xuat thong tin nhan vien.\n"
            <<"0. END.\n"
            <<"_______________________________\n"
            <<"Your choice: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1) nv.Nhap_1();
        else if(key==2) nv.Nhap_n();
        else if(key==3) nv.Duyet_all();
    }
return 0;
}
