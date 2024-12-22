#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
int binarySearch(vector<int> &v, int k)
{
     int l=0;int r=v.size()-1;
     sort(v.begin(), v.end());
    while(l<=r)
    {
        int m=(l+r)/2;
        if(v[m]==k) return m;
        else if(k>v[m]) l=m+1;
        else r=m-1;
    }
    return -1;
}
main()
{
    ifstream in("filemangdong.txt");
    vector<int> v;
    while(true)
    {
        string sub;
        in>>sub;
        if(sub==""||sub=="\n"||sub=="\r"||sub=="\0") break;
        v.push_back(atoi(sub.c_str()));
    }
    in.close();
    sort(v.begin(), v.end());
    int k;
    cin>>k;
    cout<<binarySearch(v, k);
return 0;
}
