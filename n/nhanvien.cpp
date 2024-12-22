#include"nhanvien.h"
#include<bits/stdc++.h>


nhanvien::nhanvien(string hoten, int songay, string maso, string chucdanh, float hesoluong)
{
	this->hoten = hoten;
	this->songaylamviec = songay;
	this->maso = maso;
	this->chucdanh = chucdanh;
	this->hesoluong = hesoluong;
}
nhanvien::nhanvien(string hoten, int songay)
{
	this->hoten = hoten;
	this->songaylamviec = songay;
	this->maso = to_string(songay) + hoten;
	if ((songaylamviec >= 0) && (songaylamviec <= 365))
	{
		this->chucdanh = "Nhan vien";
		this->hesoluong = 1.0;
	}
	else if ((songaylamviec > 365) && (songaylamviec <= 730))
	{
		this->chucdanh = "Quan li";
		this->hesoluong = 1.5;
	}
	else if ((songaylamviec > 730) && (songaylamviec <= 1460))
	{
		this->chucdanh = "Truong phong";
		this->hesoluong = 2.25;
	}
	else if (songaylamviec > 1460)
	{
		this->chucdanh = "Truong ban quan li";
		this->hesoluong = 4.0;
	}
}
nhanvien::nhanvien(const nhanvien& other)
{
	this->chucdanh = other.chucdanh;
	this->hesoluong = other.hesoluong;
	this->songaylamviec = other.songaylamviec;
	this->hoten = "";
	this->maso = "";
}

nhanvien::nhanvien(){}
nhanvien::~nhanvien(){}
string nhanvien::layhoten()
{
	return hoten;
}
void nhanvien::ganhoten(string ten)
{
	hoten = ten;
}
int nhanvien::laysongay()
{
	return songaylamviec;
}
void nhanvien::gansongay(int songaylam)
{
	songaylamviec = songaylam;
}
void nhanvien::xuat()
{
	cout << "Ho ten: " << hoten << "\n";
	cout << "So ngay lam viec: " << songaylamviec << "\n";
	cout << "Ma so: " << maso << "\n";
	cout << "Chuc danh: " << chucdanh << "\n";
	cout << "He so luong: " << hesoluong << "\n" << "\n";
}
void nhanvien::nhap()
{
	string ten; int songaylam;
	cout << "Nhap ho ten: "; getline(cin, ten); 
	cout << "Nhap so ngay lam viec: "; cin >> songaylam; cout << "\n";
	nhanvien p=nhanvien(ten, songaylam);
	this->hoten=p.hoten;
	this->songaylamviec=p.songaylamviec;
    this->maso=p.maso;
	this->chucdanh=p.chucdanh;
	this->hesoluong=p.hesoluong;
}