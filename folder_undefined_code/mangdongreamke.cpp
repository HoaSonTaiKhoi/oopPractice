#include<bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
struct Point
{
    int value;
    Point *pNext;
};
struct List
{
    Point *pHead;
    Point *pTail;
};
void KhoiTaoList(List &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}
Point *KhoiTaoPoint(int x)
{
    Point *p=new Point;
    if(p==NULL)  exit(1);
    p->value=x;
    p->pNext=NULL;
return p;
}
void AddPoint_DauList(List &L, Point *p)
{
    if(p==NULL) exit(1);
    if(L.pHead==NULL)
    {
        L.pHead=p;
        L.pTail=p;
    }
    else
    {
        p->pNext=L.pHead;
        L.pHead=p;
    }
}
void AddPoint_CuoiList(List &L, Point *p)
{
    if(p==NULL) exit(1);
    if(L.pHead==NULL)
    {
        L.pHead=p;
        L.pTail=p;
    }
    else 
    {
        L.pTail->pNext=p;
        L.pTail=p;
    }
}
void Tim_and_Addvaosau(List &L, Point *p, int x)
{
    Point *temp=L.pHead;
    while(temp!=NULL)
    {
        if(temp->value==x) break;
        temp=temp->pNext;
    }
    if(temp!=NULL)
    {
         if(temp==L.pTail) AddPoint_CuoiList(L, p);
         else if(temp==L.pHead) AddPoint_DauList(L,p);
         else
         {
            p->pNext=temp->pNext;
            temp->pNext=p;
         }
    }
    else AddPoint_DauList(L,p );
return;
}

void DeletePoint(List &L, int x)
{
    Point*del;
    Point *temp=L.pHead; Point *temp1=L.pHead;
    while(temp!=NULL)
    {
        
        if(temp->value==x) break;
        temp1=temp;
        temp=temp->pNext;
    }
    if(temp!=NULL)
    {
        if(temp==L.pTail)
        {
            del=L.pTail;
            temp1->pNext=NULL;
            L.pTail=temp1;
            delete(del);
            return;
        }
        else if(temp==L.pHead)
        {
            del=L.pHead;
            L.pHead=temp->pNext;
            if(L.pHead==NULL) L.pTail=NULL;
            delete(del);
            return;
        }
        else
        {
            del=temp;
            temp1->pNext=temp->pNext;
            delete(del);
            return;
        }

    }
}

bool isPrime(int x)
{
    if(x<2) return false;
    else if(x==2||x==3) return true;
    else if(x%2==0||x%3==0) return false;
    else
    {
        int k=5;
        while(k*k<=x)
        {
            if(x%k==0||x%(k+2)==0) return false;
            k+=6;
        }
    }
    return true;
}


void InList(List &L)
{
    Point *p=L.pHead;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->pNext;
    }
}
void DelPrime(List &L)
{
    Point *temp=L.pHead; Point*temp1=L.pHead; Point *del;
    while(temp!=NULL)
    {
        if(isPrime(temp->value))
        {
           if(temp==L.pTail)
           {
              del=temp;
              temp1->pNext=L.pTail->pNext;
              L.pTail=temp1;
              delete(del);
              temp=NULL;
           }
           else if(temp==L.pHead)
           {
             del=L.pHead;
             L.pHead=temp->pNext;
             if(L.pHead==NULL) L.pTail=NULL;
             delete(del);
           }
           else
           {
             del=temp;
             temp1->pNext=temp->pNext;
             delete(del);
           }
        }
        temp1=temp;
        if(temp1!=NULL)
        {
            temp=temp->pNext;
        }
    }
return;
}

void Point_sau_Prime_Point(List &L, int x)
{
    
    Point *temp=L.pHead;
    Point *temp1=new Point;
    while(temp!=NULL)
    {
        Point *p=KhoiTaoPoint(x);
        temp1=temp->pNext;
        if(isPrime(temp->value))
        {
            if(temp==L.pTail) 
            {
                AddPoint_CuoiList(L, p);
                temp1=NULL;
            }
            else
            {
                p->pNext=temp->pNext;
                temp->pNext=p;
            }
        }
     temp=temp1;
    }
return;
}
int main()
{
    List L;
    KhoiTaoList(L);
    int x;
    ifstream in ("filemangdong.txt");
    while(!in.eof())
    {
        in>>x;
        AddPoint_CuoiList(L, KhoiTaoPoint(x));
    }
    in.close();
    //Add dau chuoi bang chuoi khac
    /*ifstream input("filemangdong1.txt");
    while(!input.eof())
    {
        input>>x;
        AddPoint_DauList(L, KhoiTaoPoint(x));
    }*/
    Tim_and_Addvaosau(L, KhoiTaoPoint(7), 9);
    Point_sau_Prime_Point(L, 10);
    InList(L);
return 0;
}