
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

    for(int i=0; i<G.v; i++)
    {
        cout<<i<<": {";
        Node* p= G.arr[i].head;
        while(p!=nullptr)
        {
            cout<<p->info;
            if(p->next!=nullptr) cout<<", ";
            p=p->next;
        }
        cout<<"}\n";
    }
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