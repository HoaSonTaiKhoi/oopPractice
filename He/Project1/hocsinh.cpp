#include"HocSinh.h"
#include<iostream>
#include<cctype>
#include<conio.h>
using namespace std;

void HocSinh::nhap()
{

	cout << "Nhap ho ten: ";
	do
	{
		getline(cin, Hoten);
		if (kiemtraTen())
			break;
		else cout << "Nhap lai ho ten: ";
	} while (1);

	cout << "Nhap ma: ";
	do
	{
		getline(cin, Ma);
		if (kiemtraMa())
			break;
		else cout << "Nhap lai ma: ";
	} while (1);

	cout << "Nhap so dien thoai: ";
	do
	{
		getline(cin, SDT);
		if (kiemtraSDT())
			break;
		else cout << "Nhap lai so dien thoai: ";
	} while (1);

	cout << "Nhap Diem trung binh: ";
	do
	{
		string s;
		getline(cin, s);
		if (kiemtraDTB(s) == 1)
		{
			DTB = atof(s.c_str());
			break;
		}
		else 
		{
			cout << "Nhap lai diem trung binh: ";
		}
	} while (1);
}

bool HocSinh::kiemtraTen()
{
	int i = 0;
	while (Hoten[i] != '\0')
	{
		if (isalpha(Hoten[i]) == 0 && Hoten[i] != ' ')
		{
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool HocSinh::kiemtraMa()
{
	int i = 0;
	if (Ma.size() != 8)
		return false;
		while (Ma[i] != '\0')
		{
			if (!isdigit(Ma[i]))
			{
				return false;
					break;
			}
			i++;
		}
	return true;
}

bool HocSinh::kiemtraSDT()
{
	int i = 0;
	if ((SDT.size() < 9) || (SDT.size() > 11))
		return false;
	while (SDT[i] != '\0')
	{
		if (!isdigit(SDT[i]))
		{
			return false;
			break;
		}
		i++;
	}
	return true;
}

bool HocSinh::kiemtraDTB(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) == 0 && s[i] != '.') return false;
	}
	return true;
}

void HocSinh::xuat()
{
	cout << "Ho ten: " << Hoten << "\n";
	cout << "Ma: " << Ma << "\n";
	cout << "So dien thoai: " << SDT << "\n";
	cout << "Diem trung binh: " << (float)DTB << "\n";
}