#pragma once
#include<string>
using namespace std;
class nhanvien
{
private:
	string hoten, maso, chucdanh;
	int songaylamviec;
	float hesoluong;
public:
	nhanvien(string hoten, int songaylamviec,string maso, string chucdanh, float hesoluong);
	nhanvien(string hoten, int songay);
	nhanvien(const nhanvien& other);
	nhanvien();
	~nhanvien();
	string layhoten();
	void ganhoten(string ten);
	int laysongay();
	void gansongay(int songay);
	void xuat();
	void nhap();
};