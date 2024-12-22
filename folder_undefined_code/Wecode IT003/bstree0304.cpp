//bstree03


#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE; 

TREE newNode(int x)
{
    TREE p= new TNODE;
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
        else if(t->key>x) return insertnode(t->pLeft,x);
        else return insertnode(t->pRight, x);
    }
    else t=newNode(x);
return;
}
void CreateTree(TREE &t)
{
    t= nullptr; int x;
    while(cin>>x && x!=-1)
    {
        insertnode(t, x);
    }
}

TREE binarysearch(TREE t, int x)
{
    if(t)
    {
        if(t->key==x) return t;
        if(t->key>x) return binarysearch(t->pLeft, x);
        else return binarysearch(t->pRight, x);
    }
    return nullptr;
}

int max_left(TREE t)
{
    t=t->pLeft;
    while(t->pRight) t=t->pRight;
    return t->key;
}

int min_right(TREE t)
{
    t=t->pRight;
    while(t->pLeft) t=t->pLeft;
    return t->key;
}
void Function(TREE t)
{
    int x; cin>>x;
    TREE p=binarysearch(t, x);
    if(p)
    {
        if(p->pLeft&&p->pRight) cout<<min_right(p);
        else cout<<"No Node 2";
    }
    else cout<<"No Find";

}


int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}

