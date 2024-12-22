void Nhap(DATHUC &B, double x, int y)
{
    DONTHUC *d=new DONTHUC(x, y);
    Node*p= new Node(d);
    if(B.head==nullptr) B.head=p;
    else B.tail->next=p;
    B.tail=p;
}

bool check_0(DATHUC B)
{
    Node*p=B.head;
    while(p!=nullptr)
    {
        if(p->data->heso!=0) return true;
        p=p->next;
    }
    return false;
}

void Xuat(DATHUC B)
{
   Node* p=B.head, *p1=B.head;
   if(check_0(B)==0) {cout<<0; return;}   
   else
   {
     while(p->data->heso==0) p=p->next;
     p1=p;
     while(p!=nullptr)
     {
        double x=p->data->heso;
        int y=p->data->somu;
       if(y==0)
       {
         if(x!=0&&p==p1)
         {
            cout<<x;
         }
         else if(x!=0)
         {
            if(x==1) cout<<"+1";
            else if(x>0) cout<<"+"<<x;
            else cout<<x;
         }
       }
       else if(y>=1&&x!=0)
       {
         if(p==p1)
         {
            if(x==1) {}
            else if(x==-1) cout<<"-";
            else cout<<x;
         }
         else
         {
            if(x==1) cout<<"+";
            else if(x==-1) cout<<"-";
            else if(x>0) cout<<"+"<<x;
            else cout<<x;
         }
         if(y==1) cout<<"x";
         else cout<<"x^"<<y;
       }
        p=p->next;
     }
   }
}

double TinhDaThuc(DATHUC B, double x)
{
    double value=0;
    Node*p=B.head;
    while(p!=nullptr)
    {
        value+=p->data->heso*pow(x, p->data->somu);
        p=p->next;
    }
    return value;
}