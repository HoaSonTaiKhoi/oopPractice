//bstree01


#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};
typedef TNODE* TREE;

TNODE* CrNode(int x)
{
    TNODE* p=new TNODE;
    if(!p) exit(1);
    p->key=x;
    p->pLeft=nullptr;
    p->pRight=nullptr;
return p;
}

inline void insertnode(TREE &T, int x)
{
    TNODE*p=CrNode(x);
     if(!p) exit(1);
    if(!T) T=p;
    else
    {
        TNODE* tmp=T;
        while(tmp)
        {
            if(tmp->key==x) break;
            else if(tmp->key>x) 
            {
                if(!tmp->pLeft) {tmp->pLeft=p; break;}
                tmp=tmp->pLeft;
            }
            else
            {
                if(!tmp->pRight) {tmp->pRight=p; break;}
                tmp=tmp->pRight;
            }
        }
    }
}
void CreateTree(TREE &T){
    T=nullptr;

    int x;
    while(cin>>x&&x!=-1)
    {
        insertnode(T, x);
    }
}

TREE check(TREE t, int x)
{
    while(t)
    {
        if(t->key==x)  return t;
            else if(t->key>x) t=t->pLeft;
            else              t=t->pRight;
    }
    return nullptr;
}
void Function(TREE t)
{
    int x; cin>>x;
    TNODE* p=check(t, x);
    if(p)
    {
        if(p==t) cout<<"Root no ancestor";
        else
        {
            TNODE* tmp=t;
            while(tmp!=p)
            {
                cout<<tmp->key<<" ";
                if(tmp->key>x) tmp=tmp->pLeft;
                else if(tmp->key<x) tmp=tmp->pRight;
            }
        }
    }
    else cout<<"No Find";
    return;
}

int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}