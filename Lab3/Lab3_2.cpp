#include<bits/stdc++.h>

using namespace std;

class CTime
{
   private:
    int day, hour, min, sec;
   public:
    CTime();
    int getday();
    int gethour();
    int getmin();
    int getsec();
    int get_total_sec();
    
    bool Re();
    void chuanhoa();
    void chuanhoa(int get_total_sec);

    void Nhap();
    void Xuat();
    void cong_x(int x);
    void tru_x(int x);
    void tru(CTime t);
    void cong_1();
    void tru_1();
};

CTime::CTime(){ this->day=this->hour=this->min=this->sec=0;}

int CTime::getday ()  {return this->day; }
int CTime::gethour()  {return this->hour;}
int CTime::getmin ()  {return this->min; }
int CTime::getsec ()  {return this->sec; }

int CTime::get_total_sec() { return this->hour*3600 + this->min*60 + this->sec;}

void CTime::chuanhoa()
{
    this->day  =  (this->get_total_sec()/86400);
    this->hour =  (this->get_total_sec()/3600)%24;
    this->min  =  (this->get_total_sec()/60)%60;
    this->sec  =   this->get_total_sec()%60;
}
void CTime::chuanhoa(int get_total_sec)
{
    this->day  =  (get_total_sec/86400);
    this->hour =  (get_total_sec/3600)%24;
    this->min  =  (get_total_sec/60)%60;
    this->sec  =   get_total_sec%60;
}

bool CTime::Re()
{
    if(this->hour>23||this->hour<0) return false;
    if(this->min>59||this->min<0) return false;
    if(this->sec>59||this->sec<0) return false;
    return true;
}
void CTime::Nhap()
{
    cout<<"Nhap gio:  "; cin>>this->hour;
    cout<<"Nhap phut: "; cin>>this->min;
    cout<<"Nhap giay: "; cin>>this->sec;
    if(Re()==0)
    {
        cout<<"CTime khong hop le!. Nhap lai!\n";
        Nhap();
    }
}

void CTime::Xuat()
{
    if(day>=1) cout<<day<<"d ";
    cout<<hour<<"h "<<min<<"m "<<sec<<"s ";
}

void CTime::cong_x(int x)
{
    this->sec+=x;
    chuanhoa();
    this->Xuat();
}

void CTime::tru_x(int x)
{
    this->sec-=x;
    chuanhoa();
    this->Xuat();
}

void CTime::tru(CTime t2)
{
    if(this->get_total_sec()-t2.get_total_sec()<0)
    {
        cout<<"Time Error";
        return;
    }
    CTime tnew;
    tnew.chuanhoa(this->get_total_sec()-t2.get_total_sec());
    tnew.Xuat();
}

void CTime::cong_1()
{
    this->sec+=1;
    chuanhoa();
    this->Xuat();
}

void CTime::tru_1()
{
    this->sec-=1;
    chuanhoa();
    this->Xuat();
}

int main()
{
    CTime t;
    while(true)
    {
        cout<<"___________________________\n"
            <<"1. Nhap.\n"
            <<"2. Xuat.\n"
            <<"3. Cong 1 so nguyen giay.\n"
            <<"4. Tru 1 so nguyen giay.\n"
            <<"5. Tru time thu 2.\n"
            <<"6. Them 1s.\n"
            <<"7. Tru 1s.\n"
            <<"0. END.\n"
            <<"___________________________\n"
            <<"Nhap lua chon: ";
        int key; cin>>key;

        if     (key==0) break;
        else if(key==1) t.Nhap();
        else if(key==2) t.Xuat();
        else if(key==3) 
        { 
            cout<<"Nhap so nguyen giay: ";
            int x; cin>>x;
            t.cong_x(x);
        }
        else if(key==4) 
        { 
            cout<<"Nhap so nguyen giay: ";
            int x; cin>>x;
            t.tru_x(x);
        }
        else if(key==5) 
        { 
            CTime t2;            
            cout<<"Nhap time 2.\n";
            t2.Nhap();
            t.tru(t2);
        }
        else if(key==6) t.cong_1();
        else if(key==7) t.tru_1 ();
        cout<<"\n";
    }
}