
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node* left;
    Node* right;
    Node(int x)
    {
        this->info=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};

typedef Node* Tree;

void insert(Tree &t, int x)
{
    if(t)
    {
        if(t->info==x) return;
        if(t->info>x) return insert(t->left, x);
        else return insert(t->right, x);
    }
    else t=new Node(x);
return;
}

void insert_n(Tree&t)
{
    int n;
    cin>>n;
    while(n>0)
    {
        int x; cin>>x;
        insert(t, x);
        n--;
    }
}

void NLR_dequy(Tree t)
{
    if(t) 
    {
        cout<<t->info<<" ";
        NLR_dequy(t->left);
        NLR_dequy(t->right);
    }
    return;
}

void NLR_stack(Tree t)
{
    stack<Node*> a;
    a.push(t);
    while(!a.empty())
    {
        Node* p=a.top();
        a.pop();
        cout<<p->info<<" ";
        if(p->right) a.push(p->right);
        if(p->left) a.push(p->left);
    }
}

void LNR_stack(Tree t)
{
    stack<Node*> a;
    while(true)
    {
        while(t)
        {
            a.push(t);
            t=t->left;
        }
        if(!a.empty())
        {
            cout<<a.top()->info<<" ";
            if(a.top()->right) t=a.top()->right;
            a.pop();
        }
        else break;
    }
}

void LRN_stack(Tree t)
{
    // stack<Node*> a;
    // Node* lastnode=nullptr;
    // while(true)
    // {
    //     while(t)
    //     {
    //         a.push(t);
    //         t=t->left;
    //     }

    //     if(a.top()->right && lastnode!=a.top()->right){t=a.top()->right;}
    //     else
    //     {
    //         cout<<a.top()->info<<" ";
    //         lastnode=a.top();
    //         a.pop();
    //     }

    //     if(!a.empty()) break;
    // }

     stack<Node*> a;
        Node* lastnode=nullptr;
        while(true)
        {
            while(t)
            {
                a.push(t);
                t=t->left;
            }
            if(a.top()->right&& lastnode!=a.top()->right) {t=a.top()->right;}
            else
            {
                cout<<a.top()->info<<" ";
                lastnode=a.top();
                a.pop();
            }
            if(a.empty()) break;
        }
}

int main()
{
    Tree t;
    t=nullptr;
    insert_n(t);
    while(true)
    {
        cout<<"________________\n"
            <<"1. LNR_stack\n"
            <<"2. NLR_stack\n"
            <<"3. LRN_stack\n"
            <<"0. END\n"
            <<"________________\n"
            <<"Your choice: ";
        int key; cin>>key;
        if(key==0) break;
        else if(key==1) LNR_stack(t);
        else if(key==2) NLR_stack(t);
        else if(key==3) LRN_stack(t);
    cout<<"\n";
    }
return 0;
}