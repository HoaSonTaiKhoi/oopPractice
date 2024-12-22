#include<iostream>
#include"CTimeSpan.h"
using namespace std;

CTimeSpan::CTimeSpan(){
    this->Day=this->Hour=this->Minute=this->second=0;
}
CTimeSpan::CTimeSpan(long d,int h,int m,int s){
    this->Day=d;
    this->Hour=h;
    this->Minute=m;
    this->second=s;
}
CTimeSpan::~CTimeSpan(){}

long CTimeSpan::GetDay(){
    return this->Day;
}
int CTimeSpan::GetHour(){
    return this->Hour;
}
int CTimeSpan::GetMinute(){
    return this->Minute;
}
int CTimeSpan::GetSecond(){
        return this->second;
}
long CTimeSpan::GetTotalHour(){
    return this->Hour+this->Day*24;
}
long CTimeSpan::GetTotalMinute(){
    return this->Minute+this->Hour*60+this->Day*24*60;
}
long CTimeSpan::GetTotalSecond(){
    return this->second+this->Minute*60+this->Hour*60*60+this->Day*24*60*60;
}
ostream& operator<<(ostream & os,CTimeSpan & Time){
    os<<Time.Day<<"d"<<Time.Hour<<"h"<<Time.Minute<<"m"<<Time.second<<"s";
    return os;
}
istream& operator>>(istream& is,CTimeSpan & Time){
    is>>Time.Day>>Time.Hour>>Time.Minute>>Time.second;
}
void CTimeSpan::AddTime(CTimeSpan & T1,CTimeSpan & T2){
    this->Day=(T1.GetTotalHour()+T2.GetTotalHour())/24;
    this->Hour=(T1.GetTotalHour()+T2.GetTotalHour())%24;
    this->Minute=(T1.GetTotalMinute()+T2.GetTotalMinute())%60;
    this->second=(T1.GetTotalSecond()+T2.GetTotalSecond())%60;
}
void CTimeSpan::SubTime(CTimeSpan & T1,CTimeSpan & T2){
    if(T1.GetTotalSecond()-T2.GetTotalSecond()<0){
        cout<<"Fail,negative time!"<<endl;
        return;
    }
    this->Day=(T1.GetTotalHour()-T2.GetTotalHour())/24;
    this->Hour=(T1.GetTotalHour()-T2.GetTotalHour())%24;
    this->Minute=(T1.GetTotalMinute()-T2.GetTotalMinute())%60;
    this->second=(T1.GetTotalSecond()-T2.GetTotalSecond())%60;
}
bool CTimeSpan::IsEqual(CTimeSpan & T){
    return(this->GetTotalSecond()==T.GetTotalSecond());
}
bool CTimeSpan::GreaterThan(CTimeSpan & T){
    return (this->GetTotalSecond()>T.GetTotalSecond());
}
bool CTimeSpan::GreaterEqualThan(CTimeSpan & T){
    return (this->GetTotalSecond()>=T.GetTotalSecond());
}
bool CTimeSpan::LowerThan(CTimeSpan & T){
    return (this->GetTotalSecond()<T.GetTotalSecond());
}
bool CTimeSpan::LowerEqualThan(CTimeSpan & T){
    return (this->GetTotalSecond()<=T.GetTotalSecond());
}