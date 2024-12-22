#include<bits/stdc++.h>
#include<string.h>
class Time
{
    private:
     int day;
     int month;
     int year;
    public:
    std::string d,m,y;
     Time()
     {// Chuoi nhap vao phai co dang dd/mm/yyyy
         getline(std::cin, d, '/');
         getline(std::cin, m, '/');
         getline(std::cin, y);
         this->day=atoi(d.c_str());
         this->month=atoi(m.c_str());
         this->year=atoi(y.c_str());
     }
     bool nam_nhuan()
     {
        return(((year%4==0)&&(year%100!=0))||(year%400==0));
     }
     void TheNextDay()
     { 
         if(month==1 ||month==3||month==5||month==7||month==8||month==10||month==12)
         {
            if(month==12&& day==31) {day=1;month=1;year++;}
            else if(day==31) {month+=1; day=1;} 
            else day++;
         }
         else if(month==4||month==6 ||month==9||month==11)
         {
            if(day==30){day=1; month+=1;}
            else day++;
         }
         else if(month==2)
         {
            if(nam_nhuan()==1)
            {
               if(day==29) {day=1; month++;}
               else day++;
            } 
            else
            {
               if(day==28) {day=1; month=3;}
               else day++;
            }
         }
         if(day<10) std::cout<<"0"<<day<<"/";
         else std::cout<<day<<"/";
         if(month<10) std::cout<<"0"<<month<<"/";
         else std::cout<<month<<"/";
         if(year<10) std::cout<<"000"<<year;
         else if(year<100 && year>=10) std::cout<<"00"<<year;
         else if(year>=100&& year <1000) std::cout<<"0"<<year;
         else std::cout<<year;
     }
     
};

int main()
{
    Time time1;
    time1.TheNextDay();
return 0;
}