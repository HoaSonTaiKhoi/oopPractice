#include<bits/stdc++.h>
#include<cstring>
using namespace std;
class Tui
{
    private:
      char name[100];
      int age;
    public: 
     Tui(char name[100], int age)
     {
        for(int i=0; i<=strlen(name); i++)
         this->name[i]=name[i];
        this->age=age;
     }
     void outt()
     {
        cout<<"My name is "<<name<<endl;
        cout<<"My age is "<<age;
     }
};
int main()
{
    Tui s1("Hoang do dpe trai", 18);
    s1.outt();
return 0;
}