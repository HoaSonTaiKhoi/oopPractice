
#include "bits/stdc++.h"
using namespace std;

class String
{
    private:
     queue<char> a;
     stack<char> b;
    public:
     String();
     ~String();
     friend istream& operator >>(istream &in, String&s);
     friend ostream& operator <<(ostream &out, String s);
     
     void reverse();
     int size();
     void get_queue(queue<char> &a);
     void get_stack(stack<char> &b);

     friend String& operator + (String &s, String s1);
     String& operator = (String s1);
};

String::String(){ a.push('0');}

String::~String()
    {
    while(!a.empty()) a.pop();
    while(!b.empty()) b.pop();
    }

istream& operator >>(istream &in, String &s)
{
    char x;
        if(!s.a.empty()) while(!s.a.empty()) s.a.pop();
        fflush(stdin);
        while(true)
        {
            x=getchar();
            if(x=='\n') break;
            s.a.push(x);
            s.b.push(x);
        }
        return in;
}

ostream &operator<<(ostream &out, String s)
{
    while(!s.a.empty())
        {
            out<<s.a.front(); 
            s.a.pop();
        }
        return out;
}

void String::reverse()
{
    while(!a.empty()) a.pop();
    while(!b.empty()) {a.push(b.top()); b.pop();}
        queue<char> d=a;
    while(!d.empty()) {b.push(d.front()); d.pop();}
}

int String::size()
{
    int n=0;
        queue<char> c=a;
        while(!c.empty())
        {
            n++;
            c.pop();
        }
    return n;
}

void String::get_queue(queue<char> &a)
{
    a=this->a;
}

void String::get_stack(stack<char> &b)
{
    b=this->b;
}

String& operator+(String &s, String s1)
{
    while(!s1.a.empty())
        {
            s.a.push(s1.a.front());
            s.b.push(s1.a.front());
            s1.a.pop();
        }
    return s;
}

String& String::operator = (String s1)
{
    queue<char> a; s1.get_queue(a);
    stack<char> b; s1.get_stack(b);
    this->a=a;
    this->b=b;
    return *this;
}



int main()
{
    String s;

    while(true)
    {
        cout<<"__________________\n"
            <<"1. Nhap string.\n(default 0)\n"
            <<"2. Xuat string.\n"
            <<"3. Size.\n"
            <<"4. Noi string 2.\n"
            <<"5. Reverse.\n"
            <<"0. END.\n"
            <<"__________________\n"
            <<"Nhap lua chon: ";
        int x; cin>>x;

        if     (x==0) break;
        else if(x==1) {cout<<"Nhap string: ";cin>>s;}
        else if(x==2) cout<<s<<"\n";
        else if(x==3) cout<<"Do lon chuoi: "<<s.size()<<"\n";
        else if(x==4)
        {
            String s2, s3; s2=s;
            cout<<"Nhap string thu 2:"; cin>>s3;
            s2=s2+s3;
            cout<<s2<<"\n";
        }
        // else if(x==4)
        // {
        //     String s2;
        //     cout<<"Nhap string thu 2:"; cin>>s2;
        //     s=s+s2;
        //     cout<<s<<"\n";
        // }
        else if(x==5) 
        {
            s.reverse();
            cout<<s<<"\n";
        }
    }
return 0;
}


