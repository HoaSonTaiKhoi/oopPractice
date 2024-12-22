//stack01
#include <iostream>
#include <string.h>
using namespace std;
// Cấu trúc của một node
struct node {
	int info;
	node* next;
};
// Cấu trúc của một Stack 
struct Stack {
	node* head;
	node* tail;
};
void CreateEmptyStack(Stack &l)
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

void push(Stack &st, int x)
{
    node*p=CreateNode(x);
    if(!p) exit(1);
    if(!st.head) {st.head=p;}
    else {p->next=st.head; st.head=p;}
}
bool check(Stack st, int x)
{
    if(!st.head) return true;
    while(st.head)
    {
        if(st.head->info==x) return false;
    st.head=st.head->next;
    }
    return true;
}

void CreateStack(Stack&st)
{
    int x;
    while(cin>>x&&x!=-1)
    {
        push(st,x);
    }
}

bool isPrime(int x)
{
    if(x<2) return false;
    else if(x==2||x==3) return true;
    else if(x%2==0 || x%3==0) return false;
    else 
    {
        int k=5;
        while(k*k<x)
        {
            if(x%k==0||x%(k+2)==0) return false;
            k+=6;
        }
    }
    return true;
}

void PrintStack(Stack &st)
{
    Stack st1;
    CreateEmptyStack(st1);
    while(st.head)
    {
        if(isPrime(st.head->info)&&check(st1, st.head->info)) 
        {
            push(st1,st.head->info); 
            cout<<st.head->info<<" ";
        }
        st.head=st.head->next;
    }
    if(!st1.head){cout<<"No SNT"; return;}
}

 
int main() {
    Stack L;
    CreateEmptyStack(L);
    CreateStack(L);
    PrintStack(L);
    return 0;
}
