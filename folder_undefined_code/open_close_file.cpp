#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main()
{
    int i;
 char s[100];
    ifstream in("C:\\Code C\\DU_AN_CONG_CHUA_G\\tost.txt");
    if(!in)
    {
        cout<<"Meo mo duoc";
        return 1;
    }
    in>>i;
    cin.ignore();
    in.getline(s, 100);
    in.close();
    cout<<i<<" " <<s;
return 0;
}