
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
    if(p==nullptr) exit(1);
    p->key=x;
    p->left=nullptr;
    p->right=nullptr;
    return p;
}

typedef Node* Tree;

void CreateEmptyTree(Tree &t)
{
    t=nullptr;
}
void Add_1(Tree &t, int x)
{
    if(t)
    {
        if(t->key==x) return;
        if(t->key>x) return Add_1(t->left, x);
        else  return Add_1(t->right,x);
    }
    t=CreateNode(x);
    return;
}

void Add_n(Tree &t)
{
    int n,x; cin>>n;
    for(int i=0; i< n; i++)
    {
        cin>>x;
        Add_1(t, x);
    }
}

Node* binarysearch(Tree t, int x)
{
    if(t)
    {
        if(t->key==x) return t;
        if(t->key>x) return binarysearch(t->left, x);
        else return binarysearch(t->right, x);
    }
    return nullptr;
}

int height(Tree t)
{
    if(t==nullptr) return -1;
    int a=height(t->left);
    int b=height(t->right);
    return (a>b?a:b)+1;
}

void Out(Tree t, int h)
{
    if(t)
    {
        Out(t->left, h);
        if(height(t)==h) cout<<t->key<<" ";
        Out(t->right, h);
    }
    return;
}
void Function(Tree t)
{
    int h; cin>>h;
    if(h<0 ||h>height(t)) {cout<<"No Node"; return;}
    else Out(t, h);
}

int main()
{
    Tree t;
    CreateEmptyTree(t);
    Add_n(t);
    Function(t);
}