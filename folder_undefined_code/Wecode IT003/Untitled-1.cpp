#include<iostream>
#include<vector>
#include<algorithm>
using std::cin;
using std::cout;
using std::swap;
using std::vector;
struct Point
{
    int x, y, z;
};
int n;
int i, j, min;
int d,e,f;
vector<Point>a;
void Sapxep(vector<Point> &a)
{
     
}

int main()
{
   cin>>n;
   for(i=0; i<n; i++)
    {
        cin>>d>>e>>f;
        a.push_back({d, e, f});
    }
    Sapxep(a);
    for(i=0; i<n; i++)
    {
        cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<"\n";
        cout<<"\n";
    }
return 0;
}