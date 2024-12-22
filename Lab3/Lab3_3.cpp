#include<bits/stdc++.h>

using namespace std;    

class CDate
{
    private:
     int day, month, year;
    public:
     CDate();
     ~CDate();
     bool nhuan(int x);
     bool checkdate();
     void Nhap();
     void Xuat();
     
     void chuanhoa_1(int x);
     void chuanhoa_2(int x);
     void copy(CDate &d1);

     void cong_x(int x);
     void tru_x(int x);
     void cong_1();
     void tru_1();
     int TimeGap(CDate d2);
};

CDate::CDate(){this->year=this->month=this->day=1;}

CDate::~CDate(){}

bool CDate::nhuan(int x)
{
    return (x%400==0)||(x%4==0&&x%100!=0);
}

bool CDate::checkdate()
{
    if(day>31|| day<=0||month>12||month<=0) return false;
    if(month==4||month==6||month==9||month==11) if(day>30) return false;
    if(month==2&& nhuan(year)==1) if(day>29) return false;
    if(month==2&& nhuan(year)==0) if(day>28) return false;
    if(year<0) return false;
    return true;
}

void CDate::Nhap()
{
    cout<<"Nhap ngay thang nam(dd mm yy): ";
    cin>>this->day>>this->month>>this->year;
    if(checkdate()==false) 
    {
        cout<<"Ngay thang nam khong hop le. Nhap lai!\n";
        Nhap();
    }
}

void CDate::Xuat()
{
    if(day<10) cout<<"0"<<day<<"/";   else cout<<day<<"/";
    if(month<10) cout<<"0"<<month<<"/"; else cout<<month<<"/";
    if(year<10)cout<<"0"<<year; else cout<<year;
}

void CDate::chuanhoa_1(int x)
{
   while(x>0)
   {
      day++;
    if     (day>29&& month==2 && nhuan(year)==1)                                     {this->month++; this->day=1;}

    else if(day>28&& month==2 && nhuan(year)==0)                                     {this->month++; this->day=1;}

    else if(day>31 && (month==1||month==3||month==5||month==7||month==8||month==10)) {this->month++; this->day=1;}

    else if(day>31 && month==12)                                      {this->day=1; this->month=1; this->year+=1;}

    else if(day>30 && (month==4||month==6||month==9||month==11))                     {this->month++;this->day=1;}
   x--;
   }
}

void CDate::chuanhoa_2(int x)
{
 while(x>0)
  {
    day--;
    if     (day<1&& month==3 && nhuan(year)==1)                                     {this->month--; this->day=29;}

    else if(day<1&& month==3 && nhuan(year)==0)                                     {this->month--; this->day=28;}
        
    else if(day<1&& (month==4||month==6||month==9||month==11||month==2||month==8))  {this->month--; this->day=31;}
        
    else if(day<1&& (month==12||month==10||month==7||month==5||month==3))           {this->month--; this->day=30;}
        
    else if(day<1&&  month==1)                                       {this->month=12; this->day=31; this->year--;}

    x--;
  }
}
void CDate::copy(CDate &d1)
{
    d1.day=this->day;
    d1.month=this->month;
    d1.year=this->year;
}

void CDate::cong_x(int x)
{
    CDate d1;
    this->copy(d1);
    d1.chuanhoa_1(x);
    d1.Xuat();
}

void CDate::tru_x(int x)
{
    CDate d1;
    this->copy(d1);
    d1.chuanhoa_2(x);
    if(d1.checkdate()==1) d1.Xuat(); else cout<<"Error";
}
void CDate::cong_1()
{
    this->chuanhoa_1(1);
    this->Xuat();
}

void CDate::tru_1()
{
    CDate d1;
    this->copy(d1);
    d1.chuanhoa_2(1);
    if(d1.checkdate()==1) {this->chuanhoa_2(1); this->Xuat();}
    else cout<<"Error. Ngay da nhap khong thay doi.";
}

int CDate::TimeGap(CDate d2)
{
    if(d2.year>this->year||(d2.year==this->year&& d2.month>this->month)||
    (d2.year==this->year&& d2.month==this->month&& d2.day>this->day))
    {
        int Gap=0;
        while(true)
        {
            if(this->day==d2.day&& this->month==d2.month&& this->year==d2.year) break;
            Gap++;
            d2.chuanhoa_2(1);
        }
        return Gap;
    }
    else if(this->year==d2.year&& this->month==d2.month&& this->day==d2.day) return 0;
    else
    {
        int Gap=0;
        while(true)
        {
            if(this->day==d2.day&& this->month==d2.month&& this->year==d2.year) break;
            Gap++;
            d2.chuanhoa_1(1);
        }
        return Gap;
    }
}

int main()
{
    CDate d;

    while(true)
    {
        cout<<"______________________________________________\n"
            <<"1. Nhap ngay thang nam- default(01/01/01).\n"
            <<"2. Xuat ngay thang nam.\n"
            <<"3. Cong so nguyen ngay.\n"
            <<"4. Tru so nguyen ngay.\n"
            <<"5. Cong 1 ngay.\n"
            <<"6. Tru 1 ngay.\n"
            <<"7. Khoang cach voi ngay thu 2.\n"
            <<"0. END.\n"
            <<"______________________________________________\n"
            <<"Nhap lua chon: ";
            int key; cin>>key;
        if(key==0) break;
        else if(key==1)
        {
            d.Nhap();
        }
        else if(key==2)
        {
            d.Xuat();
        }
        else if(key==3)
        {
            cout<<"Nhap so nguyen ngay: ";
            int x; cin>>x;
            cout<<"Ket qua cong: ";
            d.cong_x(x);
        }
        else if(key==4)
        {
            cout<<"Nhap so nguyen ngay: ";
            int x; cin>>x;
            cout<<"Ket qua tru: ";
            d.tru_x(x);
        }
        else if(key==5)
        {
            cout<<"Ket qua cong 1: ";
            d.cong_1();
        }
        else if(key==6)
        {
            cout<<"Ket qua tru 1: ";
            d.tru_1();
        }
        else if(key==7)
        {
            CDate d2;
            cout<<"Nhap ngay thu 2. \n";
            d2.Nhap();
            cout<<d.TimeGap(d2)<<" ngay";
        }
        cout<<"\n";
    }
return 0;
}