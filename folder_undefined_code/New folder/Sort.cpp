#include<bits/stdc++.h>

class Node
{
    public:
     int value;
     Node* next;
    public:
     Node(int x)
     {
        this->value=x;
        this->next=NULL;
     }
};

class List
{
    private:
     Node* head;
     Node* tail;
    public:
     List()
     {
        head=NULL;
        tail=NULL;
     }
     void AddNode(int x)
     {
        Node *node=new Node(x);
       if(head==NULL) head=node;
       else tail->next=node;
       tail=node;
     }
     void Input()
     {
        int n,x;
        std::cin>>n;
        for(int i=0; i<n; i++)
        {
            std::cin>>x;
            AddNode(x);
        }
     }
     void Output()
     {
        Node* node=head;
        while(node!=NULL)
        {
            std::cout<<node->value<<" ";
            node=node->next;
        }
     }
     Node * Mid()
     {
        Node* node=head;
        Node* node1=head;
        while(node1->next!=NULL&&node1->next->next!=NULL)
        {
            node=node->next;
            node1=node1->next->next;
        }
        return node;
     }
};


int main()
{
    List L=List();
    L.Input();
    Node* p=L.Mid();
    std::cout<<p->value<<"\n";
    L.Output();
return 0;
}