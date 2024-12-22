#include<iostream>
#include<windows.h>
using namespace std;
int nn(int n){
	int a=n*2+1;
	return a;
}
main(){
	int n,a,b,c, s;
	cin>>n;
	a=n;
	s=0;
	c=0;
	system("cls");
	PO:
		b=n;

	while(b>a){
	
			cout<<b;
			b-=1;
		}
		
			for(int j=1;j<nn(a); j++){
				cout<<a;
			}
	while(b<=n){

			cout<<b;
			b+=1;
		}
		a--;
		

		s+=1;
while(a>=0){

	
			cout<<endl;
			goto PO;
	}
	a=1;
	cout<<endl;
    BACK:
    	b=n;
	    while (b>a){
		
	    	cout<<b;
	    	b--;
		} 
		for(int j=1;j<nn(a); j++){
				cout<<a;
			}
		while(b<=n){
			cout<<b;
			b++;
		}	
		a++;
	while(a<=n){
		cout<<endl;
		goto BACK;
	}	
 return 0;
}