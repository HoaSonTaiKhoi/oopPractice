
#include<bits/stdc++.h>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

class Human
{
    private:
     string hoten;
     string ngaysinh;
     bool gioitinh;
     string CCCD;
    public:
     Human();
     ~Human();
     void set_hoten(string s);
     void set_ngaysinh(string s);
     void set_gioitinh(bool c);
     void set_CCCD(string s);
     string get_hoten();
     string get_ngaysinh();
     string get_CCCD();
     bool get_gioitinh();
     bool check_ngay_sinh();
     bool check_CCCD();
     int check_gioitinh(string s);

     virtual void Nhap();
     virtual void Xuat();
};

class Sinhvien:public Human
{
    private:
     string University;
     string Faculty;
     string MSSV;
    public:
    Sinhvien();
    ~Sinhvien();
     void Nhap();
     void Xuat();
};


class Hocsinh: public Human
{
    private:
     string School;
     string Grade;
    public:
     Hocsinh();
    ~Hocsinh();
     void Nhap();
     void Xuat();
};

class Congnhan: public Human
{
    private:
     string Ma_cong_nhan;
    public:
     Congnhan();
    ~Congnhan();
     void Nhap();
     void Xuat();
};

class Nghesi: public Human
{
    private:
     string Bietdanh;
    public:
     Nghesi();
    ~Nghesi();
     void Nhap();
     void Xuat();
};

class Casi: public Human
{
    private:
     string bietdanh;
    public:
     Casi();
    ~Casi();
     void Nhap();
     void Xuat();
};

class DS_Human
{
    private:
     vector<Human*> ds;
    public:
     void Nhap_1();
     void Nhap_n();
     void Xuat_n();
};
Human::Human(){this->hoten=this->CCCD=this->ngaysinh=""; this->gioitinh=1;}

Human::~Human(){}

void Human::set_hoten(string s) {this->hoten=s;}
void Human::set_ngaysinh(string s) {this->ngaysinh=s;}
void Human::set_CCCD(string s) {this->CCCD=s;}
void Human::set_gioitinh(bool c) { this->gioitinh = c; }
string Human::get_hoten(){return this->hoten;}
string Human::get_ngaysinh(){return this->ngaysinh;}
string Human::get_CCCD(){return this->CCCD;}
bool Human::get_gioitinh(){return this->gioitinh;}

bool Human::check_ngay_sinh()
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

bool Human::check_CCCD()
{
    int n=this->CCCD.size();
    if(n!=12)  return false;
    for(int i=0; i<n ;i++)
    {
        if(this->CCCD[i]<48||this->CCCD[i]>57) {return false; break;}
    }
    return true;
}

int Human::check_gioitinh(string s)
{
    for(int i=0; i<s.size(); i++) s[i]=tolower(s[i]);
    if(s=="nam") return 2;
    else if(s=="nu") return 1;
    else return 0;
}

void Human::Nhap()
{
    cin.ignore();
    cout<<"Nhap ho va ten: "; getline(cin, this->hoten);
    cout<<"Nhap ngay sinh(dd/mm/yy): "; getline(cin, this->ngaysinh);
    while(this->check_ngay_sinh()==0) {cout<<"Nhap lai ngay sinh: "; getline(cin,this->ngaysinh);}


    string temp_gioitinh; cout<<"Nhap gioi tinh(Nam/Nu): "; getline(cin, temp_gioitinh);
    while(check_gioitinh(temp_gioitinh)==0) {cout<<"Nhap lai gioi tinh: "; getline(cin, temp_gioitinh);}
    if(check_gioitinh(temp_gioitinh)==2) this->gioitinh=1;
    else this->gioitinh=0;

    cout<<"Nhap CCCD: "; getline(cin, this->CCCD);
    while(this->check_CCCD()==0) {cout<<"Nhap lai CCCD: "; getline(cin, this->CCCD);}
}

void Human::Xuat()
{
    cout<<"\t Ho va ten: "<<this->hoten;
    cout<<"\n\t Ngay sinh: "<<this->ngaysinh;
    cout<<"\n\t Gioitinh: "; if(this->gioitinh==1) cout<<"Nam"; else cout<<"Nu";
    cout<<"\n\t CCCD: "<<this->CCCD;
}

Sinhvien::Sinhvien():Human(){}
Sinhvien::~Sinhvien(){}

void Sinhvien::Nhap()
{
    Human::Nhap();
    cout<<"Nhap truong dai hoc: "; getline(cin, this->University);
    cout<<"Nhap Khoa: "; getline(cin, this->Faculty);
    cout<<"Nhap ma so sinh vien: "; getline(cin, this->MSSV);
}

void Sinhvien::Xuat()
{
    Human::Xuat();
    cout<<"\n\t Truong dai hoc: "<<this->University;
    cout<<"\n\t Khoa: "<<this->Faculty;
    cout<<"\n\t Ma so sinh vien: "<<this->MSSV;
}

Hocsinh::Hocsinh():Human(){}
Hocsinh::~Hocsinh(){}

void Hocsinh::Nhap()
{
    Human::Nhap();
    cout<<"Nhap truong hoc: "; getline(cin, this->School);
    cout<<"Nhap lop hoc: "; getline(cin, this->Grade);
}

void Hocsinh::Xuat()
{
    Human::Xuat();
    cout<<"\n\t Truong hoc: "<<this->School;
    cout<<"\n\t Lop hoc: "<<this->Grade;
}

Congnhan::Congnhan():Human(){}
Congnhan::~Congnhan(){}

void Congnhan::Nhap()
{
    Human::Nhap();
    cout<<"Nhap ma cong nhan: "; getline(cin, this->Ma_cong_nhan);
}

void Congnhan::Xuat()
{
    Human::Xuat();
    cout<<"\n\t Ma cong nhan: "<<this->Ma_cong_nhan;
}

Nghesi::Nghesi():Human(){}
Nghesi::~Nghesi(){}

void Nghesi::Nhap()
{
    Human::Nhap();
    cout<<"Nhap biet danh: "; getline(cin, this->Bietdanh);
}

void Nghesi::Xuat()
{
    Human::Xuat();
    cout<<"\n\t Biet danh: "<<this->Bietdanh;
}

Casi::Casi():Human(){}
Casi::~Casi(){}

void Casi::Nhap()
{
    Human::Nhap();
    cout<<"Nhap biet danh: "; getline(cin, this->bietdanh);
}

void Casi::Xuat()
{
    Human::Xuat();
    cout<<"\n\t Biet danh: "<<this->bietdanh;
}

void DS_Human::Nhap_1()
{
    Human *a;
    cout<<"<><><><><><><><><><><><>\n"
        <<"1. Sinh vien.\n"
        <<"2. Hoc sinh.\n"
        <<"3. Cong nhan.\n"
        <<"4. Nghe si.\n"
        <<"5. Casi.\n"
        <<"<><><><><><><><><><><><>\n"
        <<"Your choice: ";
    int key; 
    cin>>key; while(key!=1&&key!=2&&key!=3&&key!=4&&key!=5) {cout<<"Your choice: ";cin>>key;}
    if(key==1) 
    {
        a=new Sinhvien();
    }
    else if(key==2) 
    {
        a=new Hocsinh();
    }
    else if(key==3) 
    {
        a=new Congnhan();
    }
    else if(key==4) 
    {
        a=new Nghesi();
    }
    else if(key==5) 
    {
        a=new Casi();
    }
    a->Nhap();
    ds.push_back(a);
}

void DS_Human::Nhap_n()
{
    int n;
    cout<<"Nhap so nguoi can nhap: "; cin>>n;
    while(n>0)
    {
        this->Nhap_1();
        n--;
    }
}

void DS_Human::Xuat_n()
{
     int n=ds.size();
    cout<<"\n\n..............................\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\nNguoi "<<i+1<<": \n";
        ds[i]->Xuat();
        cout<<"\n";
    }
    cout<<"\n..............................\n";
}

int main()
{
    DS_Human hm;
    while(true)
    {
        cout<<"\n\t\t\tQUAN Li\n"
            <<"_______________________________\n"
            <<"1. Nhap 1 nguoi.\n"
            <<"2. Nhap n nguoi.\n"
            <<"3. Xuat thong tin nhan vien.\n"
            <<"0. END.\n"
            <<"_______________________________\n"
            <<"Your choice: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1) hm.Nhap_1();
        else if(key==2) hm.Nhap_n();
        else if(key==3) hm.Xuat_n();
    }
return 0;
}
