#include<bits/stdc++.h>
std::vector<int>a;
int n;
int i;
int temp;
int min, max;
int s=0;
int main()
{
   std::cin>>n;
   for(i=0; i<n; i++)
   {
     std::cin>>temp;
     a.push_back(temp);
   }
   min=0; max=1;
   for(i=0; i<n; i+=2)
   {
      if(a[i]<=a[min]) min=i;
   }
   for(i=1; i<n; i+=2)
   {
     if(a[i]>=a[max]) max=i;
   }
   if(a[max]>a[min])
   std::swap(a[max], a[min]);
   for(int i=0; i<n; i++)
   {
    s+=pow(-1, i)*a[i];
   }
   std::cout<<s;
return 0;
}