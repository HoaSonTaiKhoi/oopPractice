#include<graphics.h>
#include<bits/stdc++.h>
#include<windows.h>
#include<string>
#include<conio.h>
#include<stdio.h>
using namespace std;

void Menu()
{
    bar(30, 30, 300, 200);
    setbkcolor(WHITE);
    setcolor(BLACK);
    
    outtextxy(33, 33, (char*)"MENU");
    outtextxy(33, 50, (char*)"1. Nhap mot diem.");
    outtextxy(33, 67, (char*)"2. Nhap nhieu diem.");
    outtextxy(33, 84, (char*)"3. Xoa diem vua nhap.");
    outtextxy(33, 101, (char*)"4. Tinh Tien.");
    outtextxy(33, 118, (char*)"5. Thoat");
}
void Choose1()
{
   
    bar(340, 30, 800, 65);
    setbkcolor(WHITE);
    setcolor(BLACK);
    outtextxy(342, 38,(char*)"Your choice: ");
}
void Choose2(char key[])
{
    bar(450, 30, 800, 65);
    gets(key);
    outtextxy(452, 38, (char*) key);
}

void VeOxy()
{
    int x=getmaxx()/2;
    int y=getmaxy()*1/2+110;
    setlinestyle(0,0,1);
    setcolor(WHITE);
    line(x, y+380, x, y-380);
    line(x+530, y, x-530, y);
    for(int i=-12; i<13; i++)
    {
        setlinestyle(0,0,1);
        line(x-3,y+i*30, x+3, y+i*30);
    }
    line(x, y-380, x+5, y-380+5);
    line(x, y-380, x-5, y-380+5);
    for(int i=-17; i<18; i++)
    {
        setlinestyle(0,0, 1);
    line(x+i*30, y-3, x+i*30, y+3);
    }
    line(x+530, y, x+530-5, y+5);
    line(x+530, y, x+530-5, y-5);
}

class DIEM
{
    private:
     int x, y;
    public:
    //Constructor Nhap diem
      DIEM()
      {
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        bar(450, 75, 600, 120);
        //Đọc tọa độ điểm
         cin>>x>>y;
         //In tọa độ ra màn hình
          char s[10];
          sprintf(s, "%d  %d", x, y);
          setcolor(BLACK);
          outtextxy(452, 77, (char*)s);

         //trả về tọa độ trên màn hình(pixel)
         x=getmaxx()/2+x*30;
         y=getmaxy()*1/2+110-y*30;
       }

     // Phương thức vẽ điểm - vẽ bằng elip có 2 bán kính bằng nhau - tô màu bằng setfillstyle
     void DrPoint()
     {
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        fillellipse(x, y, 4, 4);
        setfillstyle(0, WHITE);
     }
     // trả về tọa độ điểm trên màn hình sau khi nhập vector
     void TT(int &a, int&b)
     {
        setfillstyle(0, WHITE);
        setcolor(WHITE);
        bar(450, 75, 600, 120);
         cin>>a>>b;
        this->x+=a*30;
        this->y-=b*30;
     }
};

// Lớp quản lí nhiều điểm
class DIEMS
{
    private:
     vector<DIEM> diems;
     int n=0;
     int count;
     int temp=0;
    public:
    //Nhap 1 điểm
     void Nhap1()
     {
        temp=n;
        DIEM d1=DIEM();
        diems.push_back(d1);
        n++;
        Draw();
        return;
     }

     //Nhập n điểm
     void Nhapn()
     {
        temp=n;
        bar(450, 75, 600, 120);
        outtextxy(500, 38, (char*)"So diem can nhap: ");
        cin>>count;
        char s[20];
        sprintf(s,"So diem can nhap: %d", count);
        outtextxy(500, 38, (char*)s );   // Trả về số n đã nhập
      
      // Vòng lặp nhập điểm và in tọa độ điểm ra màn hình
      for(int i=0; i< count; i++)
        {
            DIEM d1=DIEM();
            diems.push_back(d1);
            char c[20];
            // In ra số điểm còn lại cần nhập
        sprintf(c,"So diem can nhap: %d", count-1-i); 
        outtextxy(500, 38, (char*)c );
            n++;
            Draw();
            delay(1000);
        }
        count=-1;
        return;
     }

     void Draw()
     {
        for(int i=temp; i< n; i++)
         diems[i].DrPoint(); //vẽ điểm
     return;
     } 



 //Xoa diem vua ve    
     void DEL()
     {
        setbkcolor(BLACK);
            cleardevice();  //Xóa màn hình
            Menu();
            VeOxy();
            bar(340, 30, 600, 65);
            bar(450, 75, 600, 120);
        setcolor(WHITE);
        n--;
        if(n<0) return; //Nếu n<0 thì thoát phương thức
        diems.resize(n);

        //In lại các điểm còn lại trong mảng
        for(int i=0; i< n; i++)
         diems[i].DrPoint();
        temp=n;
        Choose1();
        outtextxy(452, 38, (char*)"3");
        delay(1000);
     }


     void TinhTien()
     {
           int a, b;
        setcolor(WHITE);
        n--;        
        diems[n].TT(a, b);
        // setbkcolor()  cài đặt màu nền sau khi xóa màu nền sẽ theo cái này
        setbkcolor(BLACK);
            cleardevice();
            Menu();
            VeOxy();
            bar(450, 75, 600, 120);

        if(n<0) return;
        for(int i=0; i< n; i++)
        diems[i].DrPoint();
        char s[20];
         sprintf(s, "Vector:  %d %d", a, b);
         setcolor(BLACK);
         //In lại cái điểm sau khi xóa;
         outtextxy(452, 77, (char*)s);
         Choose1();
         outtextxy(452, 38, (char*)"4");
        temp=n;
        n++;
        Draw(); //vẽ lại điểm mới
        delay(200);
     }
     
};


int main()
{
    DIEMS A;
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    int w1=initwindow(1200, 1000, (char*)"Bai3_1");
    setcurrentwindow(w1);
    while (true)
    {
        Menu();
        VeOxy();
        char key[1];
        Choose1(); Choose2(key);
        if(strcmp(key, "1")==0)
        {
            A.Nhap1();
        }
        else if(strcmp(key, "2")==0)
        {
            A.Nhapn();
        }
        else if(strcmp(key, "3")==0)
        {
            A.DEL();
        }
        else if(strcmp(key, "4")==0)
        {
            A.TinhTien();
        }
        else if(strcmp(key, "5")==0) {delay(500);break;}
    }
closegraph();
return 0;
}