#pragma once
#include<vector>
using namespace std;
struct Coordinate{
    double x;
    double y;
};
class Quadrangle
{
private:
    Coordinate Coor[4];
public:
    //constructor and destructor
    Quadrangle();
    Quadrangle(Coordinate *coor);
    virtual ~Quadrangle();

    //Setter
    void SetCoor(Coordinate coor[4]);
    virtual void Set();
    
    //Getter
    Coordinate* GetCoor(){return Coor;}
    
    //other methods
    virtual bool Check()=0;
    virtual void Print();
};
class Trapeze :public Quadrangle
{
private:
    double LongEdge;
    double ShortEdge;
    double Heigth;
public:
    //Constructor and Destructor
    Trapeze();
    Trapeze(double l,double s,double h);
    ~Trapeze();
    //Setter
    void Set();
    void SetLongEdge(double w);
    void SetShortEdge(double l);
    void SetHeigth(double h);
    //Getter
    double GetLongEdge(){return LongEdge;}
    double GetShortEdge(){return ShortEdge;}
    double GetHeigth(){return Heigth;}
    //other method
    virtual bool Check();
    void Print();
};
class Parallelogram :public Quadrangle
{
private:
    double LongEdge;
    double ShortEdge;
    double Heigth;
public:
    //Constructor and Destructor
    Parallelogram();
    Parallelogram(double l,double s,double h);
    ~Parallelogram();
    //Setter
    void Set();
    void SetLongEdge(double w);
    void SetShortEdge(double l);
    void SetHeigth(double h);
    //Getter
    double GetLongEdge(){return LongEdge;}
    double GetShortEdge(){return ShortEdge;}
    double GetHeigth(){return Heigth;}
    //other method
    virtual bool Check();
    void Print();
};
class RecAngle:public Quadrangle
{
private:
    double Width;
    double Length;
public:
    //Constructor and Destructor
    RecAngle();
    RecAngle(double w,double l);
    ~RecAngle();
    //Setter
    void Set();
    void SetWidth(double w);
    void SetLength(double l);
    //Getter
    double GetWidth(){return Width;}
    double GetLength(){return Length;}
    //other method
    virtual bool Check();
    virtual void Print();
};
class Square:public RecAngle
{
private:
    double Edge;
public:
    //Constructor and Destructor
    Square();
    Square(double e);
    ~Square();
    //Setter
    void Set();
    void SetEdge(double e);
    //Getter
    double GetEdge(){return Edge;}
    //other method
    virtual bool Check();
    void Print();
};




