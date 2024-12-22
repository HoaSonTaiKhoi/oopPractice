#include<iostream>
using namespace std;

int main(){
	int n,m;
	cout<<"Nhap so menh gia ban có và so tien can thanh toan: ";
	cin>>n>>m;
	int a[n];
	
	int b[n];
	for(int i=1; i<=n; i++){
		cout<<"Menh gia "<<i<<": ";
		cin>>a[i];
		b[i]=0;
	}
	
	
	for(int i=1; i<n; i++){
		for (int j=i+1; j<=n;j++){
			if(a[i]>a[j]){
				int c=a[i];
				a[i]=a[j];
				a[j]=c;
			}
		}
			
	}
	int tcl=m;
	int i=n;
	while (i>=1){
	 while (tcl>=a[i]){
	 	tcl-=a[i];
	 	b[i]+=1;
	 }
	 i--;
	 
	}
	cout<<"ket qua:"<<endl;
	cout<<"So tien khong the thanh toan: "<<tcl<<endl;
	
	for (int i=1; i<=n; i++){
		cout<<"Mênh gia "<<i<<"k: "<<b[i]<<endl;
	}
}
