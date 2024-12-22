
#include<bits/stdc++.h>
using namespace std;

string ltrim(const string &str) {
    string s(str);

    
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );// đọc từ đầu chuỗi đến thành phần khác isspace đầu tieen

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}


int main()
{
    string n_temp, ar_temp;
    getline(cin, n_temp);
    getline(cin, ar_temp);

    int n=stoi(ltrim(rtrim(n_temp)));
    vector<string> str=split(rtrim(ar_temp));

    vector<long> ar(n);
    for(int i=0; i<str.size(); i++)
    {
        long tmp=stol(str[i]);
        ar[i]=tmp;
    }

    for(auto x:ar) cout<<x<<" ";

cout<<"\n"<<n;
return 0;
}