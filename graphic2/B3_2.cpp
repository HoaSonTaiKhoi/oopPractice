#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<bits/stdc++.h>
#include<winbgim.h>
#include<math.h>
#define val 3.14159265/180.0
using namespace std;

char key[2];

//Danh sách lựa chọn
void MENU()
{
    bar(20, 20, 500, 135);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(22, 22, (char*)"MENU");
    outtextxy(22, 50, (char*)"1. Khoi tao tam giac.");
    outtextxy(22, 70, (char*)"2. Xuat cac diem tam giac.");
    outtextxy(22, 90,(char*)"3. Tinh tien.");
    outtextxy(22, 110,(char*)"4. Quay.");
    bar(250, 38, 500, 135);
    outtextxy(252, 50,(char*)"5. Phong to");
    outtextxy(252, 70,(char*)"6. Thu nho");
    outtextxy(252, 90,(char*)"7. Thoat.");
}

//Trục tọa độ
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

// Vẽ bảng hiện thị kết quả lựa chọn
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
int p(int x){  return x*x; } //trả về bình phương 1 số

// Class quản lí tọa độ điểm
class DIEM
{
    private:
     int x, y;
    public:
    //Nhập tọa độ điểm
     DIEM()
     {
        bar(750, 70, 1000, 135);
        setcolor(BLACK);
        cin>>x>>y;
        char s[20];
        sprintf(s, "Input: %d  %d", x, y);
        outtextxy(752, 72, (char*)s);
        
         x=getmaxx()/2+x*20;
         y=getmaxy()/2+100-y*20;
         delay(500);
     }
    // Vẽ chấm điểm 
     void DrawPoint()
     {
        setbkcolor(WHITE);
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        fillellipse(x, y, 4, 4);
        setfillstyle(0, WHITE);
     }

     //Vẽ đường
     void  DrawLine(DIEM p)
     {
        line(this->x, this->y,p.x,p.y);
     }

    // Trả về tọa độ thực sự của điểm (chứ không phải pixel)
     void Point(int &a, int &b)
     {
        a=(x-getmaxx()/2)/20;
        b=(getmaxy()/2+100-y)/20;
     }
     void getxy(int &t, int &u)
     {
        t=this->x;
        u=this->y;
        Point(t, u);
     }

     // thay đổi tọa độ điểm theo vector<c,d>
     void TT(int &c,  int &d , vector<DIEM> &Trian)
     { 
        cin>>c>>d;
        for(int i=0; i<3; i++)
        {
            Trian[i].x+=c*20;
            Trian[i].y-=d*20;
        }
     }

     //Thay đổi tọa độ điểm theo góc và tâm quay
     void quay(double angle, int xo,int yo)
     {
        int t1=this->x, t2=this->y;
        this->x=(int) (t1-xo)*cos(val*angle)-(t2-yo)*sin(angle*val)+xo;
        this->y=(int) (t1-xo)*sin(val*angle)+(t2-yo)*cos(angle*val)+yo;
     }
     static void Rotate(vector<DIEM>&Trian, DIEM p,  double angle, int temp)
     {
        int t=p.x, u=p.y;
        for(int i=0; i<3; i++)
        {
            if(i!=temp)  Trian[i].quay(angle, t ,u);
        }
     }

     //Phương thức tĩnh kiểm tra thẳng hàng
     static bool checkthanghang(vector<DIEM> Trian)
     {
        int x1, y1, x2, y2;
        x1=Trian[0].x-Trian[1].x;
        y1=Trian[0].y-Trian[1].y;
        x2=Trian[0].x-Trian[2].x;
        y2=Trian[0].y-Trian[2].y;
        if(x1*y2==y1*x2) return false;
        return true;
     }

    //Phương thức tĩnh tìm tâm đường tròn ngoại tiếp tam giác ABC
     static void Center(vector<DIEM> d, int &i1, int &i2)
      {  
       int vp=(p(d[0].x)+p(d[0].y)-p(d[1].x)-p(d[1].y))*(d[0].y-d[2].y)-(p(d[0].x)+p(d[0].y)-p(d[2].x)-p(d[2].y))*(d[0].y-d[1].y);
       int vt=2*(d[0].x-d[1].x)*(d[0].y-d[2].y)-2*(d[0].x-d[2].x)*(d[0].y-d[1].y);
         i1=(int) vp/vt;
       vp=(p(d[0].x)+p(d[0].y)-p(d[1].x)-p(d[1].y))*(d[0].x-d[2].x)-(p(d[0].x)+p(d[0].y)-p(d[2].x)-p(d[2].y))*(d[0].x-d[1].x);
       vt=2*(d[0].y-d[1].y)*(d[0].x-d[2].x)-2*(d[0].y-d[2].y)*(d[0].x-d[1].x);
       i2=(int)vp/vt;
      }

    // thay đổi tọa độ điểm sau phóng to / thủ nhỏ, dựa trên tỉ lệ k và tâm I(i1,i2)
      static void zoom(vector<DIEM> &d, double k, int i1, int i2)
      {
           for(int i=0; i< 3; i++)
           {
              d[i].x=(int)(d[i].x-i1)*k+i1;
              d[i].y=(int)(d[i].y-i2)*k+i2;
           }
      }

};

class Triangle
{
   private:
    vector<DIEM> Trian;
    int n=0, temp=0;
    int a[7];
   public:
    void CreateTriangle()
    {
        
        bar(700, 50, 1000, 135);
        outtextxy(710, 52,(char*) "So diem can nhap: 3" );
        for(int i=0;i<3; i++)
        {
            temp=n;
            DIEM d1=DIEM();
            Trian.push_back(d1);
            char s[20];
            sprintf(s, "So diem can nhap: %d", 3-i-1);
            outtextxy(710, 52, (char*)s);
            n++;
            Draw();
            delay(500);
        
            if(i==1) Trian[0].DrawLine(Trian[1]);
            else if(i==2)
            {
                Trian[0].DrawLine(Trian[2]);
                Trian[1].DrawLine(Trian[2]);
            }
        }
        if(DIEM::checkthanghang(Trian)==false)
        {
            setcolor(BLACK);
             outtextxy(710, 90,(char*)"Khong phai la tam giac! Nhap lai!");
             delay(500);
            setbkcolor(BLACK);
            cleardevice();
             MENU();
             VEOXY();
             Choose();
             Choose_1(key);
             Trian.clear();
             n=0;
             system("pause");
            return CreateTriangle();
        }
    }

    void OutPoint()
    {
        vector<char> str={'A', 'B', 'C'};
         bar(700, 50, 1000, 135);
        for(int i=0; i< 3; i++)
        {
            char s[10];
            int a,b;
                Trian[i].Point(a,b);
                sprintf(s,"%c(%d, %d)",str[i], a,b);
                outtextxy(710, 52+i*20, (char*)s);
        }
        system("pause");
    }

    void TinhTien()
    {
        int c,d;
        bar(700, 50, 1000, 135);
        outtextxy(710,52, (char*)"Nhap vector");
        
        Trian[0].TT(c,d, Trian);
        char s[10];
        sprintf(s, "Vector da nhap: <%d, %d>", c,d);
        bar(700, 50, 1000, 135);
        outtextxy(710, 52, (char*)s);

    setbkcolor(BLACK);
    cleardevice();
      MENU();
      VEOXY();
      Choose();
      temp=0;
      bar(800, 20, 1000, 135);
      outtextxy(802, 22, (char*)"3");
      bar(700, 50, 1000, 135);
      outtextxy(710, 52, (char*)s);

//Vẽ lại các điểm và line
      Draw();
      Trian[0].DrawLine(Trian[1]);
      Trian[0].DrawLine(Trian[2]);
      Trian[1].DrawLine(Trian[2]);
      system("pause");
    }

    //Phương thức vẽ các điểm
    void Draw()
    {
        setcolor(WHITE);
        setfillstyle(0, WHITE);
        for(int i=temp; i<n;i++)
          Trian[i].DrawPoint();
    }

    //Phương thức tịnh tiến
    void Quay()
    {
        int t, u;
        double angle;
        OutPoint();
        bar(800, 50, 1000, 135);
        vector<char> str={'A', 'B', 'C'};
        // Nhập điểm làm tâm xoay và đánh dấu tâm đó 
        outtextxy(802, 52, (char*)"Nhap diem lam goc: ");
        char chose[10]; gets(chose);
          
          if     (strcmp(chose, "A")==0) {Trian[0].getxy(t,u); temp=0;}
          else if(strcmp(chose, "B")==0) {Trian[1].getxy(t,u); temp=1;}
          else if(strcmp(chose, "C")==0) {Trian[2].getxy(t,u); temp=2;}

        //Hiện kết quả nhập 
         bar(800, 50, 1000, 135);
         outtextxy(850, 52, (char*)chose);
         sprintf(chose, "(%d,%d)", t, u);
         outtextxy(860, 52, (char*)chose);
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
            char s[40]; sprintf(s, "Tam xoay: %c(%d, %d) & Goc da nhap: %0.2f ", str[temp], t, u, angle);
            outtextxy(710, 52, (char*)s);

        //Thay đổi tọa độ xoay khi xoay, lấy tâm xoay đã đánh dấu trước đó bằng temp
        DIEM::Rotate(Trian, Trian[temp], angle, temp);
        temp=0;
        Draw();
        Trian[0].DrawLine(Trian[1]);
        Trian[0].DrawLine(Trian[2]);
        Trian[1].DrawLine(Trian[2]);
        system("pause");
    }
    

    // Phóng to thu nhỏ
    void ZOOM()
    {
        int i1, i2;
        DIEM::Center(Trian, i1, i2); // Tìm tâm đường tròn ngoại tiếp tam giác
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
        char c[20]; sprintf(c, "Tam: I(%d,%d) & Ti le: %0.1f", (i1-getmaxx()/2)/20, (getmaxy()/2+100-i2)/20, l);
        outtextxy(802, 52, (char*)c);
        
        // Thay đổi tọa độ các điểm dựa trên tâm , các điểm và k.
        DIEM::zoom(Trian, k, i1, i2);
        temp=0;
        Draw();
        Trian[0].DrawLine(Trian[1]);
        Trian[0].DrawLine(Trian[2]);
        Trian[1].DrawLine(Trian[2]);
        system("pause");
    }
};


int main()
{
    Triangle T;
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    
    //khởi tạo và chọn cửa sổ hiển thị.
    int window=initwindow(1200, 1000, (char*)"Bai3_2");
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
            T.CreateTriangle();
        }
        else if(strcmp(key, "2")==0)
        {
            T.OutPoint();
        }
        else if(strcmp(key, "3")==0)
        {
            T.TinhTien();
        }
        else if(strcmp(key, "4")==0)
        {
            T.Quay();
        }
        else if(strcmp(key,"5")==0)
        {
            T.ZOOM();
        }
        else if(strcmp(key, "6")==0)
        {
            T.ZOOM();
        }
        else if(strcmp(key, "7")==0) {delay(500); break;}
    }
closegraph();
return 0;
}