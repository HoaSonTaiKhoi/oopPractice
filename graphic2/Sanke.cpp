#include<bits/stdc++.h>
#include<ctime>
#include<string>
#include<windows.h>
#include<winbgim.h>
#include "graphics.h"
#include<cmath>
#define val 3.14159265/180.0
using std::cin;
using std::cout;

class Loop
{
    private:
       int xo=getmaxx()/2, yo=getmaxy()/2;
       int hour, min, sec;
    public:
      void Nhap()
      {
         this->sec=0;
         cout<<"Nhap gio: "; cin>>this->hour;
         cout<<"Nhap phut: "; cin>>this->min;
      }
      Loop()
      {
         Nhap();
      while(true)
       {
        circle(xo,yo,450);
        drawsec();
        drawmin();
        drawhour();
        sec+=1;
        delay(1000);
        chuanhoa();
        cleardevice();
       }
      }
      
      void draw()
      {
          for(int i=0; i<=6; i++)
          {
            int x1=(int) (0)*cos(val*30*i)-(-420)*sin(val*30*i)+xo;
            int y1=(int) (0)*sin(val*30*i)+(-420)*cos(val*30*i)+yo;
          }
      }

      void drawsec()
      {
         int x=(int) (0)*cos(val*6*sec)-(-400)*sin(val*6*sec)+xo;
         int y=(int) (0)*sin(val*6*sec)+(-400)*cos(val*6*sec)+yo;
         line(xo,yo, x, y);
      }
      
      void drawmin()
      {
         int x=(int) (0)*cos(val*6*min)-(-350)*sin(val*6*min)+xo;
         int y=(int) (0)*sin(val*6*min)+(-350)*cos(val*6*min)+yo;
         line(xo,yo, x, y);
      }

      void drawhour()
      {
         int x=(int) (0)*cos(val*30*hour)-(-200)*sin(val*30*hour)+xo;
         int y=(int) (0)*sin(val*30*hour)+(-200)*cos(val*30*hour)+yo;
         line(xo,yo, x,y);
      }
      
      int get_total_sec()
      {
         return hour*3600+min*60+sec;
      }
      void chuanhoa()
      {
         hour=(get_total_sec()/3600)%12;
         min=(get_total_sec()/60)%60;
         sec=(get_total_sec())%60;
      }
    
};


int main()
{
    int gd=DETECT, gm=0;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    int window=initwindow(1200, 1000, (char*)"Clock");
    setcurrentwindow(window);


    Loop L;
    getch();
closegraph();
return 0;
}
