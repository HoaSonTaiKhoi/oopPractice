//quick sort


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

void quickSort(vector<int>&a, int l, int r)
{
    if(l>=r) return;
    int x=a[(l+r)/2], i=l, j=r;
    cout<<"["<<l<<" - "<<r<<"]: ";
    while(i<j)
    {
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j) {swap(a[i], a[j]); i++; j--;}
    }
    for(int e=l; e<=r; e++) cout<<a[e]<<"\t";
    cout<<endl;
    quickSort(a, l, j);
    quickSort(a, i, r);
}
void Sort(vector<int> &a)
{
    int n=a.size();
    quickSort(a, 0, n-1);  
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);

	return 0;
}
