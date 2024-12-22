#include<iostream>
using namespace std;


void Hieu_Goal_Card(int a[][3], int &point, int &Hieu,  int &Goal, int &Card)
{
    for(int i=0; i<3; i++)
    {
        if(a[i][0]==a[i][1]) point +=1;
        else if(a[i][0]>a[i][1]) point +=3;
     Hieu+=a[i][0]-a[i][1];
     Goal+=a[i][0];
     Card+=a[i][2];
    }
}

void In(int &point, int &Hieu,  int &Goal, int &Card)
{
   cout<<point<<" "<<Hieu<<" "<<Goal<<" "<<Card;
}
main()
{
    int a[3][3];
    int b[3][3];
      for(int i=0; i<3; i++)
       {
        for(int j=0; j<3; j++)
         cin>>a[i][j];
       }
      for(int i=0; i<3; i++)
       {
        for(int j=0; j<3; j++)
         cin>>b[i][j];
       }
    int a1=0, a2=0, a3=0, a4=0;
    int b1=0, b2=0, b3=0, b4=0;
    Hieu_Goal_Card(a, a1, a2, a3, a4);
    Hieu_Goal_Card(b, b1, b2, b3, b4);

    int checkwin =0;
    if(a1>b1) checkwin=1;
    else if(a1<b1) checkwin=2;
    else 
    {
        if(a2>b2) checkwin =1;
        else if(a2<b2) checkwin=2;
        else 
        {
            if(a3>b3) checkwin=1;
            else if(a3<b3) checkwin=2;
            else 
            {
                if(a4>b4) checkwin=2;
                else if(a4<b4) checkwin=1;
            }
        }
    }
    if(checkwin==1) In(a1, a2, a3, a4);
    else In(b1, b2,b3, b4);
return 0;
}