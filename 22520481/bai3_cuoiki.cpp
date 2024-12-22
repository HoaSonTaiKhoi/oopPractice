
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<iomanip>
using namespace std;

class Malware
{
    protected:
     string name, file;
     float detection_rate;
    public:
     Malware();
     ~Malware();
    virtual void Nhap();
    virtual void Xuat();
    float get_detection_rate();
    virtual float Determine_DetectionRate()=0;
};

Malware::Malware(){}
Malware::~Malware(){}

void Malware::Nhap()
{
    cout<<"Nhap ten: "; cin>>name;
    cout<<"Nhap ten file: "; cin>>file;
}

void Malware::Xuat()
{
    cout<<"\n#Result: "
        <<"\n-Name: "<<name
        <<"\n-File's Name: "<<file;
}

float Malware::get_detection_rate()
{
    this->detection_rate=this->Determine_DetectionRate();
    return this->detection_rate;
}

class Virus:public Malware
{
    private:
     string signature, behaviour;
    public:
     Virus();
     ~Virus();
     void Nhap();
     void Xuat();
     float Determine_DetectionRate();
};

Virus::Virus():Malware(){}
Virus::~Virus(){}

void Virus::Nhap()
{
    Malware::Nhap();
    cout<<"Nhap signature: ";cin>>signature;
    cout<<"Nhap behaviour: "; cin>>behaviour;
}

void Virus::Xuat()
{
    Malware::Xuat();
    cout<<"\n-Signature: "<<signature
        <<"\n-Behaviour: "<<behaviour;
}

float Virus::Determine_DetectionRate()
{
    string s="ILoveYou";
    if(this->signature.length()!=s.length()) return 0.01;
    for(int i=0; i<this->signature.length(); i++)
    {
        if(this->signature[i]!=s[i]) return 0.01;
    }
    return 99.99;
}


class Ransomeware:public Malware
{
    private:
     string encryptKey;
     double  ransomAmount;
    public:
     Ransomeware();
     ~Ransomeware();
     void Nhap();
     void Xuat();
     float Determine_DetectionRate();
};

Ransomeware::Ransomeware():Malware(){}
Ransomeware::~Ransomeware(){}

void Ransomeware::Nhap()
{
    Malware::Nhap();
    cout<<"Nhap encryptKey: ";cin>>encryptKey;
    cout<<"Nhap ransomAmount: "; cin>>ransomAmount;
}

void Ransomeware::Xuat()
{
    Malware::Xuat();
    cout<<"\n-EncryptKey: "<<encryptKey
        <<"\n-RansomAmount: "<<ransomAmount;
}

float Ransomeware::Determine_DetectionRate()
{
    if(encryptKey.length()<8) return 96.69;
    return 3.31;
}

int main()
{
    Malware* mal;
    while(true)
    {
        cout<<"---------------------\n"
            <<"1. Virus\n"
            <<"2. Ransomeware\n"
            <<"0. END\n"
            <<"---------------------\n"
            <<"Lua chon: ";
        int key;
        cin>>key;
        if(key==0) break; //END.
        else if(key==1) 
        {
            mal=new Virus();
            mal->Nhap();
            mal->Xuat();
            cout<<"\n#Detection_rate: "<<mal->get_detection_rate();
        }
        else if(key==2)
        {
            mal=new Ransomeware();
            mal->Nhap();
            mal->Xuat();
            cout<<"\n#Detection_rate: "<<mal->get_detection_rate();
        }
        cout<<"\n";
    }
    return 0;
}

