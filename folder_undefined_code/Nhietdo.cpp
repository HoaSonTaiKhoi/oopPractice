#include<iostream>
#include<windows.h>
using namespace std;
int main(){
	double F,C,K;
	cin>> F;
	 C=(F-32)/1.8;
	 K=C+273.15;
	system("cls");
	cout<<(F-32)/1.8<<"\t"<<(F-32)/1.8+273.15;
}