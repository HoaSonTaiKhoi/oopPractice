#include<bits/stdc++.h>

class SinhVien
{
    private:
     std::string s;
     double toan;
     double van;
    public:
     SinhVien()
     {
        getline(std::cin, s);
        std::cin>>toan>>van;
     }
     void display()
     {
        std::cout<<s<<" "<<toan<<" "<<van<<" "<<(toan+van)/2.0;
     }

};

int main()
{
    SinhVien sv1;
    sv1.display();
}