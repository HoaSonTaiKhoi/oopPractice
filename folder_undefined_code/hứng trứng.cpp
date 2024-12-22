#include <iostream>

#include <stdio.h>

#include <conio.h>

#include <Windows.h>

#include <stdlib.h>

#include <time.h>



#define consoleWidth     85

#define roadWidth        33

#define consoleHeight    30



using namespace std;

void gotoXY (int column, int line)

{

	COORD coord;

	coord.X = column;

	coord.Y = line;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

} 



void TextColor (int color)

{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);

}



struct toado 

{

	int x,y;

};



struct gio

{

	toado td;

	int diem;

	int truot;

};



struct doan 

{

	toado td;

};



void khoitao (gio & gio, doan &da) {

	//---gio

	gio.td.x = 70;

	gio.td.y = consoleHeight - 1;

	

	

	da.td.x = rand() % consoleWidth;

	da.td.y = 0;

	

	gio.diem = 0;

	gio.truot = 0;

}



void hienthi (gio &gio, doan &da) {

	system("cls");

	

	TextColor(7);

	for (int i = 0; i < consoleHeight; i++) {

		gotoXY(roadWidth, i);

		putchar(179);

	}

	TextColor(3);	

 	gotoXY(gio.td.x, gio.td.y);

 	printf("%c%c%c%c%c%c%c", 254, 254, 254, 254, 254, 254, 254);

 	TextColor(7);

	for (int i = 0; i < consoleHeight; i++) {

		gotoXY(consoleWidth, i);

		putchar(179);

	}

	TextColor(6);

	gotoXY(da.td.x, da.td.y);

	printf("o");

	

	if (da.td.x <= roadWidth)

	da.td.x = rand() % consoleWidth;

	

	TextColor(7);

	gotoXY(consoleWidth + 4, 14);

	printf("diem = %d", gio.diem);

	gotoXY(consoleWidth + 4, 10);

	printf("bi truot = %d", gio.truot);

	gotoXY(roadWidth - 20, 14);

	printf("Luu Y: bi truot"); 

	gotoXY(roadWidth - 20, 15);

	printf("3 lan se thua");

}





void dieukhien (gio &gio) {

	if (kbhit()) {

		int key = _getch();

		

		if (key == 'a' && gio.td.x >= roadWidth + 3)

		gio.td.x-= 2;

		if (key == 'd' && gio.td.x <= consoleWidth - 9)

		gio.td.x+= 2;

	}

}



int xuly (gio &gio, doan &da) {

	da.td.y++;

	

	if (da.td.y >= consoleHeight) {

		da.td.x = rand() % consoleWidth - 1;

		da.td.y = 0;

		gio.truot++;

	}

	

	if (gio.td.x == da.td.x && gio.td.y == da.td.y || gio.td.x + 1== da.td.x && gio.td.y == da.td.y || gio.td.x + 2 == da.td.x && gio.td.y == da.td.y || 

	gio.td.x  + 3 == da.td.x && gio.td.y == da.td.y || gio.td.x + 4 == da.td.x && gio.td.y == da.td.y || gio.td.x + 5 == da.td.x && gio.td.y == da.td.y ||

	gio.td.x + 6 == da.td.x && gio.td.y == da.td.y || gio.td.x + 7 == da.td.x && gio.td.y == da.td.y) {

		gio.diem+=5;

		da.td.x = rand() % consoleWidth - 1;

		da.td.y = 0;

	}

	if (gio.truot == 3) 

	return -1;

}



int main() {

	int i;

	int o;

	srand(time(NULL));

	gio gio;

	doan da;

	khoitao (gio, da);

	

	int ma = 0;

	printf("1.huong dan\n");

	printf("2.choi game\n");

	printf("3.tac gia\n");

	printf("4.thoat\n");

	printf("toi chon:");

	cin >> o;

	if (o == 1) {

		

		system("cls");

			printf("***********\n");

			printf("*HUONG DAN*\n");

			printf("***********\n");

			printf("Bam a de sang trai\n");

			printf("Bam d de sang phai\n");

			printf("phai hung trung cang nhanh cang tot\n");

			printf("bi rot 3 trung se thua\n");

			printf("2.choi game\n");

			printf("3.tac gia\n");

			printf("4.thoat\n");

			printf("toi chon:");

			cin >> o;

			

		}	

	if (o == 3) {

		system("cls");

		printf("tac gia: Nguyen Van Minh Huy\n");

		printf(":)))))))))))))))))))))\n");

		printf("1.huong dan\n");

		printf("2.choi game\n");

		printf("4.thoat\n");

		printf("toi chon:");

		cin >> o;

	}

	if (o == 1) {

		

		system("cls");

			printf("***********\n");

			printf("*HUONG DAN*\n");

			printf("***********\n");

			printf("Bam a de sang trai\n");

			printf("Bam d de sang phai\n");

			printf("phai hung trung cang nhanh cang tot\n");

			printf("bi rot 3 trung se thua\n");

			printf("2.choi game\n");

			printf("3.tac gia\n");

			printf("4.thoat\n");

			printf("toi chon:");

			cin >> o;

		}

	if (o == 4) {

		printf("3s nua se thoat    bye~   bye~   bye~");

		Sleep(3000);

	}

	if (o == 2) {

	while (1) {

		// hien thi

		hienthi (gio, da);

		// dieu khien

		dieukhien (gio);

		// xuly 

		ma = xuly(gio, da);

		// game thua

		if (ma == -1) {

			system("cls");

			gotoXY(30, 13);

			printf("ban da thua:))))))");

			gotoXY(30, 14);

			printf("diem cua ban la %d", gio.diem);

			gotoXY (30, 15);

			printf("ban co muon choi nua ko\n");

			gotoXY (30, 18);

			printf("1.Co        2.Khong\n");

			gotoXY (30, 19);

			printf("toi chon:");

			cin >> i;

			if (i == 1) {

				system("cls");

				main ();

			}

			break;

			}

		Sleep (0);

		}

		

	return 0;

	}

}