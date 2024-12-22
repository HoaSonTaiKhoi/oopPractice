#include<graphics.h>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int main()
{
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, (char*)"C:\\TC\\BGI");
    setcolor(WHITE);
    outtextxy(200, 200, (char*)"Hao game that day");
    int k=1;
    char s[10]="Hoang";
    outtextxy(100, 100, (char*)s);
 getch();
 closegraph();
return 0;
}