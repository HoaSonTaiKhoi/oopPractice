#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>

class Candidate
{
   private:
    std::string mssv, ten, birth;
    double toan, van, anh;
   public:
    Candidate();
    void Xuat();
    bool check();
};

class TestCandidate
{
   private:
    std::vector<Candidate> Candidates;
    int n;
    int count=0;
   public:
    void Nhap();
    void Check();
};

//Nhập thông tin một Sinh Viên mới
Candidate::Candidate()
    {
      getline(std::cin, mssv, ' ');
      std::string temp;
      
      while (true)
      {
         getline(std::cin, temp, ' ');
         if(temp[0]>='0'&&temp[0]<='9'||temp[1]>='0'&&temp[1]<='9') break;
         ten+=temp;
         ten+=" ";
      }
      
      ten.resize(ten.size()-1);  
      
      birth=temp;
      
      std::cin>>toan>>van>>anh;
      std::cin.ignore();
      }
   

//Xuat 1 Candidate
void Candidate::Xuat()
    {
      std::cout<<mssv<<" "<<ten<<" "<<birth<<" "<<toan<<" "<<van<<" "<<anh;
    }
// check tổng điểm có lớn hơn 15 hay không
bool Candidate::check()
    {
      if(toan+van+anh>15) return true;
      return false;
    }

// Nhap n Sinh vien
void TestCandidate::Nhap()
{ 
   std::cout<<"Nhap tong so sinh vien: ";
   std::cin>>n; 
   std::cin.ignore();
   for(int i=0; i< n; i++)
   {
    Candidate p1=Candidate();
    Candidates.push_back(p1);
   }
}

//Kiểm tra và xuất ra những sinh viên nào có tổng điểm >15.
void TestCandidate::Check()
{
   for(int i=0; i<n; i++)
   {
      if(Candidates[i].check()==true)
      {
          Candidates[i].Xuat();
          std::cout<<"\n";
          count++;
      } 
   }
   if(count ==0) std::cout<<"Khong co sinh vien thoa dieu kien!\n";
   return;
}

int main()
{
   TestCandidate Test;
   Test.Nhap();
   std::cout<<"\nKet qua: \n";
   Test.Check();

return 0;
}