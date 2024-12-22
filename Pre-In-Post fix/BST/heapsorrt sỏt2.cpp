
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

void Input(vector<int> &v)
{
	int tmp;
	cin >> tmp;
	while (tmp >= 0) {
		v.push_back(tmp);
		cin >> tmp;
	}
}

int heapify(vector<int> &a, int k, int n)
{
    int count=0, j=2*k+1;
    while(j<n)
    {
        if(j+1<n) if(a[j]<a[j+1]) j=j+1;
        if(a[k]>=a[j]) break;
        swap(a[k],a[j]); count++;
        k=j; j=2*k+1;
    }
    return count;
}

void buildheap(vector<int> &a, int n)
{
    cout<<"N="<<n<<":  "; for(int i=0; i<n; i++) cout<<a[i]<<"  ";
    int count=0, i=(n-1)/2;
    while(i>=0)
    {
        count+=heapify(a, i, n);
        i--;
    }
    cout<<"\nswap: "<<count<<"\n";    
}

void Sort(vector<int> a)
{
    int n,m, count =0;
    n=m=a.size();
    // if(n==0)
    // {
    //     cout<<"N="<<0<<":\n"
    //         <<"swap: "<<0;
    //     return;
    // }
    buildheap(a, m);

    while(m>0)
    {
        m--;
        swap(a[0], a[m]);
        
        cout<<"N="<<m<<":  "; for(int i=0; i<n; i++) cout<<a[i]<<"  ";
            
        
        count=heapify(a, 0, m);

        cout<<"\nswap: "<<count<<"\n";
        if(m==1&&count==0) break;
    }
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
