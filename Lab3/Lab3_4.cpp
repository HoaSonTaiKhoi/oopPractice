#include<bits/stdc++.h>
#include<math.h>
#include<algorithm>
using namespace std;

class Dathuc
{
   private:
    double *a=new double;
    int n;
   public:
    Dathuc();
    ~Dathuc();
    friend istream &operator >>(istream &in, Dathuc &p);
    friend ostream &operator <<(ostream &out, Dathuc p);
    void Value(double x);
    void operator +(Dathuc p2);
    void operator -(Dathuc p2);
};

Dathuc::Dathuc() {this->n=0;this->a=new double;}

Dathuc::~Dathuc(){delete [] a;}

istream &operator>>(istream &in, Dathuc &p)
{
   cout<<"Nhap bac da thuc: "; in>>p.n;
   p.a=new double[p.n+1];
   for(int i=p.n; i>=0; i--)
   in>>p.a[i];
   return in;
}

ostream &operator<<(ostream &out, Dathuc p)
{
   for(int i=p.n; i>=0; i--)
   {
     if(i==1)
     {
        if(p.a[i]!=0)
        {
            if(p.a[i]==1) out<<"+x";
            else if(p.a[i]==-1) out<<"-x";
            else if(p.a[i]>1) out<<"+"<<p.a[i]<<"x";
            else out<<p.a[i]<<"x";
        }
     }

     else if(i==0)
     {
        if(p.a[i]!=0)
        {
            if(p.n!=0)
            {
             if(p.a[i]==1) out<<"+"<<p.a[i];
             else if(p.a[i]>1) out<<"+"<<p.a[i];
             else out<<p.a[i];
            }
            else out<<p.a[i];
        }
        else if(p.n==0&&p.a[i]) out<<0;
     }

     else if(i==p.n)
     {
        if(p.a[i]!=0)
        {
            if(p.a[i]==1) out<<"x^"<<p.n;
            else if(p.a[i]==-1) out<<"-x^"<<p.n;
            else if(p.a[i]>1) out<<p.a[i]<<"x^"<<p.n;
            else out<<p.a[i]<<"x^"<<p.n;
        }
     }
     else
     {
        if(p.a[i]!=0)
        { 
          if(p.a[i]==1) out<<"+x^"<<i;
          else if(p.a[i]==-1) out<<"-x^"<<i;
          else if(p.a[i]>1) out<<"+"<<p.a[i]<<"x^"<<i;
          else out<<p.a[i]<<"x^"<<i;
        }
     }
   }
   return out;
}


void Dathuc::Value(double x)
{
    double value=0;
    for(int i=n; i>=0; i--)
    {
        value+=this->a[i]*pow(x, i);
    }
    cout<<"f(x)= "<<value;
}

void Dathuc::operator +(Dathuc p2)
{
    Dathuc p;
    if(this->n>p2.n)
    {
        p.n=this->n;
        p.a=new double[this->n+1];
        for(int i=this->n; i>=0; i--)
        {
            if(p2.n>=i) p.a[i]=this->a[i]+p2.a[i];
            else p.a[i]=this->a[i];
        }
    }
    else if(this->n<p2.n)
    {
        p.n=p2.n;
        p.a=new double[p2.n+1];
        for(int i=p2.n; i>=0; i--)
        {
            if(this->n >= i) p.a[i]=this->a[i]+p2.a[i];
            else p.a[i]=p2.a[i];
        }
    }
    else
    {
        p.n=p2.n;
        p.a=new double[p2.n+1];
        for(int i=p2.n; i>=0; i--)
        {
            p.a[i]=this->a[i]+p2.a[i];
        }
    }
    cout<<p;
}

void Dathuc::operator - (Dathuc p2)
{
    Dathuc p;
    if(this->n>p2.n)
    {
        p.n=this->n;
        p.a=new double[this->n+1];
        for(int i=this->n; i>=0; i--)
        {
            if(p2.n>=i) p.a[i]=this->a[i] - p2.a[i];
            else p.a[i]=this->a[i];
        }
    }
    else if(this->n<p2.n)
    {
        p.n=p2.n;
        p.a=new double[p2.n+1];
        for(int i=p2.n; i>=0; i--)
        {
            if(this->n >= i) p.a[i]=this->a[i]-p2.a[i];
            else p.a[i]=-p2.a[i];
        }
    }
    else
    {
        p.n=p2.n;
        p.a=new double[p2.n+1];
        for(int i=p2.n; i>=0; i--)
        {
            p.a[i]=this->a[i]-p2.a[i];
        }
    }
    cout<<p;
}

int main()
{
    Dathuc p1;
    while(true)
    {
        cout<<"_________________________________\n"
            <<"1. Nhap da thuc.\n"
            <<"2. Xuat da thuc.\n"
            <<"3. Tinh gia tri bieu thuc theo x.\n"
            <<"4. Cong hai da thuc.\n"
            <<"5. Tru hai da thuc.\n"
            <<"0. END.\n"
            <<"_________________________________\n"
            <<"Nhap lua chon: ";
        int key; cin>>key;
        if(key==0)  break;
        else if(key==1)  cin>>p1;
        else if(key==2)  cout<<p1;
        else if(key==3)
          {
            double x; cin>>x;
            p1.Value(x);
          }
        else if(key==4)
          {
            Dathuc p2;
            cout<<"Nhap da thuc thu 2.\n";
            cin>>p2;
            p1+p2;
          }
        else if(key==5)
          {
            Dathuc p2;
            cout<<"Nhap da thuc thu 2.\n";
            cin>>p2;
            p1-p2;
          }
        cout<<"\n";
    }
return 0;
}