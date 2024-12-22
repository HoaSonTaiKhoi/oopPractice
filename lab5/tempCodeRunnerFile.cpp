
#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;


vector<int> get_ans(const vector<int>& A,int K){
	map<int,int> Hash;
        for(int i=0; i<A.size(); i++)
        {
            Hash[A[i]]=1;
        }
    map<int,int> ::iterator i;
    for(i = Hash.begin(); i!=Hash.end(); i++)
    {
        cout<<i->first<<" "<<i->second<<"\n";
    }
}

int main(){
	ios::sync_with_stdio(false); cin.tie(nullptr);
	
	cin >> n >> k;
	
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	
	vector<int> ans = get_ans(a,k);
	
	for (const int& x: ans) cout << x << ' ';
	return 0;
}
