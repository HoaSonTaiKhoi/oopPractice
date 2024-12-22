#include<bits/stdc++.h>
#include<string>
using namespace std;

struct Node
{
    string info;
    Node* next;
};

Node * CreateNode(string x)
{
    Node * p=new  Node;
    p->info=x;
    p->next=NULL;
    return p;
}
struct Stack
{
    Node *top= NULL;
    void push(string x)
    {
       Node*p= CreateNode(x);
       if(top==NULL)
       {
         top=p;
         return;
       }
       p->next=top;
       top=p;
    }
    void pop()
    {
        if(top!=NULL)
        {
        Node *temp=top;
        top=top->next;
        delete(temp);
        }
    }
    int size()
    {
        Node*p=top; int t=0;
        while(p!=NULL)
        { 
            t++;
            p=p->next;
        }
        return t;
    }

    string Top()
    {
        return top->info;
    }

    void Duyet()
    {
        Node *p=top;
        if(p!=NULL)
        {
        while(p!=NULL)
        {
            cout<<p->info<<" ";
            p=p->next;
        }
        }
    }
};

int main()
{
    Stack st;
    string s;
    getline(cin,s);
    stringstream is(s);
    while(true)
    {
        string temp;
        is>>temp;
        if(temp=="\n"||temp=="\0") break;
        st.push(temp);
    }
    st.Duyet();
}

/* while(true)
    {
        cout<<"________________\n";
        cout<<"1. Push.\n";
        cout<<"2. Pop.\n";
        cout<<"3. Size.\n";
        cout<<"4. Top.\n";
        cout<<"5. Duyet.\n";
        cout<<"0. END.\n";
        cout<<"Nhap lua chon: "; cin>>key;

        if(key==1) st.push();
        else if (key==2) st.pop();
        else if(key==3) cout<<st.size();
        else if(key==4) cout<<st.Top();
        else if(key==5) st.Duyet();
        else if(key==0) break; 
        cout<<"\n";
    }*/