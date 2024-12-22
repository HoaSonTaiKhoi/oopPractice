// Latex

#include<bits/stdc++.h>

using namespace std;

class Node
{
    public:
    char info;
     Node* next;
    public:
     Node(char x)
     {
        this->info=x;
        this->next=nullptr;
     }
};


struct Stack
{
   Node* stack=nullptr;
   void push(char x)
   {
     Node*p=new Node(x);
     p->next=stack;
     stack=p;

   }
   void pop()
   {
    if(stack==nullptr) return;
     Node* temp=stack;
     stack=stack->next;
     delete temp;
   }
   char Top()
   {
    return stack->info;
   }
   void Duyet()
   {
    Node *p= stack;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->next;
    }
   }
};


bool Latex(string s, Stack st)
{
   for(int i=0; i<s.size(); i++)
   {
      if(s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
      else
      {
         if((s[i]==')'||s[i]==']'||s[i]=='}')&& st.stack==nullptr) return false;
         else if(s[i]==')'||s[i]==']'||s[i]=='}')
         {
            if(s[i]==')'&& st.Top()=='(') st.pop();
            else if(s[i]==']'&&st.Top()=='[') st.pop();
            else if(s[i]=='}'&& st.Top()=='{') st.pop();
            else st.push(s[i]);
         }
      }
   }
   if(st.stack==nullptr) return true;
   return false;
}

int main()
{
    Stack st;
    string s;
    getline(cin, s);
    cout<<Latex(s, st);
return 0;
}