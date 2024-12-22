
#include "bits/stdc++.h"
#include<fstream>
using namespace std;

class String
{
    private:
     queue<char> a;
     stack<char> b;
    public:
     String();
     ~String();
     friend istream& operator >>(istream &in, String&s);
     friend ostream& operator <<(ostream &out, String s);
     
     void reverse();
     inline int size();
     void erase();
     
     friend String& operator + (String &s, String s1);
     friend String& operator +(String& s, char c);
     
     friend bool operator== (String s,String s1);
     String& operator = (string s);
     String& operator = (String s);
     String& operator = (char c);

     char operator[](int index);
     friend class file;
};

String::String(){}

String::~String()
    {
    while(!a.empty()) a.pop();
    while(!b.empty()) b.pop();
    }

istream& operator >>(istream &in, String &s)
{
    char x;
        if(!s.a.empty()) while(!s.a.empty()) s.a.pop();
        while(true)
        {
            x=getchar();
            if(x=='\n') break;
            s.a.push(x);
            s.b.push(x);
        }
        return in;
}

ostream &operator<<(ostream &out, String s)
{
    while(!s.a.empty())
        {
            out<<s.a.front(); 
            s.a.pop();
        }
        return out;
}

void String::reverse()
{
    while(!a.empty()) a.pop();
    while(!b.empty()) {a.push(b.top()); b.pop();}
        queue<char> d=a;
    while(!d.empty()) {b.push(d.front()); d.pop();}
}

inline int String::size()
{
    int n=0;
        queue<char> c=a;
        while(!c.empty())
        {
            n++;
            c.pop();
        }
    return n;
}

String& operator+(String &s, String s1)
{
    while(!s1.a.empty())
        {
            s.a.push(s1.a.front());
            s.b.push(s1.a.front());
            s1.a.pop();
        }
    return s;
}


String &operator+(String &s, char c)
{
   if(c!='.'&& c!='?' && c!='!')
   {
    s.a.push(c);
   }
   return s;
}

bool operator==(String s, String s1)
{
    if(s.size()!=s1.size()) return false;
    else
    {
        queue<char> a =s.a;
        queue<char> a1=s1.a;
        while(!a.empty())
        {
            if(a.front()==a1.front()){a.pop(); a1.pop();}
            else return false;
        }
        if(a.empty()&& a1.empty()) return true;
    }
    return false;
}


void String::erase()
{
    while(!a.empty()) a.pop();
}

String &String::operator=(string s)
{
    while(!a.empty()) a.pop();
    for(int i=0; i<s.size(); i++) a.push(s[i]);
    return *this;
}

String &String::operator=(String s)
{
    while(!a.empty()) a.pop();
    while(!s.a.empty()) {a.push(s.a.front()); s.a.pop();}
    return *this;
}

String &String::operator=(char c)
{
    this->a.push(c);
    return *this;
}

char String::operator[](int index)
{
    queue<char>d=a;
    while(index>0)
    {
        index--;
        d.pop();
    }
    return d.front();
}

class file
{
    private:
     vector<pair<String, int>> c;
     vector<String> d;
     vector<int> cw;
     vector<String> w;
    public:
    string file_output;
     file(string file_input, string file_output)
     {
        this->file_output=file_output;
        string tmp; String sen;
        ifstream input(file_input);
        if(input) 
        {
            while(!input.eof())
            {
                input>>tmp;
                if(tmp[0]==' ') tmp.erase(tmp.begin());

                if(tmp[tmp.size()-1]=='\n') tmp.resize(tmp.size()-1);

                String temp; temp=tmp; string dis=" "; String dist; dist=dis;
                 if(tmp[tmp.size()-1]!='.'&& tmp[tmp.size()-1]!='?'&& tmp[tmp.size()-1]!='!'&& tmp[tmp.size()-1]!='\n') { sen=sen+temp;sen=sen+dist;}
                 else
                 {
                    sen=sen+dist;
                    sen=sen+temp;
                    d.push_back(sen);
                    sen.erase();
                 }
                 if(d[d.size()-1].a.front()==' ') d[d.size()-1].a.pop();
            }
        }
        input.close();
     }
     
     void Xuat()
     {
        for(int i=0; i<d.size();i++)
        cout<<d[i]<<"\n";
     }

     int get_size()
     {
        return d.size();
     }


     void word_per_sen()
     {
        int temp=0;
        for(int i=0; i<d.size(); i++)
        {
            for(int j=0; j<d[i].size(); j++)
            {
                if(d[i][j]==' ') temp++;
            }
            cw.push_back(temp);
            temp=0;
        }
        for(int i=0; i<cw.size();i++) cout<<cw[i]<<"\n";
     }


     void word_max_count()
     {
        for(int i=0; i< d.size(); i++)
        {
            String t, temp;
            t=d[i];
             for(int j=0; j<t.size(); j++)
             {
                if(t[j]!=' ' && t[j]!='.' && t[j]!='?' && t[j]!='!' &&t[j]!=',' ) temp=temp+t[j];
                if(t[j]==' '||t[j]=='.' || t[j]=='?' || t[j]=='!'||t[j]==',')
                {
                    w.push_back(temp);
                    temp.erase();
                    if(t[j+1]==' ') j++;
                }
             }
        }
        vector<String> ww=w;
        while (!ww.empty())
        {
            String t; t=ww[0];
            c.push_back({t,1});
            ww.erase(ww.begin());
            for(int j=0; j<ww.size(); j++)
            {
                 if(ww[j]==t)
                 {
                    c[c.size()-1].second++;
                    ww.erase(ww.begin()+j);
                    j-=1;
                 }
            }
        }
        int max=0;
        for(int i=0; i<c.size(); i++) if(c[i].second>max) max=c[i].second;
        for(int i=0; i<c.size(); i++) if(c[i].second==max) cout<<c[i].first<<" "<<c[i].second<<"\n";
     }

    int tang(String s, String s1)
    {
        while(!s.a.empty()&&!s1.a.empty())
        {
            char c1=tolower(s.a.front()), c2=tolower(s1.a.front());
            if(c1>c2) return 1;
            else if(c1< c2) return -1;
            else {s.a.pop(); s1.a.pop();}
        }
        if(!s.a.empty()&&s1.a.empty()) return 1;
        else if(s.a.empty()&&! s1.a.empty()) return -1;
        else return 0;
    }

    void sortAZ(vector<String> &w, int t, int n)
    {
        int min;
        for(int i=t; i<n-1; i++)
        {
            min=i;
            for(int j=i+1;j<n; j++)
            {
                if(tang(w[min], w[j])==1) min=j;
            }
            String temp;
            temp=w[min];
            w[min]=w[i];
            w[i]=temp;
        }
    }
    
    void sort_word_per_sen()
    {
        int m=0;
        for(int i=0; i<cw.size(); i++)
        {
            sortAZ(w, m,m+cw[i]);
            m+=cw[i];
        }
    }
    ~file()
    {
        ofstream out (file_output, std::ofstream::out | std::ofstream::trunc);
        if(out)
        {
            out<<this->get_size()<<endl;
            for(int i=0; i<cw.size(); i++)
            {
                out<<"So tu o cau "<<i+1<<" la: "<<cw[i]<<endl;
            }
        
        out<<"Cac tu xuat hien nhieu nhat: ";
        int max=0;
        for(int i=0; i<c.size(); i++) if(c[i].second>max) max=c[i].second;
        for(int i=0; i<c.size(); i++) if(c[i].second==max) out<<c[i].first<<" "<<c[i].second<<endl;
        

        sort_word_per_sen();
        int m=0;
        for(int i=0; i<cw.size(); i++)
        {
            for(int j=m; j<m+cw[i]-1; j++) out<<w[j]<<" ";
            out<<w[cw[i]+m-1]<<". ";
            m=cw[i];
        }
        }
        out.close();
    }

};


main(int argc,  char **argv)
{
    string file_input(argv[1]);
    string file_output(argv[2]);
    file f(file_input, file_output);
    f.Xuat();
    cout<<f.get_size()<<"\n";
    f.word_per_sen();
    f.word_max_count();
    //f.sort_word_per_sen();
return 0;
}

//./main tc1_input
//g++ -g -o main wow.cpp -I . -std=c++11