
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node* left;
    Node* right;
};

Node* CreateNode(int x)
{
    Node* p=new Node;
    p->key=x;
    p->left=nullptr;
    p->right=nullptr;
    return p;
}

struct Tree
{
    Node* root=new Node;
    void CreateTree(){ root =nullptr;}
    void binaryAdd_1(Node *&temp, int x)
    {
        if(temp!=nullptr)
        {
            if(temp->key==x) return;
            else if(temp->key>x) 
            {
                //    if(tmp->left!=nullptr) 
           binaryAdd_1(temp->left, x);
            // else {tmp->left=CreateNode(x); return;}
         }
        else if(key->key<x)
         {
            // if(tmp->right!=nullptr)
             binaryAdd_1(temp->right, x);
            // else {tmp->right=CreateNode(x); return;}
         }
        }
        else temp=CreateNode(x);
        return;
    }
    Node* binarysearch(Node* temp, int x)
    {
        if(temp!=nullptr)
        {
            if(temp->key==x) return temp;
            else if(temp->key>x) return binarysearch(temp->left, x);
            else return binarysearch(temp->right, x);
        }
        return nullptr;
    }

    void preorder(Node* temp)
    {
        if(temp!=nullptr)
        {
            cout<<temp->key<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
        return;
    }
};

int main()
{
    Tree t;
    t.CreateTree();
    while(true)
    {
        cout<<"_______________\n"
            <<"1. Add.\n"
            <<"2. Duyet\n"
            <<"3. Search\n"
            <<"0. END.\n"
            <<"_______________\n"
            <<"Nhap lua chon: ";
        int key,x;
            cin>>key;
        
        if(key==0) break;
        else if(key==1)
        {
            cout<<"Nhap x: "; cin>>x;
            // if(t.root==nullptr) t.root=CreateNode(x);
            t.binaryAdd_1(t.root, x);
        }
        else if(key==2)
        {
            t.preorder(t.root);
        }
        else if(key==3)
        {
            cout<<"Nhap x: "; cin>>x;
            cout<<t.binarysearch(t.root, x);
        }
    }
return 0;
}