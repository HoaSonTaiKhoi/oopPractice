#pragma once
#include<string>

using namespace std;

class HocSinh
{
private:
	string Hoten, Ma, SDT;
	float DTB;
public:
	void nhap();
	void xuat();
	bool kiemtraTen();
	bool kiemtraMa();
	bool kiemtraSDT();
	bool kiemtraDTB(string s);
};
