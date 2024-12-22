#include<bits/stdc++.h>
using namespace std;
class Student
{
    private: 
     string name;
     int age;
    public:
     static int S;
     Student (string name, int age)
     {
        this->name=name;
        this->age=age;
     }
};
int Student::S=0;
main()
{
    Student s1("Manh", 19);
    Student s2("Kien", 20);
    cout<<s1.S<<" "<<s2.S;
return 0;
}