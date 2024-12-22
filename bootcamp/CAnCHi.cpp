#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n; cin>>n;
    int x=n%10;
    string can="";
    string chi="";
   if(n>=0)
   {
    switch(x)
     {
        case 0:
          can="CANH";
          break;
        case 1:
          can="TAN";
          break;
        case 2:
          can="NHAM";
          break;
        case 3:
          can="QUY";
          break;
        case 4 :
          can="GIAP";
          break;
        case 5:
          can="AT";
          break;
        case 6:
          can="BINH";
          break;
        case 7:
          can="DINH";
          break;
        case 8:
          
          can="MAU";
          break;
        case 9:
          can="KY";
          break;
      }  
    x=n%12;
    switch (x)
    {
        case 0: chi="THAN"; break;
        case 1: chi="DAU"; break;
        case 2: chi="TUAT"; break;
        case 3: chi="HOI"; break;
        case 4: chi="TY'"; break;
        case 5: chi="SUU"; break;
        case 6: chi="DAN"; break;
        case 7: chi="MEO"; break;
        case 8: chi="THIN"; break;
        case 9: chi="TY."; break;
        case 10: chi="NGO"; break;
        case 11: chi="MUI"; break;
    }   
   }
   else
   {
    n=-n;
    x=n%10;
    switch(x)
     {
        case 1:
          can="CANH";
          break;
        case 2:
          can="KY";
          break;
        case 3:
          can="MAU";
          break;
        case 4:
          can="DINH";
          break;
        case 5 :
          can="BINH";
          break;
        case 6:
          can="AT";
          break;
        case 7:
          can="GIAP";
          break;
        case 8:
          can="QUY";
          break;
        case 9:
          can="NHAM";
          break;
        case 0:
          can="TAN";
          break;
      }  
    x=n%12;
    switch (x)
    {
        case 1: chi="THAN"; break;
        case 2: chi="MUI"; break;
        case 3: chi="NGO"; break;
        case 4: chi="TY."; break;
        case 5: chi="THIN"; break;
        case 6: chi="MEO"; break;
        case 7: chi="DAN"; break;
        case 8: chi="SUU"; break;
        case 9: chi="TY'"; break;
        case 10: chi="HOi"; break;
        case 11: chi="TUAT"; break;
        case 0: chi="DAU"; break;
    }   
   }
    string s=can+" "+chi;
    cout<<s;
return 0;
}
