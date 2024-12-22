// queue01
#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Queue
struct Queue{
	node* head;
	node* tail;
};
void CreateEmptyQueue(Queue &l)
{
    l.head=NULL;
    l.tail=NULL;
}
node* CreateNode(int x)
{
    node* p = new node();
    if(p==NULL) exit(1);
    p->info=x;
    p->next=NULL;
    return p;
}

void push(Queue &l, int x)
{
    node* p=CreateNode(x);
    if(!p) exit(1);
    if(!l.head) l.head=p;
    else l.tail->next=p;
    l.tail=p;
}

void CreateQueue(Queue&l)
{
    string s; cin>>s; int count=1;
    push(l, (int)s[0]);
    for(int i=1; i<s.length(); i++)
    {
        if(l.tail->info!=(int)s[i]) {push(l, count); push(l, (int)s[i]); count=1;}
        else count++;
    }
    push(l, count);
}
void PrintQueue(Queue l)
{
     for(node*p=l.head; p!=NULL; p=p->next)
        cout<<p->info;
}
int main() {
    Queue L;
    CreateEmptyQueue(L);
    CreateQueue(L);
    PrintQueue(L);
    return 0;
}
