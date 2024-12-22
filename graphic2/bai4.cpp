
#include<bits/stdc++.h>
#include<graphics.h>
#include<winbgim.h>
#include<time.h>
#include<string>


using namespace std;

class DIEM
{
    private:
     //Tọa độ thực của điểm
     double x,y;
     //Tọa độ pixel để in ra màn hình
     int a,b;
    public:
     DIEM(){}
     ~DIEM(){}
     
     virtual void Nhap()
     {
        setbkcolor(WHITE);
        setcolor(BLACK);
        cout<<"Nhap toa do(x y): ";cin>>x>>y;
        //In giá trị đã nhập ra màn hình
        char s[20];
        sprintf(s, "Input: %0.1f  %0.1f", x, y);
        outtextxy(520, 75, (char*)s);
        
        // Đổi tọa độ điểm thành tọa độ pixel
         a=(int)getmaxx()/2+x*20;
         b=(int)getmaxy()/2+100-y*20;
     }

     //Phương thức vẽ điểm
     virtual void Xuat()
     {
        setbkcolor(WHITE);
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        fillellipse(a, b, 4, 4);
        setfillstyle(0, WHITE);
     }

     double get_x(){return x;}
     double get_y(){return y;}
     int get_a(){return a;}
     int get_b(){return b;}
};


class Elip:public DIEM
{
    private:
     double r1, r2;
     int R1, R2;
    public:
     Elip();
     ~Elip();
     void Nhap();
     void Xuat();
};

class Circle:public DIEM
{
    private:
     double r;
     int R;
    public:
    Circle();
    ~Circle();
     void Nhap();
     void Xuat();
};


Elip::Elip():DIEM(){}

Elip::~Elip(){}

void Elip::Nhap()
{
   DIEM::Nhap();
   cout<<"Nhap 2 ban kinh(r1 r2): "; cin>>this->r1>>this->r2;
   char s[20]; sprintf(s, "R1= %0.1.f  R2= %0.1f", this->r1, this->r2);
   outtextxy(520, 100, (char*)s);

   this->R1=(int)this->r1*20;
   this->R2=(int)this->r2*20;
}

void Elip::Xuat()
{
    DIEM::Xuat();
    setcolor(WHITE);
    ellipse(get_a(), get_b(), 0, 360, this->R1, this->R2);
}

Circle::Circle():DIEM(){}

Circle::~Circle(){}

void Circle::Nhap()
{
    DIEM::Nhap();
    cout<<"Nhap ban kinh r: "; cin>>this->r;
    char s[20]; sprintf(s, "R1= %0.1f ", this->r);
   outtextxy(520, 100, (char*)s);
   this->R=(int) this->r*20;
}

void Circle::Xuat()
{
     DIEM::Xuat();
    setcolor(WHITE);
    arc(get_a(), get_b(), 0, 360, this->R);
}


class Window
{
    private:
     Circle Cr;
     Elip Ep;
    public:
     void MENU(){
       bar(20, 20, 500, 135);
       setbkcolor(WHITE);
       setcolor(BLACK);
       outtextxy(22, 22, (char*)"MENU");
       outtextxy(50, 50, (char*) "1. Nhap va' ve Ellipse");
       outtextxy(50, 75, (char*) "2. Nhap va' ve Circle");
       outtextxy(50, 100, (char*) "0.Thoat");
      }

      void Oxy()
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

      void Choice()
      {
        setbkcolor(WHITE);
        bar(500,20, 700, 135);
        setcolor(BLACK);
        outtextxy(502, 50, (char*) "YOUR CHOICE: ");
      }

      void Choice_1(char *key)
      {
        setcolor(BLACK);
        outtextxy(620,50, (char*) key);
      }
      void Hienthi()
      {
         while(true)
         {
            MENU();
            Oxy();
            Choice();
            char key[2]; cout<<"Your choice: "; gets(key);
            Choice_1(key);
            if(!strcmp(key,"0")) break;
            else if(!strcmp(key,"1"))
            {
                Ep.Nhap();
                Ep.Xuat();
                system("pause");
            }
            else if(!strcmp(key,"2"))
            {
                Cr.Nhap();
                Cr.Xuat();
                system("pause");
            }
            setbkcolor(BLACK);
            cleardevice();
         }
         return;
      }
};


int main()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    
    //khởi tạo và chọn cửa sổ hiển thị.
    int window=initwindow(1200, 1000, (char*)"Bai4");
    setcurrentwindow(window);

    Window wd;
    wd.Hienthi();
closegraph();
return 0;
}

