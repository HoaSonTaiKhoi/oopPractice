#include<bits/stdc++.h>
#include<dos.h>
#include<graphics.h>
#include<winbgim.h>
#include<string>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#define val 3.14159265/180.0
using namespace std;

char key[2];

void MENU()
{
    bar(20, 20, 500, 135);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(22, 22, (char*)"MENU");
    outtextxy(22, 50, (char*)"1. Khoi tao da giac.");
    outtextxy(22, 70, (char*)"2. Xuat cac diem da giac.");
    outtextxy(22, 90, (char*)"3. Tinh tien.");
    outtextxy(22, 110,(char*)"4. Quay.");
    bar(250, 38, 500, 135);
    outtextxy(252, 50,(char*)"5. Phong to");
    outtextxy(252, 70,(char*)"6. Thu nho");
    outtextxy(252, 90,(char*)"7. Thoat.");
}

void VEOXY()
{
    int x=getmaxx()/2;
    int y=getmaxy()/2+100;
    setbkcolor(WHITE);
    setcolor(WHITE);
    line(x, y+410, x,  y-410);
    line(x+510, y, x-510, y);
    for(int i=-19; i<20; i++)
    {
        line(x-3, y-i*20, x+3, y-i*20);
    }
    line(x-5, y-410+5, x, y-410);
    line(x+5, y-410+5, x, y-410);
    for(int i=-24; i< 25;i++)
    {
        line(x+i*20, y-3, x+i*20, y+3);
    }
    line(x+510-5, y+5, x+510, y);
    line(x+510-5, y-5, x+510, y);
}

void Choose()
{
    setbkcolor(WHITE);
    bar(700, 20, 1000, 135);
    setcolor(BLACK);
    outtextxy(702, 22, (char*)"Your choice: ");
}
void Choose_1(char key[])
{
    bar(800, 20, 1000, 135);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(802,22,  (char*)key);
}
int p(int x){  return x*x; }

class DIEM
{
    private:
     //Tọa độ thực của điểm
     double x;
     double y;
     //Tọa độ pixel để in ra màn hình
     int a;
     int b;
    public:
     DIEM()
     {
        bar(750, 70, 1000, 135);
        setcolor(BLACK);
        cin>>x>>y;
        //In giá trị đã nhập ra màn hình
        char s[20];
        sprintf(s, "Input: %0.1f  %0.1f", x, y);
        outtextxy(752, 72, (char*)s);
        
        // Đổi tọa độ điểm thành tọa độ pixel
         a=(int)getmaxx()/2+x*20;
         b=(int)getmaxy()/2+100-y*20;
         delay(500);
     }

     //Phương thức vẽ điểm
     void DrawPoint()
     {
        setbkcolor(WHITE);
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        fillellipse(a, b, 4, 4);
        setfillstyle(0, WHITE);
     }
    
    //Phương thức vẽ đường
     void DLine(DIEM p)
     {
        line(this->a, this->b, p.a, p.b);
     }

     double getx()
     {
        return x;
     }
     double gety()
     {
        return y;
     }
    
    //Kiemtra thang hàng
    static bool checkthanghang(vector<DIEM> Trian, int n, int diems)
     {
        int x1, y1, x2, y2;
        if(n==diems-1)
        {
        x1=Trian[n].x-Trian[0].x;
        y1=Trian[n].y-Trian[0].y;
        x2=Trian[n].x-Trian[1].x;
        y2=Trian[n].y-Trian[1].y;
        if(x1*y2==y1*x2) return true;
        return false;
        }
        else
        {
        x1=Trian[n].x-Trian[n-1].x;
        y1=Trian[n].y-Trian[n-1].y;
        x2=Trian[n].x-Trian[n-2].x;
        y2=Trian[n].y-Trian[n-2].y;
        if(x1*y2==y1*x2) return true;
        return false;
        }
     }

//Tịnh tiến điểm
    void tt(double v1, double v2)
    {
        this->x+=v1;
        this->y+=v2;
        this->a=this->a+(int)v1*20;
        this->b=this->b-(int)v2*20;
    }
//Thay đổi tọa độ điểm sau quay
    void quay(double angle, int xo,int yo)
     {
        int t1=this->x, t2=this->y;
        this->x=(int) (t1-xo)*cos(val*angle)-(t2-yo)*sin(angle*val)+xo;
        this->y=(int) (t1-xo)*sin(val*angle)+(t2-yo)*cos(angle*val)+yo;
        this->a=(int)this->x*20+getmaxx()/2;
        this->b=(int)getmaxy()/2+100-this->y*20;
     }
//Thay đổi tọa độ điểm sau phóng to/ thu nhỏ
    void zoomm(double k, int n)
    {
        this->x=this->x*k;
        this->y=this->y*k;
        this->a=(int)this->x*20+getmaxx()/2;
        this->b=(int)getmaxy()/2+100-this->y*20;
    }
    
};




class POLY
{
    private:
     vector<DIEM> Poly;
     int n=0, temp=0;
    public:
     void CreatePoly()
     {
        //Đọc và xuất số điểm cần nhập
        bar(700, 50, 1000, 135);
        outtextxy(710, 52,(char*)"Nhap so diem: ");
        int diems;
        cin>>diems;
        bar(700, 50, 1000, 135);
        char s[20]; sprintf(s, "So diem can nhap: %d", diems);
        outtextxy(710, 52,(char*)s);

        for(int i=0; i<diems; i++)
        {
            temp=n;
            DIEM d1=DIEM();
            Poly.push_back(d1);
            char c[20]; sprintf(c, "So diem can nhap: %d", diems-i-1);
            outtextxy(710, 52, (char*)c);
            n++;
            // Vẽ  điểm và vẽ đường từ 2 điểm trở lên
            Draw();
            if(n>=2) DrawLine();
            if(n==diems) Poly[n-1].DLine(Poly[0]);
            delay(500);
            //check thẳng hàng
            if(n>=3)
            {
               while(DIEM::checkthanghang(Poly, n-1, diems)==true)
               {
                   DEL();
                   temp=n;
                   d1=DIEM();
                   Poly.push_back(d1);
                   n++;
                   outtextxy(710, 52, (char*)c);
                   Draw();
                   DrawLine();
                   if(n==diems) Poly[n-1].DLine(Poly[0]);
                   delay(500);
               }
            }
        }
     }

     void DEL()
     {
        setbkcolor(BLACK);
            cleardevice();  //Xóa màn hình
            MENU();
            VEOXY();
            Choose();
            Choose_1(key);
          setcolor(WHITE);
          n--;
          Poly.resize(n);
        //In lại các điểm còn lại trong mảng
        for(int i=0; i< n; i++)
         Poly[i].DrawPoint();
        temp=0;
        DrawLine();
         outtextxy(810, 92, (char*)"Thang hang! Nhap lai!");
        delay(1000);
     }

     void Draw()
    {
        setcolor(WHITE);
        setfillstyle(0, WHITE);
        for(int i=temp; i<n;i++)
          Poly[i].DrawPoint();
    }
    void DrawLine()
    {
        setcolor(WHITE);
        setfillstyle(0, WHITE);
        for(int i=temp;i<n; i++)
        Poly[i-1].DLine(Poly[i]);
    }

    void OutPoint()
      {
         bar(700, 50, 1000, 135);
        for(int i=0; i< n; i++)
        {
            cout<<"("<<Poly[i].getx()<<" , "<<Poly[i].gety()<<")\n";
        }
        system("pause");
      }

    void TinhTien()
    {
        double v1, v2;
        bar(700, 50, 1000, 135);
        outtextxy(710,52, (char*)"Nhap vector");
        cin>>v1>>v2;
        
        for(int i=0; i<n ; i++)
         {
            Poly[i].tt(v1, v2);
         }
        
        char s[10];
        sprintf(s, "Vector da nhap: <%0.1f, %0.1f>", v1, v2);
        bar(700, 50, 1000, 135);
        outtextxy(710, 52, (char*)s);

     setbkcolor(BLACK);
     cleardevice();
       MENU();
       VEOXY();
       Choose();
       bar(800, 20, 1000, 135);
      outtextxy(802, 22, (char*)"3");
       bar(700, 50, 1000, 135);
      outtextxy(710, 52, (char*)s);
      
      //Vẽ lại các điểm và line
      temp=0;
      Draw();
      temp=1;
      DrawLine();
      Poly[n-1].DLine(Poly[0]);
      system("pause");
    }

    void Quay()
    {
        double xo, yo,angle;

        OutPoint();
        bar(800, 50, 1000, 135);
        // Nhập điểm làm tâm xoay và đánh dấu tâm đó 
        outtextxy(802, 52, (char*)"Nhap diem lam goc(bat ki): ");
        cin>>xo>>yo;
        //Hiện kết quả nhập 
        char chose[20]; sprintf(chose, "(%0.1f , %0.1f)", xo, yo);
         bar(800, 50, 1000, 135);
         outtextxy(802, 52, (char*)chose);
         outtextxy(802, 72, (char*)"Nhap goc: "); cin>>angle;
         char c[10]; sprintf(c, "Nhap goc: %0.2f", angle);
         outtextxy(802, 72, (char*)c);
        
        //Xóa màn hình
        setbkcolor(BLACK);
        cleardevice();
        
        //In lại
             MENU();
             VEOXY();
             Choose();
             Choose_1(key);
        setfillstyle(0, WHITE);
             bar(700, 50, 1000, 135);
        setcolor(BLACK);
            char s[40]; sprintf(s, "Tam xoay: (%0.1f, %0.1f) & Goc da nhap: %0.2f ", xo, yo, angle);
            outtextxy(710, 52, (char*)s);

        //Thay đổi tọa độ xoay khi xoay, lấy tâm xoay đã đánh dấu trước đó bằng temp
        for(int i=0; i< n; i++)
        {
            Poly[i].quay(angle, xo, yo);
        }
        temp=0;
        Draw();
        temp=1;
        DrawLine();
        Poly[n-1].DLine(Poly[0]);
        system("pause");
    }

    void ZOOM()
    {
        bar(800, 50, 1000, 135);
        // Nhập tỉ lệ phóng to/thu nhỏ
        outtextxy(802, 52, (char*)"Nhap ti le: ");
        double k,l; cin>>k; l=k;

        //Nếu người dùng chọn 6 tức là thu nhỏ thì tỉ lệ phóng to sẽ là 1/k.
        if(strcmp(key,"6")==0) k=1.0/k;
        
        //Xóa màn hình
        setbkcolor(BLACK);
        cleardevice();

        //In lại
             MENU();
             VEOXY();
             Choose();
             Choose_1(key);
        setfillstyle(0, WHITE);
             bar(700, 50, 1000, 135);
        setcolor(BLACK);
        char c[10]; sprintf(c, "Ti le: %0.1f", l);
        outtextxy(802, 52, (char*)c);
        
        // Thay đổi tọa độ các điểm dựa trên các điểm và k.
        for(int i=0; i< n; i++)
        {
            Poly[i].zoomm(k, n);
        }
        temp=0;
        Draw();
        temp=1;
        DrawLine();
        Poly[n-1].DLine(Poly[0]);
        system("pause");
    }

};

int main()
{
    POLY T;
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    
    //khởi tạo và chọn cửa sổ hiển thị.
    int window=initwindow(1200, 1000, (char*)"Bai3_3");
    setcurrentwindow(window);
    while(true)
    {
        MENU();
        VEOXY();
        Choose();
        gets(key);
        Choose_1(key);
        

        if(strcmp(key, "1")==0)
        {
            T.CreatePoly();
        }
        else if(strcmp(key,"2")==0)
        {
            T.OutPoint();
        }
        else if(strcmp(key,"3")==0)
        {
            T.TinhTien();
        }
        else if(strcmp(key,"4")==0)
        {
            T.Quay();
        }
        else if(strcmp(key,"5")==0||strcmp(key,"6")==0)
        {
            T.ZOOM();
        }
        else if(strcmp(key, "7")==0) {delay(500); break;}
    }
closegraph();
return 0;
}