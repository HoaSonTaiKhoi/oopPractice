//insertion sort


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

void Sort(vector<int> &a)
{
    int n=a.size(), i=1;
    while(i<n)
    {
        int e=a[i], k=i-1;
        cout<<"i="<<i<<": pos="<<e<<" e=";
        while(k>=0&& e>=a[k])
        {
            a[k+1]=a[k];
            k--;
        }
        
        a[k+1]=e;
        cout<<k+1<<"\n";
        i++;
    }
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
