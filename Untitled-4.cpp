// overloading operator

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class SinhVien
{
    private:
     int id;
    string name;
    public:
     friend istream & operator>>(istream &in, SinhVien &sv)
     {
         cout<<"Nhap id: "; in>> sv.id;
         in.ignore();
         cout<<"Nhap tên: "; getline(in, sv.name);
         return in;
     }
     friend ostream& operator <<( ostream &out, SinhVien sv)
     {
        out<<"ID: "<<sv.id<<" "<<"Name: "<<sv.name;
     }
     SinhVien operator +(SinhVien a)
     {
        SinhVien b;
        b.id=this->id+a.id;
        b.name=this->name+a.name;
        return b;
     }
     friend bool operator <(SinhVien a, SinhVien b)
     {
        return a.id<b.id;  
     }
};

int main()
{
    int n;
    cin>>n;
    SinhVien sv[n];
    for(int i=0; i<n; i++) cin>>sv[i];
    sort(sv, &sv[n]);
    for(int i=0; i<n; i++) cout<<sv[i]<<"\t";
    
return 0;
}