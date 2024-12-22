//Sort2
#include <iostream>
using namespace std;
struct TIME{
    int gio,phut,giay;
};
 
struct node {
	TIME info;
	node* next;
};

struct List{
	node* head;
	node* tail;
};

node* CreateNode(int x, int y, int z)
{
    node *p= new node;
    if(!p) exit(1);
    p->info.gio=x;
    p->info.phut=y;
    p->info.giay=z;
    p->next=nullptr;
return p;
}

void CreateList(List &L)
{
    L.head=nullptr;
    L.tail=nullptr;

    int n, x, y, z; cin>>n;
    while(n>0)
    {
        cin>>x>>y>>z;
        node*p= CreateNode(x, y, z);
        if(!L.head) {L.head=p;L.tail=p;}
        else {p->next=L.head; L.head=p;}
        n--;
    }
}
void PrintList(List &L)
{
    node*p=L.head;
    while(p)
    {
        int get_total_sec=p->info.gio*3600+p->info.phut*60+p->info.giay;
        cout<<(get_total_sec/3600)%24<<"h"
        <<(get_total_sec/60)%60<<"p"
        <<get_total_sec%60<<"s"<<endl;
        p=p->next;
    }
}

int main() {
    List L;
    CreateList(L);
    PrintList(L);
    return 0;
}
