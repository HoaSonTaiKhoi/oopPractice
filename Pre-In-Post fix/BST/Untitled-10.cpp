
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int info;
    Node* left, *right;
    Node(int x)
    {
        this->info=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};

typedef Node* Tree;

void CreateTree(Tree &t)
{
    t=nullptr;
}

void Add_1(Tree &t, int x)
{
    if(t)
    {
        if(t->info==x) return;
        else if(t->info>x) return Add_1(t->left, x);
        else return Add_1(t->right, x);
    }
    else t=new Node(x);
    return;
}

void Add_n(Tree &t)
{
    CreateTree(t);
    int n,x; cin>>n;
    while(n>0)
    {
        cin>>x;
        Add_1(t, x);
        n--;
    }
}

void Duyet_bst_width(Tree t)
{
    if(t)
    {
        queue<Tree> a;
        a.push(t);
        while (!a.empty())
        {
            Node* p= a.front();
            cout<<p->info<<" ";
            a.pop();
            if(p->left) a.push(p->left);
            if(p->right) a.push(p->right);
        }
    }
}

Node * search(Tree t,int x)
{
    if(t)
    {
        if(t->info==x) return t;
        else if(t->info>x) return search(t->left, x);
        else return search(t->right, x);
    }
    else return nullptr;
}

void Thaythe(Node* &p, Node* &tmp)
{
    if(tmp->left) Thaythe(p, tmp->left);
    else
    {
        p->info=tmp->info; //lúc này p vẫn còn đang trỏ vào t cũ ( tức cái t-> right ở hàm Xoa_x) nên những gì thay đổi của p cụ thể là info thì t hở hàm Xoa_x cũng có info thay đổi.
        p=tmp; //lúc này p đã trỏ vào địa chỉ mới- tmp nên không còn dính dáng gì tới p cũ (p=t ở Xoa_x).
        tmp=tmp->right; //vì lấy cây con bên phải nên lúc làm cái node cần xóa biến mất thì phải đẩy theo bên phải. lúc này tmp->left đang nullptr
        // ví dụ    6
        //       4     9
        //     3   5  7  10
        //   1         8
    }
}
void Xoa_x(Tree &t, int x)
{
    if(t)
    {
        if(t->info>x) Xoa_x(t->left, x);
        else if(t->info<x) Xoa_x(t->right, x);
        else
        {
            Node * p=t;
            if(t->right==nullptr && t->left==nullptr) {t=t->right; delete p; return;}
            if(t->left==nullptr) t=t->right;
            else if(t->right==nullptr) t=t->left;
            else
            {
                Thaythe(p, t->right);
            }
        }
    }
}

int leaf(Tree t)
{
    if(t)
    {
        if(!t->left&& !t->right) return 1;
    }
    else return 0;
    return leaf(t->left)+leaf(t->right);
}

int count_1_con(Tree t)
{
    if(t)
    {
     if(!t->left&&!t->right) return 0;
     else if(t->left&&t->right) return count_1_con(t->left)+count_1_con(t->right);
     else
     {
        if(t->left) return 1+count_1_con(t->left);
        else if(t->right) return 1+count_1_con(t->right);
     }
    }
    return 0;
}
int main()
{
    Tree t;
    Add_n(t);
    Duyet_bst_width(t);

    int x; cin>>x;
    Xoa_x(t,x);
    cout<<"\n";
    Duyet_bst_width(t);
    cout<<"\n"
        <<leaf(t)<<"\n"
        <<count_1_con(t);
return 0;
}