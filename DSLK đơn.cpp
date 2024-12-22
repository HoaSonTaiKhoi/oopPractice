
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
     int value;
     Node *next;
    public:
     Node( int value)
     {
        this->value=value;
        this->next=NULL;
     }
};
class List
{
    private:
     Node *head;
     Node *tail;
    public:
     List()
     {
        this->head=NULL;
        this->tail=NULL;
     }
     void AddNode(int value)
     {
        Node *node=new Node(value);
        if(head==NULL)
        {
            head=node;
        }
        else
        {
            tail->next=node;
        }
        tail=node;
     }
     void displayNode()
     {
        Node *p=head;
        while(p!=NULL)
        {
            cout<<p->value<<" ";
            p=p->next;
        }
     }
};


int main()
{
    List L=List();
    int n; cin>>n;
    for(int i=0; i<n; i++)  
    {
        int x; cin>>x;
        L.AddNode(x);
    }
    L.displayNode();
return 0;
}