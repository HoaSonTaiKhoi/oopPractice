
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


void get_ans(const vector<int>& A,int K){
	map<int,int> Hash;

    // vector<int> b;
    //     for(int i=0; i<A.size(); i++)
    //     {
    //         Hash[A[i]]+=1;
    //     }
    // map<int,int> ::iterator i=Hash.begin();

    // while(K>0&& i!=Hash.end())
    // {
    //     b.push_back(i->first);
    //     i->second-=1;
    //     K--;
    //     i++;
    // }
    // i=Hash.begin();
    // while(K>0 && i!=Hash.end())
    //  {
    //     if(i->second>0)
    //     {
    //         b.push_back(i->first);
    //         i->second-=1;
    //         K--;
    //     }
    //     else i++;
    //  }
    // sort(b.begin(), b.end());


    map<int, int> temp;
    vector<int> b;
        for(int i=0; i<A.size(); i++)
        {
            Hash[A[i]]+=1;
        }
    map<int,int> ::iterator i=Hash.begin();

    while(K>0&& i!=Hash.end())
    {
        temp[i->first]+=1;
        i->second-=1;
        K--;
        i++;
    }
   
   
    map<int,int> ::iterator j=Hash.begin();
    while(K>0 && j!=Hash.end())
    {
        if(j->second>0)
        {
            temp[j->first]+=1;
            j->second-=1;
            K--;
        }
        else j++;
    }


    for(map<int,int>::iterator e=temp.begin(); e!=temp.end(); e++)
    {
        while(e->second>0)
        {
            b.push_back(e->first);
            e->second-=1;
        }
    }

    for (const int& x: b) cout << x << ' ';


    // return b;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	// vector<int> ans = 
    get_ans(a,k);
	
	// for (const int& x: ans) cout << x << ' ';
	return 0;
}
