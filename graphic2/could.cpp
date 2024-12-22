#include <graphics.h>
main()
{
int gd=0, gm=0;
initgraph(&gd, &gm, (char*)"");
setbkcolor(GREEN);
setcolor(RED);
setfillstyle(CLOSE_DOT_FILL,YELLOW);
rectangle(5,5,300,160);
bar(5,175,300,340);
bar3d(320,100,500,340,100,1);
getch();
closegraph();
}