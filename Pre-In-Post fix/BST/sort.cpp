
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
    int n=a.size();
    for(int i=0; i<n-1; i++)
    {
        cout<<"i="<<i<<": ";
        int j=-1, min=i;
        for(j=i+1; j<n; j++)
            {if(a[min]<a[j]) min=j;}
        swap(a[i], a[min]);
        cout<<"swap ("<<a[min]<<"-"<<a[i]<<")";
        cout<<endl;
    }
}

int main() {
	vector<int> A;
	Input(A);
	Sort(A);
	return 0;
}
