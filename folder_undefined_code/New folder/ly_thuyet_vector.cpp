#include<bits/stdc++.h>
#include<vector>
using namespace std;


// clear() xóa hết vector
// erase(iterator) xóa phần tử chọn trước   erase(vitridau, vitricuoi);
//pop_back() xóa phần từ bên phải
//reverse(vitridau, vi tri cuoi);
int main()
{
   int n; cin>>n;
   vector<int> a;

    for(int i=0; i< n; i++)
     {
        int x; cin>>x;
        a.push_back(x);
     }
    
     for(vector<int>::iterator x=a.begin(); x!=a.end(); x++)
      cout<<*x<<" ";
   cout<<endl;
     for(auto x=a.begin(); x!=a.end(); x++)
      cout<<*x<<" ";
   cout<<endl;
     for(int x: a)
     cout<<x<<" ";
return 0;
}