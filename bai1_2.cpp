
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<iomanip>
using namespace std;
class SUBJECT_POINT
{
    private:
     string name;
     float point_of_process, midterm_point, final_point, point_average_of_subject;
    public:
     SUBJECT_POINT();
     ~SUBJECT_POINT();
     void Nhap();
     void Xuat();
     float get_point_average_of_subject();
     friend istream& operator >>(istream& in, SUBJECT_POINT& sp1);
     friend ostream& operator <<(ostream& out, SUBJECT_POINT& sp1);
};

SUBJECT_POINT::SUBJECT_POINT()
{
    point_of_process=midterm_point=final_point=point_average_of_subject=0;
}

SUBJECT_POINT::~SUBJECT_POINT(){}

void SUBJECT_POINT::Nhap()
{
    cin>>this->name;
    cin>>this->point_of_process>>this->midterm_point>>this->final_point;
}

void SUBJECT_POINT::Xuat()
{
    cout<<this->name<<": "<<this->get_point_average_of_subject();
}

float SUBJECT_POINT::get_point_average_of_subject()
{
    this->point_average_of_subject=this->point_of_process*0.2+this->midterm_point*0.3+this->final_point*0.5;
return this->point_average_of_subject;
}

istream &operator>>(istream &in, SUBJECT_POINT &sp1)
{
    in>>sp1.name>>sp1.point_of_process>>sp1.midterm_point>>sp1.final_point;
return in;
}

ostream &operator<<(ostream &out, SUBJECT_POINT& sp1)
{

    out<<sp1.name<<": "<<sp1.get_point_average_of_subject();
    return out;
}

// bai 2
class DS_subject_point
{
    private:
     vector<SUBJECT_POINT*> ds;
     int n;
    public:
     DS_subject_point();
     ~DS_subject_point();
     void Nhap_Xuat();
     void GPA();
     void point_max_min();
};

DS_subject_point::DS_subject_point(){}
DS_subject_point::~DS_subject_point(){ ds.clear();}

void DS_subject_point::Nhap_Xuat()
{
    cout<<"Nhap so mon: ";
    cin>>this->n;
    for(int i=0; i<n; i++)
    {
        SUBJECT_POINT* sp=new SUBJECT_POINT();
        sp->Nhap();
        ds.push_back(sp);
    }

cout<<"\n#Result: \n";
    for(int i=0; i<n; i++)
    {
        cout<<*ds[i]<<"\n";
        //ds[i]->Xuat();
    }
}

void DS_subject_point::GPA()
{
       float Summary=0;
       for(int i=0; i<n; i++)
       Summary+=ds[i]->get_point_average_of_subject();
    float GPA=Summary/n;
    cout<<"\n#GPA: "<<fixed<<setprecision(2)<<GPA<<"\n";
}

void DS_subject_point::point_max_min()
{
    float max, min;
    max=min=ds[0]->get_point_average_of_subject();
    for(int i=1; i<n; i++)
    {
        if(max<ds[i]->get_point_average_of_subject()) max=ds[i]->get_point_average_of_subject();
        if(min>ds[i]->get_point_average_of_subject()) min=ds[i]->get_point_average_of_subject();
    }

    cout<<"\n#Subject_point_max: \n";
    for(int i=0; i<n; i++)
    {
        if(ds[i]->get_point_average_of_subject()==max) cout<<*ds[i]<<"\n";
    }

    cout<<"\n#Subject_point_min: \n";
    for(int i=0; i<n; i++)
    {
        if(ds[i]->get_point_average_of_subject()==min) cout<<*ds[i]<<"\n";
    }
}

int main()
{
    DS_subject_point danhsach;
    danhsach.Nhap_Xuat();
    danhsach.GPA();
    danhsach.point_max_min();
return 0;
}