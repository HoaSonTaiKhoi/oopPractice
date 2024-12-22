// DÃY ĐẸP
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<string.h>

using namespace std;

int main()
{
    int *a, n, step=0;
    cin>>n; a=new int[n];

    for(int i=0; i<n; i++) cin>>a[i];

    map<int, int> day;

    for(int i=0; i<n; i++) 
    {
        day[a[i]]=0;
    }
    for(int i=0; i<n ;i++)
    {
        day[a[i]]+=1;
    }

    for(int i=0; i<n; i++)
    {
        if(day[a[i]]==a[i]) continue;
        if(day[a[i]]>a[i])
        {while(day[a[i]]>a[i]) {step++; day[a[i]]--;}}
        else if(day[a[i]]<a[i]) while(day[a[i]]>0) {step++; day[a[i]]--;} 
    }
    cout<<step;
}