#include<bits/stdc++.h>
#include<cstring>
using namespace std;

struct Node 
{
    char info;
    Node* next;
};

Node *CreateNode(char x)
{
    Node *p= new Node;
    p->info=x;
    p->next=nullptr;
    return p;
}

struct Stack
{
    
void push(Node** top, char x)
{
   Node* p= CreateNode(x);
   if((*top) == NULL) (*top)=p;
   else
   {   p->next=(*top);
       (*top)=p;
   }
}

void pop(Node** top)   //Removehead()
{
   if(top!=NULL)
   {
    Node* temp=(*top);
    (*top)=temp->next;
    delete(temp);
   }
}

int size(Node* top)
{
    int t=0;
    while(top!=NULL)
    {
        ++t;
        top=top->next;
    }
    return t;
}

int Top(Node* top)
{
    return top->info;
}
};

struct Queue
{
    void push(Node **q, char x)
    {
        Node *p=CreateNode(x);
        if((*q)==NULL)
        {
            (*q)=p;
             return;
        }
        Node *temp=(*q);
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
    void pop(Node**q)
    {
      if((*q)==NULL) return;
      Node* temp=(*q);
      (*q)=(*q)->next;
      delete temp;  
    }
    int size(Node* q)
    {
        int t=0;
        while(q!=NULL)
        {
            t++;
            q=q->next;
        }
        return t;
    }
    int front(Node* q)
    {
        return q->info;
    }
    bool empty(Node *q)
    {
        return q==NULL;
    }
    void duyet(Node *q)
    {
        while(q!=NULL)
        {
            cout<<q->info<<" ";
            q=q->next;
        }
    }
};


int main()
{
    Node* stack=NULL;
    Node *queue=NULL;
    Stack st;
    Queue q;
    string s;
    getline(cin, s);
    for(int i=0; i<s.size(); i++)
    {
        st.push(&stack, tolower(s[i]));
        q.push(&queue, tolower(s[i]));
    }
    bool check=true;
    while(q.empty(queue)!=true)
    {
        if(st.Top(stack)!=q.front(queue)) {check=false; break;}
        q.pop(&stack);
        st.pop(&queue);

    }
    if(check==true) cout<<"YES";
    else cout<<"NO";
return 0;
}
