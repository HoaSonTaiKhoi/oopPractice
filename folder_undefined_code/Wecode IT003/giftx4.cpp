#include <iostream>
#include <vector>
#include <algorithm>

int n,x, tmp;
int m=-1;
int i, j, l, r;

std::vector<int> a,b, ans;
int main() {
    int index[4];
    std::cin >> n>>x;
    for (int i = 0; i < n; i++) {
        std::cin >> tmp;
        a.push_back(tmp);
    }
    b=a;

    std::sort(a.begin(), a.end());
    
    for (i = 0; i < n - 3; i++) {
        int sum;
        for (j = i + 1; j < n - 2; j++) {
            l = j + 1;
            r = n - 1;
            
            while (l < r) {
                 sum = a[i] + a[j] + a[l] + a[r];
                if (sum <= x && sum > m) {
                    m = sum;
                    index[0]=i; index[1]=j; index[2]=l; index[3]=r;
                }
                if (sum >= x) r--;
                else l++;
            }
        }
        if(sum==x) break;
    }
    if (m == -1)
        std::cout << "Impossible";
    else {
        std::cout<<m<<"\n";
           for(int e=0; e<n; e++)
           {
            if(a[index[0]]==b[e]) ans.push_back(e+1);
            if(a[index[1]]==b[e]) ans.push_back(e+1);
            if(a[index[2]]==b[e]) ans.push_back(e+1);
            if(a[index[3]]==b[e]) ans.push_back(e+1);
           }
        
        std::sort(ans.begin(), ans.end());
        for (int i = 0; i < 4; i++)
            std::cout << ans[i] << " ";
    }
    return 0;
}