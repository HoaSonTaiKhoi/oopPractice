
#include<bits/stdc++.h>

using namespace std;

class matrix
{
    private:
    int dong, cot;
     vector<vector<int>> m;
    bool check;
    public:
     matrix();
     ~matrix();
     void clear();
     void Nhap();
     void Xuat();
     friend istream& operator >> (istream& in, matrix& matrix1);
     friend ostream& operator <<(ostream& out, const matrix& matrix1);
     matrix& operator = (const matrix& matrix1);
     friend matrix operator + (matrix m,const matrix& matrix1);
     friend matrix operator - (matrix m,const matrix& matrix1);
     friend matrix operator * (matrix matrix1, const matrix &matrix2);
};

matrix::matrix()
{
    this->dong=this->cot=0;
    this->check=0;
}

matrix::~matrix()
{
    this->m.clear();
    this->dong=0;
    this->cot=0;
    this->check=0;
}

void matrix::clear()
{
    this->m.clear();
    this->dong=0;
    this->cot=0;
    this->check=0;
}

void matrix::Nhap()
{
    this->m.clear();
    cout<<"Nhap so dong, cot: "; cin>>this->dong>>this->cot;
    this->m.resize(this->dong, vector<int> (this->cot,0));
    for(int i=0; i<this->dong; i++)
    {
        for(int j=0; j<this->cot; j++)
        {
            int x; cin>>x;
            m[i][j]=x;
        }
    }
}

void matrix::Xuat()
{
    if(!check) cout<<*this;
    else cout<<"Khong hop le"; 
    return;
}

matrix &matrix::operator=(const matrix &matrix1)
{
    this->dong=matrix1.dong;
    this->cot=matrix1.cot;
    this->m.clear();
    this->m.resize(matrix1.dong, vector<int> (matrix1.cot, 0));
    for(int i=0; i<dong; i++)
    {
        for(int j=0; j<cot; j++)
        this->m[i][j]=matrix1.m[i][j];
    }
    return *this;
}

matrix operator+(matrix m,const matrix &matrix1)
{
    if(m.dong==matrix1.dong&& m.cot==matrix1.cot)
    {
        for(int i=0; i<m.dong; i++)
        {
            for(int j=0; j<m.cot; j++)
             m.m[i][j]+=matrix1.m[i][j];
        }
    }
    else m.check=1;
    return m;
}

matrix operator - (matrix m,const matrix &matrix1)
{
    if(m.dong==matrix1.dong&& m.cot==matrix1.cot)
    {
        for(int i=0; i<m.dong; i++)
        {
            for(int j=0; j<m.cot; j++)
             m.m[i][j]-=matrix1.m[i][j];
        }
    }
    else m.check=1;
    return m;
}

istream & operator >>(istream& in, matrix& matrix1)
{
    matrix1.m.clear();
    cout<<"Nhap so dong, cot: "; in>>matrix1.dong>>matrix1.cot;
    matrix1.m.resize(matrix1.dong, vector<int> (matrix1.cot,0));
    for(int i=0; i<matrix1.dong; i++)
    {
        for(int j=0; j<matrix1.cot; j++)
        {
            int x; cin>>x;
            matrix1.m[i][j]=x;
        }
    }
    return in;
}

ostream& operator << (ostream& out, const matrix& matrix1)
{
    for(int i=0; i<matrix1.dong; i++)
    {
        for(int j=0; j<matrix1.cot; j++)
        {
            out<<matrix1.m[i][j];
            if(j!=matrix1.cot-1) out<<" ";
        }
        if(i!=matrix1.dong-1) out<<"\n";
    }
    return out;
}

matrix operator*(matrix matrix1, const matrix &matrix2)
{
    if(matrix1.cot==matrix2.dong)
    {
        matrix other=matrix1;
        matrix1.clear();
        matrix1.dong=other.dong;
        matrix1.cot=matrix2.cot;
        matrix1.m.resize(matrix1.dong, vector<int> (matrix1.cot, 0));
        for(int i=0; i<other.dong; i++)
        {
            for(int j=0; j<matrix2.cot; j++)
            {
                int s=0;
                for(int e=0; e<other.cot; e++)
                s+=other.m[i][e]*matrix2.m[e][j];
            matrix1.m[i][j]=s;
            }
        }   
    }
    else matrix1.check=1;

return matrix1;
}


int main()
{
    matrix m1, m2, m3;
    while(true)
    {
        cout<<"1. Nhap.\n"
            <<"2. Xuat.\n"
            <<"3. Cong.\n"
            <<"4. Tru.\n"
            <<"5. Nhan.\n"
            <<"0. END.\n"
            <<"Yourchoice: ";
        int key; cin>>key;
        if(key==0) break;
        switch (key)
        {
         case 1: cin>>m1; break;
         case 2: m1.Xuat(); break;
         case 3: cin>>m2; m3=m1+m2; m3.Xuat(); break;
         case 4: cin>>m2; m3=m1-m2; m3.Xuat(); break;
         case 5: cin>>m2; m3=m1*m2; m3.Xuat(); break;
        }
        m2.clear(); m3.clear();
    cout<<"\n";
    }
}