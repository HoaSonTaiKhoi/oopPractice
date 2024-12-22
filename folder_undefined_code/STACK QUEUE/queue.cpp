#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

Node *CreateNode(int x)
{
    Node*p=new Node;
    p->info=x;
    p->next=NULL;
return p;
}
struct Queue
{
    Node* queue=NULL;
    void push()
    {
        int x; cin>>x;
        Node*p= CreateNode(x);
        if(queue==NULL)
        {
            queue=p;
            return;
        }
        Node*t=queue;
        while(t->next!=NULL) t=t->next;
        t->next=p;
    }
    void pop()
    {   
        if(queue!=NULL)
        {
        Node *temp=queue;
        queue=queue->next;
        delete temp;
        }
    }
    int  size()
    {
        Node*p=queue; int t=0;
        while(p!=NULL)
        {
            t++;
            p=p->next;
        }
        return t;
    }
    int front()
    {
        return queue->info;
    }
    void Duyet()
    {
        Node*p=queue;
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
    }
    bool empty()
    {
        return queue==NULL;
    }

};

int main()
{
    Queue q;
    int key;
    while(true)
    {
        cout<<"________________\n";
        cout<<"1. Push.\n";
        cout<<"2. Pop.\n";
        cout<<"3. Size.\n";
        cout<<"4. Top.\n";
        cout<<"5. Duyet.\n";
        cout<<"6. Empty or not.\n";
        cout<<"0. END.\n";
        cout<<"Nhap lua chon: "; cin>>key;

        if(key==1) q.push();
        else if (key==2) q.pop();
        else if(key==3) cout<<q.size();
        else if(key==4) cout<<q.front();
        else if(key==5) q.Duyet();
        else if(key==6) cout<<q.empty();
        else if(key==0) break; 
        cout<<"\n";
    }
}