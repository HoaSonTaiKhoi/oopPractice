    #include<bits/stdc++.h>
  
    #include<math.h>
using namespace std;

int tongchuso(long long x)
{
    
    int sum =0;
    while(x>0) 
    {
        sum+=x%10;
        x/=10;
    }
    return sum;
}

int reverse(int x)
{
    int s=0;
    while(x>0)
    {
        s=s*10+x%10;
        x/=10;
    }
    return s;
}
 bool isPrime(int x)
 {
    if(x<2) return false;
    else if(x==2||x==3) return true;
    else if(x%2==0||x%3==0) return false;
    else
    {
        int k=5;
        while(k*k<x) if(x%k==0 ||x%(k+2)==0) return false;
    }
    return true;
 }
 long long ucln(long long a, long long b)
 {
     if (a == 0 || b == 0){
        return a + b;
    }
    while (a != b){
        if (a > b){
            a -= b; // a = a - b
        }else{
            b -= a;
        }
    }
    return a;
 }

 int main()
 {
    long long a, b;
    cin>>a>>b;
    if(isPrime(reverse(tongchuso(ucln(a,b))))==true) cout<<"CO";
    else cout<<"KHONG";
return 0;
 }