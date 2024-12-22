#ifndef NGAY_H_
#define NGAY_H_
#include<iostream>
using namespace std;
class DMY
{
private:
    int Day ;
    int Month;
    int Year;
public:
    int GetDayOfMonth();
    bool CheckDMY();
    DMY();
    DMY(int d,int m,int y);
    ~DMY();
    void DecreaseYear(int amount);
    void IncreaseMonth(int amount);
    void DecreaseMonth( int amount);
    DMY operator+(int amount);
    DMY operator-(int amount);
    long operator-(DMY & dmy);
    DMY operator++();
    DMY operator--();
    bool CheckLeapYear();
    long long GetTotalDay();
    friend ostream & operator<<(ostream& os,const DMY & dmy);
    friend istream & operator>>(istream& is,DMY & dmy);
};
#endif