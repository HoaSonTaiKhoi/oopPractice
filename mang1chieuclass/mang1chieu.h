#pragma once
#include<stdlib.h>
#include<windows.h>
#include<time.h>

using namespace std;
class mangmotchieu	
{
private:
	int *arr=new int;
	int n;
public:
	mangmotchieu();
    void Xuat();
	void dem_x();
	void tang_dan();
	void so_le_nho_nhat();
	bool ng_to(int x);
	void Nguyento_max();
};