
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<stack>


int n, m,a, b, x,p , i;
std::set<int>::iterator e;
std::set<int> ans;
std::stack<int>open;

int main()
{
    std::cin>>n>>m;
    std::vector<bool>close(n+1, 0);
    std::vector<std::vector<int>> G(n+1, std::vector<int> (n+1, 0));

    for(i=0; i< m; i++)
    {
         std::cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }

    std::cin>>x;
    open.push(x);
    ans.insert(x);
    close[x]=1;
    for(int i=0; i<n+1; i++)
    {
        if(G[i][p]==1) {close[i]=1; ans.insert(i);}
    }
    while(!open.empty())
    {
        p=open.top(); open.pop();

        for(i=0; i<n+1; i++)
        {
            if(G[p][i]==1 && close[i]==0)
            {
                G[p][i]=0;
                open.push(i);
                ans.insert(i);
            }
        }
    }

    std::cout<<ans.size()<<"\n";
    for(e=ans.begin(); e!=ans.end(); e++) std::cout<<*e<<" ";
return 0;
}