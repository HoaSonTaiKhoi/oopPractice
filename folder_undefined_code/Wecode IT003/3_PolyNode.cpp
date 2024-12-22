    // //Poly Node

    // #include<bits/stdc++.h>
    // #include<conio.h>
    // #include<math.h>
    // using namespace std;

    // class Node
    // {
    //     public: 
    //     double x; int y;
    //     Node* next;
    //     Node(double x, int y)
    //     {
    //     this->x=x;
    //     this->y=y;
    //     this->next=nullptr;
    //     }
    // };
    // int n;
    // double t1;int t2;
    // class List
    // {
    //     public:
    //     Node* head;
    //     Node*tail;
    //     List()
    //     {
    //         this->head=nullptr;
    //         this->tail=nullptr;
    //     }

    //     void Nhap()
    //     {
    //         cin>>n;
    //         for(int i=0; i<n; i++)
    //         {
    //             cin>>t1>>t2;
    //             Node*p=new Node(t1, t2);
    //             if(head==nullptr) head=p;
    //             else tail->next=p;
    //             tail=p;
    //         }
    //     }
    //     bool check()
    //     {
    //         Node*p=head;
    //         while(p!=nullptr) 
    //         {if(p->x!=0) return true; p=p->next;}
    //     return false;
    //     }
    //     void Outpoly()
    //     {
    //         Node* p=head;
    //         cout<<"Da thuc vua nhap la: ";
    //     if(check()==1)
    //     {
    //         while(p!=nullptr)
    //         {
    //             if(p->y==0)
    //             {
    //                 if(p==head&&p->x!=0)
    //                 {
    //                     cout<<p->x;
    //                 }
    //                 else if(p->x!=0)
    //                 {
    //                     if(p->x>0) cout<<"+"<<p->x;
    //                     else cout<<p->x;
    //                 }
    //             }
    //             else if(p->y==1)
    //             {
    //                 if(p==head&& p->x!=0)
    //                 {
    //                     if(p->x==1) cout<<"x";
    //                     else if(p->x==-1) cout<<"-x";
    //                     else cout<<p->x<<"x";
    //                 }
    //                 else if(p->x!=0)
    //                 {
    //                     if(p->x==1) cout<<"+x";
    //                     else if(p->x==-1) cout<<"-x";
    //                     else if(p->x>0) cout<<"+"<<p->x<<"x";
    //                     else cout<<p->x<<"x";
    //                 }
    //             }
    //             else
    //             {
    //                 if(p==head&& p->x!=0)
    //                 {
    //                     if(p->x==1) cout<<"x";
    //                     else if(p->x==-1) cout<<"-x";
    //                     else cout<<p->x<<"x";
    //                     cout<<"^"<<p->y;
    //                 }
    //                 else if(p->x!=0)
    //                 {
    //                     if(p->x==1) cout<<"+x";
    //                     else if(p->x==-1) cout<<"-x";
    //                     else if(p->x>0) cout<<"+"<<p->x<<"x";
    //                     else cout<<p->x<<"x";
    //                     cout<<"^"<<p->y;
    //                 }
                    
    //             }
    //         p=p->next;
    //         }
    //     }
    //     else cout<<0;
    //     }

    //     void f_x(double x)
    //     {
    //         double sum;
    //         Node*p= head;
    //         while(p!=nullptr)
    //         {
    //         sum+=p->x*pow(x, p->y);
    //         p=p->next;
    //         }
    //         cout<<"Voi x="<<x<<", gia tri da thuc la: "<<setprecision(2)<<fixed<<sum;
    //     }
    // };

    // int main()
    // {
    //     List L;
    //     L.Nhap();
    //     double x; cin>>x;
    //     L.Outpoly();
    //     cout<<"\n";
    //     L.f_x(x);
    // return 0;
    // }


#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};

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


int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "<<fixed<< setprecision(2) << TinhDaThuc(B, x);
    return 0;
}

// int hs=chs(B.a[i]);
//     	int ms=cms(B.b[i]);
// 		if(i==k) 
// 		 {
// 		    if(B.a[i]==1)
// 			{
				
// 		   	  if (ms==0 ) cout<<"1";
// 		      else if(ms==1) cout<<"x";
// 		   	  else cout<<"x^"<<B.b[i];
// 			}
// 			else if (B.a[i]==-1)
// 			{
// 				if (ms==0 ) cout<<"-1";
// 		      else if(ms==1) cout<<"-x";
// 		   	  else cout<<"-x^"<<B.b[i];
// 			}
// 		   else if(B.a[i]!=0)
// 		   {
// 		   	 if (ms==0 ) cout<<B.a[i];
// 		   	else if(ms==1) cout<<B.a[i]<<"x";
// 		   	else cout<<B.a[i]<<"x^"<<B.b[i];
// 		   }
// 		 }
		
// 		if(hs !=0&& i!=k)
		
// 		{
// 			if(B.a[i]==1)
// 			{
				
// 		   	  if (ms==0 ) cout<<"+1";
// 		      else if(ms==1) cout<<"+x";
// 		   	  else cout<<"+x^"<<B.b[i];
// 			}
// 			else if (B.a[i]==-1)
// 			{
// 				if (ms==0 ) cout<<"-1";
// 		      else if(ms==1) cout<<"-x";
// 		   	  else cout<<"-x^"<<B.b[i];
// 			}
// 			else if(B.a[i]>1)
// 			{
// 				if (ms==0 ) cout<<"+"<<B.a[i];
// 		      else if(ms==1) cout<<"+"<<B.a[i]<<"x";
// 		   	  else cout<<"+"<<B.a[i]<<"x^"<<B.b[i];
// 			}
// 			else if(B.a[i]<-1)
// 			{
// 					if (ms==0 ) cout<<B.a[i];
// 		      else if(ms==1) cout<<B.a[i]<<"x";
// 		   	  else cout<<B.a[i]<<"x^"<<B.b[i];
// 			}	
// 		}
// 	}