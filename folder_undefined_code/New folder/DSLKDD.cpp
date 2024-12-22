#include<bits/stdc++.h>
#include<algorithm>
#include<time.h>

std::clock_t start, end;
double time_use;
int n;


class Node
{
    public:
     int value;
     Node* next;
    public:
     Node(int x)
     {
        this->value=x;
        this->next=NULL;
     }
};

class List
{
    private:
     Node* head;
     Node* tail;
    public: 
      List()
      {
        head=NULL;
        tail=NULL;
      }
    void AddNode(int x)
    {
        Node* node= new Node(x);
        if(head==NULL) head=node;
        else tail->next=node;
        tail=node;
    }
    void CoutList()
    {
        Node*node=head;
        while(node!=NULL)
        {
            std::cout<<node->value<<" ";
            node=node->next;
        }
    }
    void NhapList()
    {
        std::cin>>n;
        for(int i=0; i< n; i++)
        {
            int x; std::cin>>x;
            AddNode(x);
        }
    }

    void SelectionSort()
    {
        Node* node=head;
        while(node!=tail)
        {
            Node* min=node;
            Node* nodej=node->next;
            while(nodej!=NULL)
            {
                if(min->value>nodej->value) min=nodej;
                nodej=nodej->next;
            }
            std::swap(min->value, node->value);
            node=node->next;
        }
    }
    Node* Remove(Node * node, Node* node1)
    {
        node->next=node1->next;
        node1->next=NULL;
    return node1;
    }

    
    void Add(Node* node, Node* node1)
    {
        node1->next=node->next;
        node->next=node1;
    }
    void Addhead(Node * e)
    {
        e->next=head;
        head=e;
    }
    void InsertSort()
    {
        Node* node=head;
        while(node->next !=NULL)
        {
             Node*e=Remove(node, node->next);
             Node* d=head, *temp=new Node(0); temp=NULL;
             while(d!=node->next)
             {
                if(d->value>=e->value) std::cout<<"true";
                temp=d;
                d=d->next;
             }
             if(temp==NULL) Addhead(e);
             else Add(temp, e);
             if (node->next == e) node=node->next;
        }
    }



    /*void Add11()
    {
        Node* p=new Node(11);
        Add(tail, p);
    }
    void Removehead()
    {
        Node* p=Remove(head, head->next);
        std::cout<<"!"<<p->value<<"! ";
    }*/
};

void Nhap(std::vector<int> &a)
{
    std::cin>>n;
    for(int i=0; i<n ;i++)
    {
        int temp; std::cin>>temp;
        a.push_back(temp);
    }
}

void Cout(std::vector<int> a)
{
    for(auto x: a)
    std::cout<<x<<" ";
}
void SelectionSort(std::vector<int> &a)
{
    
    int i=0;
    int min,j;
    while(i< n-1)
    {
        min=i; j=i+1;
        while (j<n) { if(a[j]< a[min]) min=j; j++;}
        std::swap(a[min], a[i]);
        i++;
    }
}
void InsertionSort(std::vector<int> &a)
{
     int i=0;
     int k;
     while(i<n-1)
     {
        int e=a[i+1];
        k=i;
        while(k>0 && a[k]>=e)
        {
            a[k+1]=a[k];
            k--;
        }
       a[k+1]=e;
       i++;
     }
}


int main()
{ 
    
    //std::vector<int> a;
    List L=List();
    L.NhapList();
    //Nhap(a);
    //start =clock();
    L.InsertSort();
    L.CoutList();
    //SelectionSort(a);
    //Cout(a);
    //end=clock();
    //time_use=(double)(end-start)/CLOCKS_PER_SEC;
    //std::cout<<"\n"<<time_use;
return 0;
}