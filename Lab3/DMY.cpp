#include"DMY.h"
#include<iostream>
using namespace std;
bool DMY::CheckDMY(){
    if(Year>0){
        if(Month>0&&Month<13){
            if(Day>0&&Day<=GetDayOfMonth()){
                return true;
            }
            else{
                cout<<"Wrong day,again!\n";
                return false;
            }
        }
        else{
            cout<<"Wrong month,again!\n";
            return false;
        }
    }
    else{
        cout<<"Wrong year,again!\n";
        return false;
    }
}
int DMY::GetDayOfMonth(){
    int DayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((Month==2)&&((Year%4==0)&&Year%100!=0)||(Year%400==0)){
        return DayOfMonth[Month-1]+1;
    }
    return DayOfMonth[Month-1];
}
DMY::DMY()
{
    Day=Month=Year=0;
}

DMY::DMY(int d,int m ,int y)
{
    Day=d;
    Month=m;
    Year =y;
}
DMY::~DMY(){
}
void DMY::DecreaseYear(int amount) {
	if (Year - amount > 0)
			Year -= amount;
	else
	{
		cout << "Error amount!" << endl;
	}
}
void DMY::DecreaseMonth( int amount) {
	if (Month - amount <= 0) {
		DecreaseYear(1 + amount / 12);
		Month = 12 - abs(Month - amount) % 12;
		if (Month == 0) Month = 12;
	}
	else
	{
		Month -= amount;
	}
}
DMY DMY::operator-(int amount){
    int dayofmonth=GetDayOfMonth();
	if (Day - amount <= 0) {
		do {
			DecreaseMonth(1);
			dayofmonth = GetDayOfMonth();
			amount = amount - Day;
			Day = dayofmonth;
		} while (Day - amount < 0);
	}
	Day -= amount;
    return *this;
}
void DMY::IncreaseMonth(int amount) {
	Year += amount / 12;
	Month = (Month + amount) % 12;
	if (Month == 0) {
		Month = 12;
	}
}
DMY DMY::operator+(int amount){
	int dayofmonth=GetDayOfMonth();
	if (Day + amount > dayofmonth) {
		do {
			dayofmonth = GetDayOfMonth();
			IncreaseMonth(1);
			amount = amount - (dayofmonth - Day);
			Day = 0;
		} while (Day + amount > dayofmonth);
	}
	Day += amount;
    return *this;
}
long long DMY::GetTotalDay(){
    long long day=0;
    for(int i=1;i<Year;i++){
        if(i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
            day+=366;
        }
        else{
            day+=365;
        }
    }
    int DayOfMonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=1;i<Month;i++){
        if((i==2)&&CheckLeapYear()){
            day+= DayOfMonth[i-1]+1;
        }
        else{
            day+=DayOfMonth[i-1];
        }
    }
    return day+Day;
}
bool DMY::CheckLeapYear() {
	if (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0)) {
		return true;
	}
	return false;
}
long DMY::operator-(DMY & dmy){
    return this->GetTotalDay()-dmy.GetTotalDay();
}
DMY DMY::operator++(){
    return *this+1;
}
DMY DMY::operator--(){
    return *this-1;
}
ostream & operator<<(ostream& os,const DMY & dmy){
    os<<dmy.Day<<"/"<<dmy.Month<<"/"<<dmy.Year;
    return os;
}
istream & operator>>(istream& is,DMY & dmy){
    do{
    cout<<"Input day,month,year: ";
    is>>dmy.Day>>dmy.Month>>dmy.Year;
    }
    while(!dmy.CheckDMY());
}