#include<iostream>
#include"mang1chieu.h"
using namespace std;
main()
{
	mangmotchieu A=mangmotchieu();
	cout<<"Da khoi tao mang 1 chieu.\n";
	while(true)
	{
		cout<<"_____________________________________________________\n"
		    <<"1. Xuat mang.\n"
			<<"2. Dem so lan xuat hien cua gia tri x trong mang.\n"
			<<"3. Kiem tra day so nguyen co tang dan hay khong.\n"
			<<"4. Tim phan tu le nho nhat trong day so nguyen.\n"
			<<"5. Tim so nguyen to lon nhat.\n"
			<<"6. Khoi tao mang so nguyen ngau nhien moi.\n"
			<<"0. END.\n"
			<<"_____________________________________________________\n"
			<<"Nhap lua chon: ";
		int key; cin>>key;
		 if(key==1)     A.Xuat();
		else if(key==2) A.dem_x();
		else if(key==3) A.tang_dan();
		else if(key==4) A.so_le_nho_nhat();
		else if(key==5) A.Nguyento_max();
		else if(key==6)	
		{
	      A=mangmotchieu();
		  cout<<"Da tao mang moi.";
		}
		else if(key==0) break;
	cout<<"\n";
	}
return 0;
}