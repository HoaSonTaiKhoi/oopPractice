 #include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head=NULL;
    Node* tail=NULL;
};

struct Graph
{
    int v; // số đỉnh của đồ thị 
    List* arr; //mảng của các danh sách
};

Node* CreateNode(int x)
{
    Node* p=new Node;
    if(!p) exit(1);
    p->info=x;
    p->next=nullptr;
    return p;
}
void insert(List& L, int x)
{
    Node* p= CreateNode(x);
    if(L.head==nullptr) L.head=p;
    else L.tail->next=p;
    L.tail=p;
}

void Input(Graph &G, int e)
{
    int a,b;
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        insert(G.arr[a], b);
    }
    int k; cin>>k;

    int bt=0, bn=0;
    if(k<0||k>=G.v) {cout<<"No find"; return;}

    Node* p=G.arr[k].head;
     while(p)
     {
        bn+=1;
        p=p->next;
     }
    for(int i=0; i<G.v; i++)
    {
        if(i!=k)
        {
          Node* e=G.arr[i].head;
         while(e)
          {
            if(e->info==k) bt++;
            e=e->next;
          }
        }
        else continue;
    }
    cout<<"Nua bac ngoai: "<<bn<<"\n";
    cout<<"Nua bac trong: "<<bt;
}
int main()
{
    int e,v;
    cin>>e>>v;
    Graph G;
    G.v=v;
    G.arr = new List[v];
    Input(G,e);

    return 0;
}