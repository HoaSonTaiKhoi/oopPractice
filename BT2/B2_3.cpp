#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;
class Candidate
{
    private:
     string MS, name, birth;
     double toan, van;
    public:
     Candidate(string MS, string name, string birth, double toan, double van)
     {
        this->MS=MS;
        this->name=name;
        this->birth=birth;
        this->toan=van;
        this->van=van;
     }
     void Xuatt()
     {
        cout<<MS<<" "<<name<<" "<<birth<<" "<<toan<<" "<<van;
     }
     bool checkdk()
     {
        if(toan+van>15) return true;
        return false;
     }
};
   
     
class TestCandidate
{
    public:
     static int n;
     static string MS, name, birth;
     static double toan, van;
    public:
     static void Nhap(vector<Candidate> &Candidates)
     {
        cin>>n;
        int i=0;
        while(i<n)
        {
            cin>>MS>>name>>birth>>toan>>van;
            Candidates.push_back(Candidate(MS, name, birth, toan, van));
        i++;
        }
     }
     static void Xuat(vector<Candidate> Candidates)
     {

        for(int i=0; i<Candidates.size(); i++) 
            if(Candidates[i].checkdk()==1)
            {Candidates[i].Xuatt(); cout<<endl;}
     }

};
int TestCandidate::n=0;
   string TestCandidate::MS="", TestCandidate::name="", TestCandidate::birth="";
   double TestCandidate::toan=0.0, TestCandidate::van=0.0;

int main()
{
    vector<Candidate> Candidates;
    TestCandidate::Nhap(Candidates);
    cout<<endl;
    TestCandidate::Xuat(Candidates);
return 0;
}