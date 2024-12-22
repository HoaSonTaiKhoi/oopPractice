#include<iostream>
#include"DMY.h"
#include<cmath>
using namespace std;
int main(){
    DMY dmy1(20,3,2020); //initialize by constructor
    cout<<"dmy1 : "<<dmy1<<endl;
    cout<<"dmy1++ "<<(++dmy1)<<endl;
    cout<<"dmy1 + 50 days: "<<(dmy1+50)<<endl;
    DMY dmy2;
    cin>>dmy2;
    cout<<"dmy2 : "<<dmy2<<endl;
    cout<<"dmy2--: "<<(--dmy2)<<endl;
    cout<<"dmy2 - 100 days: "<<(dmy2-100)<<endl;
    cout<<"dmy1 : "<<dmy1.GetTotalDay()<<endl;
    cout<<"dmy2 : "<<dmy2.GetTotalDay()<<endl;
   cout<<"dmy2-dmy1 :"<<abs(dmy2-dmy1);
    return 0;
}