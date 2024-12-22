#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<math.h>

std::vector<int>a;
std::vector<int>b;
int l, check=0;
int m, n;
int x,y;
int i,j;
int temp1, temp2;
int len(int x)
{ 
    l=0;
    while(x>0)
    {
        l+=1;
        x/=10; 
    }
    return l;
}
int hamming(std::vector<int>a,  std::vector<int> b)
{
   for(i=0; i<b.size(); i++)
   {
      if(a[i]!=b[i]) count++;
   }
   return cout;
}
int main()
{
    std::cin>>x>>y;
    m=len(x);
    n=len(y);
    for(i=n-1; i>=0; i--)
   {
   temp1=x/pow(10,i);
   temp2=y/pow(10,i);
   temp1%=10;
   temp2%=10;
   a.push_back(temp1);
   b.push_back(temp2);
   }
   for(i=0; i<n; i++)
    std::cout<<a[i]<<" ";
   std::cout<<"\n";
   for(i=0; i<n; i++)
    std::cout<<b[i]<<" ";
   
return 0;
}
