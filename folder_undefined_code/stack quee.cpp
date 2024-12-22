#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
     int info;
     Node *next;
    Node(int x)
    {
        this->info=x;
        this->next=nullptr;
    }
    void Xuat()
    {
        cout<<this->info;
    }
};
struct Stack
{
    Node* stack=nullptr;
    
    void Push(int x)
     {
        Node*p=new Node(x);
        if(stack!=nullptr) p->next=stack;
        stack=p;
     }
    void Pop()
     {
        Node* temp=stack;
        stack=stack->next;
        delete(temp);
     }
    int  Top()
     {
        return stack->info;
     }
    int Size()
     {
        int size=0;
        Node *p= stack;
        while(p!=nullptr)
        {
            size++;
            p=p->next;
        }
        return size;
     }
    void Duyet()
     {
        Node*p=stack;
        while(p!=nullptr)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
        cout<<"\n";
     }
};

int main()
{
    Stack st;
    while(true)
    {
        cout<<"_______________\n"
            <<"1. Push.\n"
            <<"2. Pop.\n"
            <<"3. Top.\n"
            <<"4. Size.\n"
            <<"5. All.\n"
            <<"0. END.\n"
            <<"_______________\n"
            <<"Your choice: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1) {int x; cout<<"Nhap x: "; cin>>x; st.Push(x);}
        else if(key==2) st.Pop();
        else if(key==3) cout<<st.Top()<<"\n";
        else if(key==4) cout<<st.Size()<<"\n";
        else if(key==5) st.Duyet();
    }
return 0;
}