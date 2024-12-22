#include<iostream>
#include"Quadrangle.h"
using namespace std;
void Input(vector<Quadrangle*> &List){
    int CatchKey;
    do{
        cout<<"\tPress 1 to input Trapeze.\n";
        cout<<"\tPress 2 to input Parellelogram.\n";
        cout<<"\tPress 3 to input RectAngle.\n";
        cout<<"\tPress 4 to input Square.\n";
        cout<<"\tPress 5 to back to the main menu.\n";
        while (cin>>CatchKey&&CatchKey!=1&&CatchKey!=2&&CatchKey!=3&&CatchKey!=4&&CatchKey!=5)
        {
            cout<<"Just Press in range 1,2,3,4,5. Again: ";
        }
        switch (CatchKey)
        {
        case 1:
            List.push_back(new Trapeze);
            List.back()->Set();
            break;
        case 2:
            List.push_back(new Parallelogram);
            List.back()->Set();
            break;
        case 3:
            List.push_back(new RecAngle);
            List.back()->Set();
            break;
        case 4:
            List.push_back(new Square);
            List.back()->Set();
            break;
        default:
            break;
        }
    }while(CatchKey!=5);
}
void Print(vector<Quadrangle*> &List){
    cout<<"-----Print List Quadrangle----\n";
    for(int i=0;i<List.size();i++){
        List[i]->Print();
        cout<<endl;
    }
    cout<<"--------------------------\n";
}
int main(){
    vector<Quadrangle*> ListQuadrangle;
    ListQuadrangle.resize(0);
    int CatchKey;
    do{
        cout<<"Manage Quadrangle: \n";
        cout<<"\tPress 1 to input one kind Quadrangle.\n";
        cout<<"\tPress 2 to print all list of Quadrangles.\n";
        cout<<"\tPress 3 to exit.\n";
        while (cin>>CatchKey&&CatchKey!=1&&CatchKey!=2&&CatchKey!=3)
        {
            cout<<"Just Press in range 1,2,3. Again: ";
        }
        switch (CatchKey)
        {
        case 1:
            Input(ListQuadrangle);
            break;
        case 2:
            Print(ListQuadrangle);
            break;
        default:
            break;
        }
    }while(CatchKey!=3);
    for(int i=0;i<ListQuadrangle.size();i++){
        delete ListQuadrangle[i];
    }
    cout<<"Thanks!";
    return 0;
}