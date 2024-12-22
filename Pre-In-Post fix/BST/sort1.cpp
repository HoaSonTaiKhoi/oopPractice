// Sort1
#include <iostream>
#include <string.h>
using namespace std;

struct point {
    int x, y;
};

struct node {
	point info;
	node* next;
};

struct List {
	node* head;
	node* tail;
};

void CreateEmptyList(List &L)
{
    L.head=nullptr;
    L.tail=nullptr;
}
node* CreateNode(int x, int y)
{
    node*p=new node;
    if(!p) exit(1);
    p->info.x=x;
    p->info.y=y;
    p->next=nullptr;
return p;
}

void CreateList(List&L)
{
    int n,x,y; cin>>n;
    while(n>0)
    {
        cin>>x>>y;
        node *p=CreateNode(x, y);
        if(L.head==nullptr) L.head=p;
        else L.tail->next=p;
        L.tail=p;
        n--;
    }
}

void addhead(List&L, int x, int y)
{
    node *p=CreateNode(x, y);
    if(!p) exit(1);
    if(!L.head) {L.head=p;L.tail=p;}  // nhớ kĩ
    else {p->next=L.head; L.head=p;}
}

void removehead(List&L, int &a, int&b)
{
    if(L.head)
    {
    node* tmp=L.head;
    L.head=tmp->next;
    a=tmp->info.x;
    b=tmp->info.y;
    delete tmp;

    if(!L.head) L.tail=nullptr;  //nhớ kĩ L.head null rồi thì tail cũng null
    }
    else return;
}

void quicksort(List&L)
{
    if(!L.head) return;
      List Left, Right, Mid;
      CreateEmptyList(Left); CreateEmptyList(Right); CreateEmptyList(Mid);
    int x,y, z, t;

    removehead(L, x, y); addhead(Mid, x, y);
    while(L.head)
    {
        removehead(L, z,t );
        if(z<x||(z==x&&t<y)) addhead(Left, z, t);
        else if(z>x||(z==x&& t>y)) addhead(Right, z,t);
        else addhead(Mid, z, t);
    }

    quicksort(Left); quicksort(Right);

    if(Left.head)
    {
        Left.tail->next=Mid.head;
        Mid.head=Left.head;
    }
    if(Right.head)
    {
        Mid.tail->next=Right.head;
        Mid.tail=Right.tail;
    }
    L=Mid;
}

void PrintList(List L)
{
    quicksort(L);
    node* p=L.head;
    while(p!=nullptr)
    {
        cout<<"("<<p->info.x<<","<<p->info.y<<")\n";
        p=p->next;
    }
}

int main() {
    List L;
	CreateEmptyList(L);
	CreateList(L);
	PrintList(L);
    return 0;
}