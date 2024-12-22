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