
#include<bits/stdc++.h>
#include<graphics.h>
#include<winbgim.h>
#include<time.h>
#include<string>
#include<math.h>


using namespace std;

class DIEM
{
    private:
     //Tọa độ thực của điểm
     double x,y;
     //Tọa độ pixel để in ra màn hình
     int a,b;
    public:
     DIEM();
     ~DIEM();
     virtual void Nhap(int i);
     //Phương thức vẽ điểm
     virtual void Xuat();

     double getx(){return x;}
     double gety(){return y;}
     int geta(){return a;}
     int getb(){return b;}
};

DIEM::DIEM()
{
    this->x=this->y=0;
    this->a=(int)getmaxx()/2;
    this->b=(int)getmaxy()/2;
}
DIEM::~DIEM(){}

void DIEM::Nhap(int i)
{
        setcolor(BLACK);
        cout<<"(x y): ";cin>>x>>y;
        //In giá trị đã nhập ra màn hình
        char s[20];
        sprintf(s, "Diem thu %d: %0.1f  %0.1f",i+1, x, y);
        outtextxy(520, 75+i*25, (char*)s);
        
        // Đổi tọa độ điểm thành tọa độ pixel
         a=(int)getmaxx()/2+x*20;
         b=(int)getmaxy()/2+100-y*20;
}

void DIEM::Xuat()
{
    setbkcolor(WHITE);
    setfillstyle(0, WHITE);
    setcolor(WHITE);
    fillellipse(a, b, 4, 4);
    setfillstyle(0, WHITE);
}

class TUGIAC
{
    private:
     DIEM *ds;
    public:
     TUGIAC();
     ~TUGIAC();
     virtual void Nhap();
     virtual void Xuat(int check);
     virtual vector<pair<double, double>> ds_vector();
     DIEM *get_ds(){return ds;}
     virtual bool check();
     void MENU();
     void Oxy();
     void Choice();
     void Choice_1(char* key);
     void d_line(int a, int b, int c, int d);
};


TUGIAC::TUGIAC(){this->ds=new DIEM[4];}
TUGIAC::~TUGIAC(){}

void TUGIAC::Nhap()
{
    for(int i=0; i<4; i++)
    {
        cout<<"Nhap diem thu "<<i+1<<" ";
        ds[i].Nhap(i);
    }
}

void TUGIAC::Xuat(int check)
{
    DIEM *ds=this->get_ds();
    vector<pair<double,double>> v= this->ds_vector();
    for(int i=0; i<4; i++)
     ds[i].Xuat();
    if(check==1)
    {
        d_line(ds[0].geta(), ds[0].getb(), ds[1].geta(), ds[1].getb());
        d_line(ds[2].geta(), ds[2].getb(), ds[3].geta(), ds[3].getb());
        if(v[0].first*v[5].first>0)
        {
            d_line(ds[1].geta(), ds[1].getb(), ds[3].geta(), ds[3].getb());
            d_line(ds[0].geta(), ds[0].getb(), ds[2].geta(), ds[2].getb());
        }
        else if(v[0].first*v[5].first<0)
        {
            d_line(ds[2].geta(), ds[2].getb(), ds[1].geta(), ds[1].getb());
            d_line(ds[0].geta(), ds[0].getb(), ds[3].geta(), ds[3].getb());
        }
    }
    else if(check==2)
    {
        d_line(ds[0].geta(), ds[0].getb(), ds[2].geta(), ds[2].getb());
        d_line(ds[1].geta(), ds[1].getb(), ds[3].geta(), ds[3].getb());
        if(v[1].first*v[4].first>0)
        {
            d_line(ds[0].geta(), ds[0].getb(), ds[1].geta(), ds[1].getb());
            d_line(ds[2].geta(), ds[2].getb(), ds[3].geta(), ds[3].getb());
        }
        else if(v[1].first*v[4].first<0)
        {
            d_line(ds[0].geta(), ds[0].getb(), ds[3].geta(), ds[3].getb());
            d_line(ds[2].geta(), ds[2].getb(), ds[1].geta(), ds[1].getb());
        }
    }
    else
    {
        d_line(ds[0].geta(), ds[0].getb(), ds[3].geta(), ds[3].getb());
        d_line(ds[1].geta(), ds[1].getb(), ds[2].geta(), ds[2].getb());   
        if(v[2].first*v[3].first>0)
        {
            d_line(ds[0].geta(), ds[0].getb(), ds[1].geta(), ds[1].getb());
            d_line(ds[2].geta(), ds[2].getb(), ds[3].geta(), ds[3].getb());
        }
        else if(v[2].first*v[3].first<0)
        {
            d_line(ds[0].geta(), ds[0].getb(), ds[2].geta(), ds[2].getb());
            d_line(ds[3].geta(), ds[3].getb(), ds[1].geta(), ds[1].getb());
        }
    }
}

vector<pair<double, double>> TUGIAC::ds_vector()
{
         vector<pair<double, double>> v;
    v.push_back({ds[0].getx()-ds[1].getx(), ds[0].gety()- ds[1].gety()});
    v.push_back({ds[0].getx()-ds[2].getx(), ds[0].gety()- ds[2].gety()});
    v.push_back({ds[0].getx()-ds[3].getx(), ds[0].gety()- ds[3].gety()});
    v.push_back({ds[1].getx()-ds[2].getx(), ds[1].gety()- ds[2].gety()});
    v.push_back({ds[1].getx()-ds[3].getx(), ds[1].gety()- ds[3].gety()});
    v.push_back({ds[2].getx()-ds[3].getx(), ds[2].gety()- ds[3].gety()});
    return v;
}

bool TUGIAC::check()
{
    // check trung nhau
    for(int i=0; i<3; i++)
    {
        for(int j=i+1; j<4; j++)
         if(ds[i].getx()==ds[j].getx()&&ds[i].gety()==ds[j].gety()) return false;
    }

    //check thang hang
    vector<pair<double, double>> v=this->ds_vector();
    for(int i=0; i<2; i++)
    {
        for(int j=i+1; j<3; j++)
        {
            if(v[i].first*v[j].second==v[i].second*v[j].first) return false;
        }
    }
    for(int i=3; i<5;i++)
    {
        for(int j=i+1; j<6; j++)
        {
           if(v[i].first*v[j].second==v[i].second*v[j].first) return false;
        }
    }
    return true;
}

void TUGIAC::MENU()
{
    bar(20, 20, 500, 170);
       setbkcolor(WHITE);
       setcolor(BLACK);
       outtextxy(22, 22, (char*)"MENU");
       outtextxy(50, 50, (char*) "1. Hinh thang.");
       outtextxy(50, 75, (char*) "2. Hinh binh hanh.");
       outtextxy(50, 100, (char*) "3. Hinh chu nhat.");
       outtextxy(50, 125, (char*) "4. Hinh vuong.");
       outtextxy(50, 150, (char*) "0. Thoat");
}

void TUGIAC::Oxy()
{
    int x=getmaxx()/2;
        int y=getmaxy()/2+100;
        
        setbkcolor(WHITE);
        setcolor(WHITE);
        line(x, y+410, x,  y-410);
        line(x+510, y, x-510, y);
        
        for(int i=-19; i<20; i++) line(x-3, y-i*20, x+3, y-i*20);
        
        line(x-5, y-410+5, x, y-410);
        line(x+5, y-410+5, x, y-410);
        for(int i=-24; i< 25;i++)     line(x+i*20, y-3, x+i*20, y+3);
    
        line(x+510-5, y+5, x+510, y);
        line(x+510-5, y-5, x+510, y);
}

void TUGIAC::Choice()
{
    setbkcolor(WHITE);
        bar(500,20, 700, 170);
        setcolor(BLACK);
        outtextxy(502, 50, (char*) "YOUR CHOICE: ");
}

void TUGIAC::Choice_1(char* key)
{
    setcolor(BLACK);
    outtextxy(620 ,50, (char*) key);
}

void TUGIAC::d_line(int a, int b, int c, int d)
{
    setcolor(WHITE);
    line(a,b,c,d);
}

class Hinhthang:public TUGIAC
{
    public:
     Hinhthang();
     ~Hinhthang();
     void Nhap();
     void Xuat();
     int kiemtra();
};


Hinhthang::Hinhthang():TUGIAC(){}
Hinhthang::~Hinhthang(){}

void Hinhthang::Nhap()
{
    TUGIAC::Nhap();
    while(kiemtra()==0) { cout<<"Khong thoa dieu kien! Nhap lai!\n"; TUGIAC::Nhap();}
}

void Hinhthang::Xuat()
{
    TUGIAC::Xuat(kiemtra());
}

int Hinhthang::kiemtra()
{
    if(TUGIAC::check()==1)
    {
    vector<pair<double, double>> v=this->ds_vector();
        if(v[0].second== 0 && v[5].second==0) return 1;
        else if(v[1].second== 0 && v[4].second==0) return 2;
        else if(v[2].second== 0 && v[3].second==0) return 3;
    }
    return 0;
}
class Hinhbinhhanh:public TUGIAC
{
    public:
     Hinhbinhhanh();
     ~Hinhbinhhanh();
     void Nhap();
     void Xuat();
     int kiemtra();
};

Hinhbinhhanh::Hinhbinhhanh(): TUGIAC(){}
Hinhbinhhanh::~Hinhbinhhanh(){}

void Hinhbinhhanh::Nhap()
{
    TUGIAC::Nhap();
    while(kiemtra()==0) { cout<<"Khong thoa dieu kien! Nhap lai!\n"; TUGIAC::Nhap();}
}

void Hinhbinhhanh::Xuat()
{
    TUGIAC::Xuat(kiemtra());
}

int Hinhbinhhanh::kiemtra()
{
    if(TUGIAC::check()==1)
    {
     vector<pair<double, double>> v=this->ds_vector();
        if(v[0].second== 0 && v[5].second==0 && abs(v[0].first)==abs(v[5].first)) return 1;
        else if(v[1].second== 0 && v[4].second==0&& abs(v[1].first)==abs(v[4].first)) return 2;
        else if(v[2].second== 0 && v[3].second==0&& abs(v[2].first)==abs(v[3].first)) return 3;
    }
    return 0;   
}


class Hinhvuong:public TUGIAC
{
    public:
     Hinhvuong();
     ~Hinhvuong();
     void Nhap();
     void Xuat();
     int kiemtra();
};

Hinhvuong::Hinhvuong():TUGIAC(){}

Hinhvuong::~Hinhvuong(){}

void Hinhvuong::Nhap()
{
    TUGIAC::Nhap();
    while(kiemtra()==0) {cout<<"Khong thoa dieu kien de bai! Nhap lai!\n"; TUGIAC::Nhap();}
}

void Hinhvuong::Xuat()
{
    TUGIAC::Xuat(kiemtra());    
}

int Hinhvuong::kiemtra()
{
    if(TUGIAC::check()==1)
    {
    vector<pair<double, double>> v=this->ds_vector();
       if(v[0].first==0&&v[5].first==0)
       {
         if(v[0].second==v[5].second) {if(abs(v[1].first)==abs(v[0].second)&&v[1].second==0) return 2;}
         else if(v[0].second==-v[5].second) {if(abs(v[2].first)==abs(v[0].second)&&v[2].second==0) return 3;}
       }
       else if(v[1].first==0 && v[4].first==0)
       {
         if(v[1].second==v[4].second) {if(abs(v[0].first)==abs(v[1].second)&&v[0].second==0) return 1;}
         else if(v[1].second==-v[4].second) {if(abs(v[2].first)==abs(v[1].second)&&v[2].second==0) return 3;}
       }
       else if(v[2].first==0&& v[3].first==0)
       {
        if(v[2].second==v[3].second) {if(abs(v[0].first)==abs(v[2].second)&&v[0].second==0) return 1;}
         else if(v[2].second==-v[3].second) {if(abs(v[1].first)==abs(v[2].second)&&v[1].second==0) return 2;}
       }
    }
    return 0;      
}


class Hinhchunhat: public TUGIAC
{
    public:
     Hinhchunhat();
     ~Hinhchunhat();
     void Nhap();
     void Xuat();
     int kiemtra();
};

Hinhchunhat::Hinhchunhat():TUGIAC(){}

Hinhchunhat::~Hinhchunhat(){}

void Hinhchunhat::Nhap()
{
    TUGIAC::Nhap();
    while(kiemtra()==0)
    {
        cout<<"Khong thoa dieu kien de bai! Nhap lai!\n";
        TUGIAC::Nhap();
    }
}

void Hinhchunhat::Xuat()
{
    TUGIAC::Xuat(kiemtra());
}

int Hinhchunhat::kiemtra()
{
    if(TUGIAC::check()==1)
    {
    vector<pair<double, double>> v=this->ds_vector();
       if(v[0].first==0&&v[5].first==0)
       {
         if(v[0].second==v[5].second) {if(v[1].second==0) return 2;}
         else if(v[0].second==-v[5].second) {if(v[2].second==0) return 3;}
       }
       else if(v[1].first==0 && v[4].first==0)
       {
         if(v[1].second==v[4].second) {if(v[0].second==0) return 1;}
         else if(v[1].second==-v[4].second) {if(v[2].second==0) return 3;}
       }
       else if(v[2].first==0&& v[3].first==0)
       {
        if(v[2].second==v[3].second) {if(v[0].second==0) return 1;}
         else if(v[2].second==-v[3].second) {if(v[1].second==0) return 2;}
       }
    }
    return 0;
}

int main()
{

    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    
    //khởi tạo và chọn cửa sổ hiển thị.
    int window=initwindow(1200, 1000, (char*)"Bai5");
    setcurrentwindow(window);
 
    TUGIAC g;
    while(true)
    {
        g.MENU();
        g.Oxy();
        g.Choice();
        char key[1]; cout<<"Your choice: "; gets(key);
        if(key[0]<='9' && key[0] >='0') g.Choice_1(key);
            if(!strcmp(key,"0")) break;
            else if(!strcmp(key,"1"))
            {
                Hinhthang tg;
                tg.Nhap();
                tg.Xuat();
                system("pause");
            }
            else if(!strcmp(key,"2"))
            {
                Hinhbinhhanh tg;
                tg.Nhap();
                tg.Xuat();
                system("pause");
            }
            else if(!strcmp(key,"3"))
            {
                Hinhchunhat tg;
                tg.Nhap();
                tg.Xuat();
                system("pause");
            }
            else if(!strcmp(key,"4"))
            {
                Hinhvuong tg;
                tg.Nhap();
                tg.Xuat();
                system("pause");
            }
            else continue;
        setbkcolor(BLACK);
        cleardevice();
        cin.ignore();
    }
closegraph();
    return 0;   
}


