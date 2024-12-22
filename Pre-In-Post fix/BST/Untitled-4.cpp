
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int info;
    Node* left;
    Node* right;
};

Node* CreateNode(int x)
    {
        Node* p=new Node;
        p->info=x;
        p->left=nullptr;
        p->right=nullptr;
    return p;
    }

struct Tree
{
    Node *root=new Node;
    void CreateTree()
    {
        root=nullptr;
    }
    void InsertNode(int x)
    {
        Node *p=CreateNode(x);
        Node* tmp=new Node;
        tmp=root;
        if(root==nullptr) {root=p; return;}
        else 
        {
            while(tmp!=nullptr)
            {
                if(tmp->info==x) return;
                else if(x<tmp->info) 
                {
                    if(tmp->left==nullptr) tmp->left=p;
                    tmp=tmp->left;
                }
                else if(x>tmp->info)
                {
                    if(tmp->right==nullptr) tmp->right=p;
                    tmp=tmp->right;
                }
            }
            tmp=p;
        }
        return;
    }

    void binaryInsert(Node *&tmp, int x)
    {
        if(tmp!=nullptr)
        {
        if(tmp->info==x) return;
        else if(tmp->info>x) 
         {
        //    if(tmp->left!=nullptr) 
           binaryInsert(tmp->left, x);
            // else {tmp->left=CreateNode(x); return;}
         }
        else
         {
            // if(tmp->right!=nullptr)
             binaryInsert(tmp->right, x);
            // else {tmp->right=CreateNode(x); return;}
         }
        }
        else tmp=CreateNode(x);
        return;
    }

    void Add_n()
    {
        int x;
        do
        {
            cin>>x;
            if(x!=-1) binaryInsert(root, x);
        }while(x!=-1);
    }
    
    bool search(int x)
    {
        Node* p=root;
        while(p!=nullptr)
        {
            if(p->info==x) return 1;
            else if(x<p->info) p=p->left;
            else p=p->right;
        }
        return 0;
    }

    Node* binarysearch(Node* tmp, int x)
    {
        if(tmp==nullptr) return nullptr;
        if(tmp->info==x) return tmp;
        else if(tmp->info> x) return binarysearch(tmp->left, x);
        else return binarysearch(tmp->right, x);
    }

    Node* maxleft(Node* tmp)
    {
       tmp=tmp->left;
       Node* max=tmp;
       Node *p=tmp;
       while(p->right!=nullptr)
       {
        max=p->right;
        p=p->right;
       }
       return max;
    }
    Node *minright(Node* tmp)
    {
        tmp=tmp->right;
        Node* min=tmp;
        Node* p=tmp;
        while (p->left!=nullptr)
        {
            min=p->left;
            p=p->left;
        }
        return min;
    }


    void delNode(int x)
    {
        Node* key=binarysearch(root, x);
        if(key->left==nullptr&& key->right==nullptr) 
        {
            Node* tmp=key;
            key=nullptr;
            delete tmp;
        }   
        else
        {
            Node* p1=maxleft(key);
            Node* p2=minright(key);
            if(p1->left==nullptr&&p1->right==nullptr)
            {
                swap(p1->info, key->info);
                Node* tmp=p1;
            p1=nullptr;
            delete tmp;
            }
            else if(p2->left==nullptr&& p2->right==nullptr)
            {
                swap(p2->info, key->info);
                Node* tmp=p2;
                p2=nullptr;
                delete tmp;
            }
        }
    }
    void preorder(Node* temp)
    {
        if(temp!=nullptr)
        {
            cout<<temp->info<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
        return;
    }
    void inorder(Node* temp)
    {
        if(temp!=nullptr)
        {
            inorder(temp->left);
            cout<<temp->info<<" ";
            inorder(temp->right);
        }
        return;
    }
    void postorder(Node *temp)
    {
    }


    int Height(Node* temp)
    {
        if(temp!=nullptr)
        {
            int a=Height
        }
    }
    void leaf(Node * temp)
    {
        if(temp!=nullptr)
        {
            leaf(temp->left);
            if(temp->left==nullptr&& temp->right==nullptr) cout<<temp->info<<" ";
            leaf(temp->right);
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
            <<"2. Add nhieu so\n"
            <<"3. Duyet\n"
            <<"4. Tim leaf\n"
            <<"5. Chieu cao\n"
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
            t.binaryInsert(t.root, x);
        }
        else if(key==2)
        {
            t.Add_n();
        }
        else if(key==3) {t.preorder(t.root); cout<<"\n";}
        else if(key==4) 
        {
            t.leaf(t.root);
        }
    }
return 0;
}