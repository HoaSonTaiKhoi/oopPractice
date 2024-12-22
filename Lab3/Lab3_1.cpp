#include<bits/stdc++.h>
#include<math.h>
using namespace std;

class CTimeSpan
{
    private:
     int day, hour, min, sec;
    public:
     CTimeSpan();
     void Nhap();
     void Xuat();
     void chuanhoa();
     void chuanhoa(int get_total_sec);

     int getday();
     int gethour();
     int getmin();
     int getsec();
     int get_total_hour();
     int get_total_min();
     int get_total_sec();

     void cong(CTimeSpan &t1, CTimeSpan &t2);
     void tru(CTimeSpan &t1, CTimeSpan &t2);

     bool Equal(CTimeSpan &t);
     bool Greater(CTimeSpan &t);
     bool Greater_or_equal(CTimeSpan &t);
     bool Smaller(CTimeSpan &t);
     bool Smaller_or_equal(CTimeSpan &t);
   
};


CTimeSpan::CTimeSpan()
{
    this->day=this->hour=this->min=this->sec=0;
}

int CTimeSpan::getday () {return this->day;  }
int CTimeSpan::gethour() {return this->hour; }
int CTimeSpan::getmin () {return this->min;  }
int CTimeSpan::getsec () {return this->sec;  }

int CTimeSpan::get_total_hour() { return this->day*24+this->hour;                                 }
int CTimeSpan::get_total_min () { return this->day*24*60+this->hour*60+this->min;                 }  
int CTimeSpan::get_total_sec () { return this->day*3600*24+this->hour*3600+this->min*60+this->sec;}

void CTimeSpan::chuanhoa()
{
   this->day = (get_total_sec ()/86400);
   this->hour= (get_total_sec ()/3600 )%24;
   this->min = (get_total_sec ()/60   )%60;
   this->sec = (get_total_sec ()      )%60;
}

void CTimeSpan::chuanhoa(int get_total_sec)
{
  this->day  =  (get_total_sec/86400);
  this->hour =  (get_total_sec/3600)%24;
  this->min  =  (get_total_sec/60)%60;
  this->sec  =   get_total_sec%60;
}

void CTimeSpan::Nhap()
{
    cout<<"Nhap ngay: "; cin>>this->day;
    cout<<"Nhap gio: "; cin>>this->hour;
    cout<<"Nhap phut: "; cin>>this->min;
    cout<<"Nhap giay: "; cin>>this->sec;
    chuanhoa();
}

void CTimeSpan::Xuat()
{
    cout<<this->day<<"d "<<this->hour<<"h "<<this->min<<"m "<<this->sec<<"s";
}


bool CTimeSpan::Equal(CTimeSpan &t)           { return this->get_total_sec() == t.get_total_sec();}

bool CTimeSpan::Greater(CTimeSpan &t)         { return this->get_total_sec() >  t.get_total_sec();}

bool CTimeSpan::Greater_or_equal(CTimeSpan &t){ return this->get_total_sec() >= t.get_total_sec();}

bool CTimeSpan::Smaller(CTimeSpan &t)         { return this->get_total_sec() <  t.get_total_sec();}

bool CTimeSpan::Smaller_or_equal(CTimeSpan &t){ return this->get_total_sec() <= t.get_total_sec();}


void CTimeSpan::cong(CTimeSpan &t1, CTimeSpan &t2)
{
    CTimeSpan t;
    t.chuanhoa(t1.get_total_sec()+t2.get_total_sec());
    cout<<"Ket qua cong: ";
    t.Xuat();
}

void CTimeSpan::tru(CTimeSpan &t1, CTimeSpan &t2)
{
    CTimeSpan t;
    t.chuanhoa(abs(t1.get_total_sec()-t2.get_total_sec()));
    cout<<"Ket qua tru: ";
    t.Xuat();
}

int main()
{
    CTimeSpan t1, t2;
    while(true)
    {
        cout<<"_________________\n"
            <<"1. Nhap t1, t2.\n"
            <<"2. Xuat t1, t2.\n"
            <<"3. Cong t1, t2.\n"
            <<"4. Tru  t1, t2.\n"
            <<"5. So sanh.\n"
            <<"0. END.\n"
            <<"_________________\n"
            <<"Nhap lua chon: ";
        int key; cin>>key;
        if     (key==0) break;
        else if(key==1)
          {
            cout<<"Nhap t1.\n";
            t1.Nhap();
            cout<<"Nhap t2.\n";
            t2.Nhap();
          }
        else if(key==2)
          {
            cout<<"Time1: \t";t1.Xuat();
            cout<<"\n";
            cout<<"Time2: \t";t2.Xuat();
          }
        else if(key==3)
          {
            CTimeSpan t;
            t.cong(t1,t2);
          }
        else if(key==4)
          {
            CTimeSpan t;
            t.tru(t1,t2);
          }
        else if(key==5)
          {
            while(true)
            {
                cout<<"_________________\n"
                    <<"1. Equal.\n"
                    <<"2. Greater.\n"
                    <<"3. Greater_equal.\n"
                    <<"4. Smaller.\n"
                    <<"5. Smaller_equal.\n"
                    <<"0. Quay lai.\n"
                    <<"_________________\n"
                    <<"Lua chon: ";
                    cin>>key;
                if(key==0) break;
                else if(key==1) cout<<t1.Equal(t2);           
                else if(key==2) cout<<t1.Greater(t2);         
                else if(key==3) cout<<t1.Greater_or_equal(t2);
                else if(key==4) cout<<t1.Smaller(t2);         
                else if(key==5) cout<<t1.Smaller_or_equal(t2);  
            }
          }
        cout<<"\n";
    }
return 0;
}