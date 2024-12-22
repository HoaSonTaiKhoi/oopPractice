
#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE; 

void CreateTree(TREE &t)
{
    t=NULL;
}
TNODE* CreateNode(int x) {
    TNODE *p = new TNODE; 
    if (p == NULL)
    exit(1);
    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Add_1(TREE &T, int x) 
{
    if (T) 
    {
    if (T->key == x) return 0;
    if (T->key > x)

    return Add_1(T->pLeft, x);

    return Add_1(T->pRight, x);
    }
    T = CreateNode(x);
    return 1;
}
void Add_n(TREE &t)
{
    t=NULL;
    int x;
    while(true)
    {
        cin>>x;
        if (x==-1) break;
        Add_1(t,x);
    }  
}

TNODE * binarysearch(TREE t,int x)
{
    if(t!=NULL)
    {
        if(t->key==x) return t;
        if(t->key>x) return binarysearch(t->pLeft, x);
        return binarysearch(t->pRight,x);
    }
    return NULL;
}

void inorder(TREE T, int x)
{
    if(T)
    {
        inorder(T->pLeft, x);
        if(T->key!=x) cout<<T->key<<" ";
        inorder(T->pRight, x);
    }
    return;
}
void Function(TREE &T)
{
    Add_n(T);
    int x; cin>>x;
    if(binarysearch(T,x)==NULL) {cout<<"No Find"; return;}
    TNODE*p=binarysearch(T,x);
    if(p->pLeft==nullptr&&p->pRight==nullptr) {cout<<"No descendant"; return;}
    else
    {
        inorder(p, x);
    }
}
int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}