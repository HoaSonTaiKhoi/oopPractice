#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> a;
std::vector<int> b;
int n;
int temp, i;
int sum=0;
int sum1=0, sum2=0;

int checksum1(std::vector<int> a, std::vector<int> b)
{
    i=a.size()-1; 
    while (i>=0)
    {
        if(a[i]<b[b.size()-1]) {temp=i; break;}
        i--;
    }
    i=0;
    while(i<=temp&& a[temp-i]<b[b.size()-1-i])
    {
        std::swap(b[b.size()-i-1], a[temp-i]);
        i++;
    }
    for(i =0; i<a.size(); i++)
      sum1+=a[i];
    for(i =0; i<b.size(); i++)
      sum1-=b[i];
    return sum1;
}

int checksum2(std::vector<int> a, std::vector<int> b)
{
   i=0;
   while(i<a.size()&& a[i]<b[b.size()-1-i])
   {
     std::swap(a[i], b[b.size()-1-i]);
     i++;
   }
   for(i =0; i<a.size(); i++)
      sum2+=a[i];
    for(i =0; i<b.size(); i++)
      sum2-=b[i];
    return sum2;
}
int main()
{
    std::cin>>n;
    for(i=0; i< n; i++)
    {
        if(i%2==0)
        {
        std::cin>>temp;
        a.push_back(temp);
        }
        else if(i%2==1)
        {
            std::cin>>temp;
            b.push_back(temp);
        }    
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sum1=checksum1(a,b);
    sum2=checksum2(a,b);
    sum=sum1>sum2?sum1:sum2;
    std::cout<<sum;
return 0;
}