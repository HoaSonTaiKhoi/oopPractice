#include<iostream>
#include<cmath>
using namespace std;
int ktranto(int i){
	if(i==2) return i;
else{
   int s=0;	
    for (int j=2; j<=sqrt(i); j++) if (i%j==0) s+=1;
if (s>=1) return 0;
else return i;
}
}
int sum_common_prime(int m, int n){
    int s=0;
    for (int i=2; i<=n; i++){
    	if(ktranto(i)==i){
		if(m%ktranto(i)==0 && n%ktranto(i)==0){
            s+=i;
        }
    }
}
if(s==0) return -1;
else return s;
}
	

int main() 
{
	int m, n;
	cin >> m >> n;
	cout << sum_common_prime(m, n);
	
return 0;
}