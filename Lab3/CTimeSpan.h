#pragma once
#include<bits/stdc++.h>
using namespace std;
class CTimeSpan
{
private:
    long Day;
    int Hour;
    int Minute;
    int second;
public:
    CTimeSpan();
    CTimeSpan(long d,int h,int m,int s);
    ~CTimeSpan();
    long GetDay();
    int GetHour();
    int GetMinute();
    int GetSecond();
    long GetTotalHour();
    long GetTotalMinute();
    long GetTotalSecond();
    friend ostream& operator<<(ostream & os,CTimeSpan & Time);
    friend istream& operator>>(istream& is,CTimeSpan & Time);
    void AddTime(CTimeSpan & T1,CTimeSpan & T2);
    void SubTime(CTimeSpan & T1,CTimeSpan & T2);
    bool IsEqual(CTimeSpan & T);
    bool GreaterThan(CTimeSpan & T);
    bool GreaterEqualThan(CTimeSpan & T);
    bool LowerThan(CTimeSpan & T);
    bool LowerEqualThan(CTimeSpan & T);
};