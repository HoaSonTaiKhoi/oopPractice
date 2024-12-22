#include<bits/stdc++.h>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>>a;
int row, col;
int i,j;
int min=100000000;
int temp;
int main()
{
    std::cin>>row>>col;
    a.resize(row, std::vector<int>(col, 0));
    for(i=0; i<row; i++)
     {
        for(j=0; j<col;j++)
        std::cin>>a.at(i).at(j);
     }
    for(i=0;i<row-2; i++)
    {
        for(j=0; j<col-2; j++)
        {
            temp=0;
            temp+=a.at(i).at(j)+a.at(i).at(j+1)+a.at(i).at(j+2)+a.at(i+1).at(j)+a.at(i+1).at(j+1)+a.at(i+1).at(j+2)+a.at(i+2).at(j)+a.at(i+2).at(j+1)+a.at(i+2).at(j+2);
            if(temp<min) min=temp;
        }
    }
    std::cout<<min;
return 0;
}