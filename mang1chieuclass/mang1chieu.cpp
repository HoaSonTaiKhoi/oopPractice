#include"mang1chieu.h"
#include<bits/stdc++.h>

mangmotchieu::mangmotchieu()
{
	srand(time(0));
	n=rand() % (1000-1+1)+1;
	arr=new int[n];

	for(int i=0; i<n; i++)
	{
	   arr[i]=rand()%1000;
	}
}

void mangmotchieu::Xuat()
{
	for(int i=0; i<n; i++)
	 cout<<arr[i]<<" ";
}

void mangmotchieu::dem_x()
{
	int x;
	cout<<"Nhap so can tim: ";
	cin>>x;

	int count=0;
	for(int i=0; i<n; i++)  if(arr[i]==x) count++;
	
	cout<<count;
}

void mangmotchieu::tang_dan()
{
	bool up=true;
	for(int i=0; i<n-1; i++){
		if(arr[i]>=arr[i+1]) {
			up=false;
			break;
		}
	}
    if(up==true) cout<<"Tang dan";
	else cout<<"Khong tang dan";
}

void mangmotchieu::so_le_nho_nhat()
{
	int min=arr[0];
	for(int i=1; i<n; i++)
	{
		while(min%2==0) min=arr[++i];
		if(arr[i]%2==1 && min>arr[i]) min=arr[i];
	}
	cout<<min;
}

bool mangmotchieu::ng_to(int x)
{
	if(x<2) return false;
	else if(x==2||x==3) return true;
	else if(x%2==0||x%3==0) return false;
	else 
	{
		int k=5;
		while(k*k<=x)
		{
			if(x%k==0 || x%(k+2)==0) return false;
			k+=6;
		}
	return true;
	}
}

void mangmotchieu::Nguyento_max()
{
	int maxprime=0; bool Prime=false;
	while(isPrime(arr[maxprime])==false&& maxprime<n) maxprime++;
    if(maxprime<n)
	{
		Prime=true;
	for(int i=maxprime+1; i<n ;i++)
	 if(isPrime(arr[i])&& arr[i]>arr[maxprime]) maxprime=i;
	}
	if(Prime==false) cout<<"Khong co";
	else cout<<arr[maxprime]<< ", index: "<< maxprime;
}
