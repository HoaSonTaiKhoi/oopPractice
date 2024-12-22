#include<iostream>
#include"Quadrangle.h"
#include<cmath>
using namespace std;
//Quadrangle definition
Quadrangle::Quadrangle(){
    Coordinate c[4];
    for(int i=0;i<4;i++){
        c[i].x=c[i].y=0;
    }
    SetCoor(c);
}
Quadrangle::Quadrangle(Coordinate *coor){
    SetCoor(coor);
}
Quadrangle::~Quadrangle(){
}
void Quadrangle::SetCoor(Coordinate coor[4]){
    for(int i=0;i<4;i++){
        Coor[i].x=coor[i].x;
        Coor[i].y=coor[i].y;
    }
}
void Quadrangle::Set(){
    Coordinate c[4];
    do{
    for(int i=0;i<4;i++){
        cout<<"Coordinate "<<i+1<<" (x,y): " ;
        cin>>c[i].x>>c[i].y;
    }
    SetCoor(c);
    }while(this->Check()==0);
}
void Quadrangle::Print(){
    Coordinate *c=GetCoor();
    for(int i=0;i<4;i++){
        cout<<"( "<<c[i].x<<" , "<<c[i].y<<")";
        if(i!=3){
            cout<<"--";
        }
    }
}

//Trapeze definition
//Constructor and Destructor
Trapeze::Trapeze(){
    SetLongEdge(0);
    SetHeigth(0);
    SetShortEdge(0);
}
Trapeze::Trapeze(double l,double s,double h){
    SetLongEdge(l);
    SetHeigth(h);
    SetShortEdge(s);
}
Trapeze::~Trapeze(){
}
//Setter
void Trapeze::Set(){
    cout<<"Input Trapeze: "<<endl;
    Quadrangle::Set();
}
void Trapeze::SetLongEdge(double w){
    LongEdge=w;
}
void Trapeze::SetShortEdge(double l){
    ShortEdge=l;
}
void Trapeze::SetHeigth(double h){
    Heigth=h;
}

//other method
double MultiCoor(Coordinate c1,Coordinate c2){
    return c1.x*c2.x+c1.y*c2.y;
}
double Module(Coordinate c1,Coordinate c2){
    return sqrt(pow(c1.x-c2.x,2)+pow(c1.y-c2.y,2));
}

Coordinate VectorCoor(Coordinate c1,Coordinate c2){
    Coordinate c;
    c.x=c1.x-c2.x;
    c.y=c1.y-c2.y;
    return c;
}
bool Trapeze::Check(){
    Coordinate YAxis={0,1};
    Coordinate *c=GetCoor();
    vector<double> value;
    double h;
    value.resize(0);
    
    for(int i=0;i<3;i++){
        for(int j=i+1 ;j<4;j++){
            if(MultiCoor(VectorCoor(c[i],c[j]),YAxis)==0){
                value.push_back(Module(c[i],c[j]));
                for(int k=0;k<4;k++){
                    if(k!=i&&k!=j){
                        h=abs(c[k].y-c[i].y);
                    }
                }
            }
        }
    }
    if(value.size()!=2){
        cout<<"Wrong input!\n";
        return false;
    }
    else{
        SetLongEdge(value[0]>value[1]?value[0]:value[1]);
        SetShortEdge(value[0]<value[1]?value[0]:value[1]);
        SetHeigth(h);
        return true;
    }
}
void Trapeze::Print(){
    cout<<"Trapeze: \n";
    Quadrangle::Print();
    cout<<"\n\t-Long edge: "<<GetLongEdge()<<endl;
    cout<<"\n\t-Short edge: "<<GetShortEdge()<<endl;
    cout<<"\n\t-Heigth: "<<GetHeigth()<<endl;
}
//Parallelogram definition
//Constructor and Destructor
Parallelogram::Parallelogram(){
    SetLongEdge(0);
    SetShortEdge(0);
    SetHeigth(0);
}
Parallelogram::Parallelogram(double l,double s,double h){
    SetLongEdge(l);
    SetShortEdge(s);
    SetHeigth(h);
}
Parallelogram::~Parallelogram(){
}
//Setter
void Parallelogram::Set(){
    cout<<"Input Parallelogram:\n";
    Quadrangle::Set();
}
void Parallelogram::SetLongEdge(double w){
    LongEdge=w;
}
void Parallelogram::SetShortEdge(double l){
    ShortEdge=l;
}
void Parallelogram::SetHeigth(double h){
    Heigth=h;
}
//other method
bool Parallelogram::Check(){
    Coordinate YAxis={0,1};
    Coordinate *c=GetCoor();
    vector<double> value;
    double h;
    double s;
    value.resize(0);
    
    for(int i=0;i<3;i++){
        for(int j=i+1 ;j<4;j++){
            if(MultiCoor(VectorCoor(c[i],c[j]),YAxis)==0){
                value.push_back(Module(c[i],c[j]));
                for(int k=0;k<4;k++){
                    if(k!=i&&k!=j){
                        h=abs(c[k].y-c[i].y);
                        double d1=Module(c[k],c[i]);
                        double d2=Module(c[k],c[j]);
                        s=(d1<d2?d1:d2);
                    }
                }
            }

        }
    }
    if(value.size()==2&&value[0]==value[1]){
        SetLongEdge(value[0]>s?value[0]:s);
        SetShortEdge(value[0]<s?value[0]:s);
        SetHeigth(h);
        return true;
    }
    else{
        cout<<"Wrong input!\n";
        return false;
    }
}
void Parallelogram::Print(){
    cout<<"Parallelogram: \n";
    Quadrangle::Print();
    cout<<"\n\t-Long edge: "<<GetLongEdge()<<endl;
    cout<<"\n\t-Short edge: "<<GetShortEdge()<<endl;
    cout<<"\n\t-Heigth: "<<GetHeigth()<<endl;
}
//Recangle definition
//Constructor and Destructor
RecAngle::RecAngle(){
    SetWidth(0);
    SetLength(0);
}
RecAngle::RecAngle(double w,double l){
    SetWidth(w);
    SetLength(l);
}
RecAngle::~RecAngle(){
}
//Setter
void RecAngle::Set(){
    cout<<"Input recangle: ";
    Quadrangle::Set();
}
void RecAngle::SetWidth(double w){
    Width=w;
}
void RecAngle::SetLength(double l){
    Length=l;
}
//other method
bool RecAngle::Check(){
    Coordinate YAxis={0,1};
    Coordinate XAxis={1,0};
    Coordinate *c=GetCoor();
    vector<double> Xvalue;
    vector<double> Yvalue;
    Xvalue.resize(0);
    Yvalue.resize(0);
    for(int i=0;i<3;i++){
        for(int j=i+1 ;j<4;j++){
            if(MultiCoor(VectorCoor(c[i],c[j]),YAxis)==0){
                Xvalue.push_back(Module(c[i],c[j]));
            }
            else if(MultiCoor(VectorCoor(c[i],c[j]),XAxis)==0){
                Yvalue.push_back(Module(c[i],c[j]));
            }
            else{
            }
        }
    }
    if(Xvalue.size()==Yvalue.size()){
        SetWidth(Xvalue[0]>Yvalue[0]?Xvalue[0]:Yvalue[0]);
        SetLength(Xvalue[0]<Yvalue[0]?Xvalue[0]:Yvalue[0]);
        return true;
    }
    else{
        cout<<"Wrong input!\n";
        return false;
    }
}
void RecAngle::Print(){
    cout<<"Recangle: \n";
    Quadrangle::Print();
    cout<<"\n\t-Width: "<<GetWidth()<<endl;
    cout<<"\n\t-Length: "<<GetLength()<<endl;
}


//Square definition
//Constructor and Destructor
Square::Square(){
    Edge=0;
}
Square::Square(double e){
    Edge=e;
}
Square::~Square(){
}
//Setter
void Square::Set(){
    cout<<"Input Edge:\n";
    Quadrangle::Set();
}
void Square::SetEdge(double e){
    Edge=e;
}
//other method
bool Square::Check(){
    if(RecAngle::Check()==1&&RecAngle::GetLength()==RecAngle::GetWidth()){
        SetEdge(RecAngle::GetLength());
        return true;
    }
    else{
        cout<<"Wrong input!\n";
        return false;
    }
}
void Square::Print(){
    cout<<"Square: \n";
    Quadrangle::Print();
    cout<<"\n\tEdge: "<<GetEdge();
}