#include<bits/stdc++.h>
#include<string.h>
// Ví dụ cụ thể cho năm nhuận
//lý giải năm nhuận
using namespace std;

class Date
{
    public: 
    int day=0;
    int month=0;
    int year=0;
    public:
     void Nhap()
     {
        string dd, mm, yy;
        getline(cin, dd, '/');
        getline(cin, mm, '/');
        getline(cin, yy);
        this->day=atoi(dd.c_str());
        this->month=atoi(mm.c_str());
        this->year=atoi(yy.c_str());

         if((month==1||month==3||month==5||month==7||month==8||month==10||month==12) && (day<=0||day>31)) return Nhap();
         else if((month==4||month==6||month==9||month==11)&&(day<=0||day>30)) return Nhap();
         else if(month==2)
         {
            if(namnhuan(year)==1&& day<=0 && day>29) return Nhap();
            else if(day<=0&& day>28) return Nhap(); 
         }
         else if(month<=0||month>12) return Nhap();
     }
     bool namnhuan(int x)
     {
        if(x%400==0) return true;
        else if(x%4==0 && x%4!=100) return true;
        else return false;
     }
     void TheNextDay()
     {
        if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
        {
            if(day==31&& month==12) {day=1;month=1;year+=1;}
            else if(day==31) {day==1; month+=1;}
            else day+=1;
        }
        else if(month==4||month==6||month==9||month==11)
        {
            if(day==30) {day=1; month++;}
            else day+=1;
        }
        else if(month==2)
        {
            if(namnhuan(year)==1)
            {
                if(day==29) {day=1; month=3;}
                else day++;
            }
            else
            {
                if(day==28) {day=1; month=3;}
                else day++;
            }
        }
     }
     void Inday()
     {
        if(day<10) cout<<"0"<<day<<"/";
        else cout<<day<<"/";
        if(month<10) cout<<"0"<<month<<"/";
        else cout<<month<<"/";
        if(year<10) cout<<"000"<<year;
        else if(year<100&&year>=10) cout<<"00"<<year;
        else if(year<1000&& year>=100) cout<<"0"<<year;
        else cout<<year;
     }
};

int main()
{
    Date date;
    date.Nhap();
    date.TheNextDay();
    date.Inday();
return 0;
}