#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct Phantu{
    int value;
    Phantu *pNext;
};
struct List
{
    Phantu *pHead;
    Phantu *pTail;

};
void KhoitaoList(List &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}
Phantu * KhoitaoPhantu(int x)
{
    Phantu *p=new Phantu;
    if(p==NULL) exit(1);
    p->value=x;
    p->pNext=NULL;
return p;
}
void AddPhantu_DauList(List &L, Phantu *p)
{
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
void AddPhantu_CuoiList(List &L, Phantu *p)
{
    if(L.pHead ==NULL)
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
void AddPhantu_sauvitri(List &L, Phantu*p, int x)
{
    Phantu *vitri=L.pHead;
    while(vitri!=NULL)
    {
        if(vitri->value==x) break;
        vitri=vitri->pNext;
    }
 if(vitri!=NULL) 
 {
    p->pNext=vitri->pNext;
    vitri->pNext=p;
    if(vitri==L.pTail) L.pTail=p;
 }
 else AddPhantu_DauList(L, p);
}
bool DeletePhantu_Dau(List &L)
{
    Phantu *p;
    if(L.pHead!=NULL)
    {
        p=L.pHead;
        L.pHead=L.pHead->pNext;
        if(L.pHead==NULL) L.pTail=NULL;
        delete p;
        return 1;
    }
    return 0;
}

bool DeletePhantu(List &L, int x)
{ Phantu * p;
     Phantu *vitri=L.pHead; Phantu *vitri1=L.pHead;
     while(vitri!=NULL)
     {
        if(vitri->value==x) break;
        vitri1=vitri;
        vitri=vitri->pNext;
     }
     if(vitri!=NULL)
     {
        if(vitri==L.pTail)
        {
            p=L.pTail;
            L.pTail=vitri1;
            vitri1->pNext=NULL;
            delete p;
            return 1;
        } 
        else if(vitri==L.pHead)
        {
            p=L.pHead;
            L.pHead=L.pHead->pNext;
            if(L.pHead==NULL) L.pTail=NULL;
            delete p;
            return 1;
        }
        else
        {
            p=vitri;
            vitri1->pNext=vitri->pNext;
            delete p;
            return 1;
        }
     }
     return 0;
}

main()
{
    List L;
    KhoitaoList(L);
    ifstream in("filemangdong.txt");
    while(!in.eof())
    {
        int x;
        in>>x;
        AddPhantu_CuoiList(L, KhoitaoPhantu(x));
    }
    int z=4;

    AddPhantu_sauvitri(L, KhoitaoPhantu(7), 4);
    DeletePhantu( L, 9);
    Phantu * p;
    p=L.pHead;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->pNext;
    }
return 0;
}