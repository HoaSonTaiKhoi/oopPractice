#include<bits/stdc++.h>
using namespace std;
class Sach
{
    protected:
    string masach;
    string tensach;
    string nxb;
    int soluong;
    long long dongia;
    public:
    virtual long long tinhtien()=0;
    virtual void nhap()
    {
        cout<<"Nhap vao cac thong tin sach: ";
        cin>>masach;
        cin.ignore();
        getline(cin,tensach);
        getline(cin,nxb);
        cin>>soluong>>dongia;
    }
    virtual void xuat()
    {
        cout<<masach<<" "<<tensach<<" "<<nxb<<" "<<soluong<<" "<<dongia<<" ";
    }
    virtual int phanloai()=0;
    string getNXB()
    {
        return nxb;
    }
};
class Sachgk:public Sach
{
    private:
    int tinhtrang;
    public:
    Sachgk(){};
    void nhap()
    {
        Sach::nhap();
        cout<<"Neu la sach cu thi nhap tinh trang la 0, moi thi la 1: ";
        cin>>tinhtrang;
    }
    void xuat()
    {
        Sach::xuat();
        if(tinhtrang==0) cout<<"Sach cu\n";
        else if(tinhtrang==1) cout<<"Sach moi\n";
    }
    long long tinhtien()
    {
        long long s=0;
        if(tinhtrang==1) s=soluong*dongia;
        else if(tinhtrang==0) s=soluong*dongia*0.5;
        return s;
    }
    int phanloai()
    {
        return 0;
    }
};
class Sachtk:public Sach
{
    private:
    long long tienthue;
    public:
    Sachtk(){};
    void nhap()
    {
        Sach::nhap();
        cin>>tienthue;
    }
    void xuat()
    {
        Sach::xuat();
        cout<<tienthue<<endl;
    }
    long long tinhtien()
    {
        long long s=0;
        s=dongia*soluong+tienthue;
        return s;
    }
    int phanloai()
    {
        return 1;
    }
};
class Quanly
{
    private:
    vector<Sach*>ds_ql;
    public:
    Quanly(){};
    Quanly(vector<Sach*>temp)
    {
        ds_ql=temp;
    }
    void nhap()
    {
        int n;
        cout<<"Nhap so sach: ";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            Sach *x;
            int choice;
            cout<<"Nhap 0 neu sach nhap vao la sach giao khoa, 1 neu la sach tham khao: ";
            cin>>choice;
            if(choice==0)
            {
                x=new Sachgk;
                x->nhap();
                ds_ql.push_back(x);
            }
            if(choice==1)
            {
                x=new Sachtk;
                x->nhap();
                ds_ql.push_back(x);
            }
        }
    }
    void xuat()
    {
        for(int i=0;i<ds_ql.size();i++)
        {
            ds_ql[i]->xuat();
        }
    }
    void tongtienmoiloaisach(long long &sgk,long long &stk)
    {
        for(int i=0;i<ds_ql.size();i++)
        {
            if(ds_ql[i]->phanloai()==0)
            {
                sgk+=ds_ql[i]->tinhtien();
            }
            if(ds_ql[i]->phanloai()==1)
            {
                stk+=ds_ql[i]->tinhtien();
            }
        }
    }
    vector<Sach*> ds_min()
    {
        vector<Sach*> temp;
        long long min=1000000000000;
        for(int i=0;i<ds_ql.size();i++)
        {
            if(ds_ql[i]->tinhtien()<min) min=ds_ql[i]->tinhtien();
        }
        for(int i=0;i<ds_ql.size();i++)
        {
            if(ds_ql[i]->tinhtien()==min) temp.push_back(ds_ql[i]);
        }
        return temp;
    }
    vector<Sach*> searchNXB(string name_nxb)
    {
        vector<Sach*>tempp;
        for(int i=0;i<ds_ql.size();i++)
        {
            if(ds_ql[i]->getNXB()==name_nxb&&ds_ql[i]->phanloai()==0)
            tempp.push_back(ds_ql[i]);
        }
        return tempp;
    }
};
int main()
{
    Quanly*quanly=new Quanly;
    quanly->nhap();
    quanly->xuat();
    Quanly*min= new Quanly(quanly->ds_min());
    min->xuat();
    string name_nxb;
    cin>>name_nxb;
    vector<Sach*> ds_of_nxb;
    ds_of_nxb=quanly->searchNXB(name_nxb);
    for(int i=0;i<ds_of_nxb.size();i++)
    {
        ds_of_nxb[i]->xuat();
    }
}

