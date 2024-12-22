//bstree02


#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE; 

TNODE* newNode(int x)
{
    TNODE* p=new TNODE;
    if(!p) exit(1);
     p->key=x;
     p->pLeft=nullptr;
     p->pRight=nullptr;
    return p;
}

void insertnode(TREE &t, int x)
{
    if(t)
    {
        if(t->key==x) return;
        if(t->key>x) return insertnode(t->pLeft,x);
        else return insertnode(t->pRight,x);
    }
     t=newNode(x);
return;
}

int n=0;
void CreateTree(TREE &t)
{
    t=nullptr;

    int x;
    while(cin>>x && x!=-1)
    {
        insertnode(t, x);
        n++;
    }
}

int max_height(TREE t)
{
    if(!t) return -1;
    int a=max_height(t->pLeft);
    int b=max_height(t->pRight);
    return (a>b?a:b)+1;
}

bool check_level(TREE t,TNODE*p, int k)
{
    if(k>max_height(t)) return false;
    int height=0;
    if(t==p&&k==0) return true;
    else
    {
    while(t)
        {
            if(t->key>p->key) t=t->pLeft;
            else t=t->pRight;
            height++;
            if(t==p && height==k) return true;

        }
    }
    return false;
}

struct Node
{
    TNODE* p;
    Node* next;
    Node(TNODE* p) {this->p=p; this->next=nullptr;}
};

struct queue
{
    Node* head, *tail;
    queue(){head=tail=nullptr;}
    void push(TNODE* p)
     {
        Node*tmp=new Node(p);
        if(!tmp) exit(1);
        if(!head) head=tmp;
        else tail->next=tmp;
        tail=tmp;
     }
    void pop()
    {
        Node* tmp;
        tmp=head;
        head=head->next;
        if(head==nullptr) tail=nullptr;
        delete  tmp;
    }
    TREE top()
    {
        return head->p;
    }
    bool isEmpty(){if(head==nullptr) return true; return false;}
};

void Function(TREE t)
{
if(t)
    {
        TREE origin=t; int k; cin>>k;
        if(k>max_height(t)||k<0) {cout<<"Khong co node o muc "<<k; return;}

    queue *q= new queue();
    q->push(t);
    cout<<"Xuat cac node o muc "<<k<<":\n";
    while(!q->isEmpty())
     {
        t=q->top(); q->pop();
        if(t->pLeft) q->push(t->pLeft);
        if(t->pRight) q->push(t->pRight);
        if(check_level(origin, t, k)) cout<<t->key<<" ";
     }
    }
else cout<<"Empty Tree.";
}

int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}