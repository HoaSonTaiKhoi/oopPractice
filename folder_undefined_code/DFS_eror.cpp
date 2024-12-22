// dfs

#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<char,int> p1, pair<char,int> p2) {
	return p1.second < p2.second;
}

void nhap(int v, map<char, int> &index, int e, vector< vector<int> > &G) {
	char str;
	for(int i = 0; i < v; i++) {
		cin >> str;
		index[str] = i;
	}
	char s1,s2;
	int a, b;
	map<char, int>::iterator it;
	while(e--) {
		cin >> s1 >> s2;
		it = index.find(s1);
		a = it->second;
		it = index.find(s2);
		b = it->second;
		G[a][b] = 1;
	}
}

int in(vector< vector<int> > G, int v, int X, int Y) {
	if(G[Y][X] != 0) {
		return Y;
	}
	for(int index = v-1; index >= 0; index--) {
		if(G[index][X] != 0) {
			G[index][X] = 0;
			return index;
		}
	}
	return -1;
}

bool check(vector< vector<int> > &E, int v, int X) {
	for(int index = 0; index < v; index++) {
		if(E[X][index] != 0) {
			return true;
		}
	}
	return false;
}

void BFS(vector< vector<int> > G, map<char, int> index, int v) {
    char s1, s2;
    cin >> s1 >> s2;

    vector< pair<char, int> > vec(index.begin(), index.end());
    sort(vec.begin(),vec.end(),cmp);

    map<char, int>::iterator it;
    it = index.find(s1);
    int X = it->second;
    it = index.find(s2);
    int Y = it->second;

    if(check(G,v,X) == false) {
        cout << "no_path" << endl;
        return;
    }

    int dem = 0;
    queue<int> myQueue;
    myQueue.push(Y);

    while(true) {
        dem = in(G,v,Y,X);
        myQueue.push(dem);
        if(dem == X) {
            break;
        }
        Y = dem;
    }

    stack<int> myStack;
    while(!myQueue.empty()) {
        myStack.push(myQueue.front());
        myQueue.pop();
    }

    while(!myStack.empty()) {
        dem = myStack.top();
        cout << vec[dem].first << ' ';
        myStack.pop();
    }

    cout << endl;
}
// int main()
// {
//     int v,e;
// 	cin >> v >> e;
// 	vector< vector<int> > G (v,vector<int>(v,0));
// 	map<char, int> v_index;
// 	nhap(v,v_index,e,G);
// 	int N;
// 	cin >> N;
// 	while(N--) {
// 		BFS(G,v_index,v);
// 	}
// 	return 0;
// }

vector<string> s1;
set<string> s2;


int check(stack<string> test,string s) {
    while(test.size()){
        if (test.top()== s)
            {return 1;}
        test.pop();
    } 
    return 0;
}

void DFS_call(vector<vector<int>> t1, map<string, int> t2, string m1, string m2, map<string, vector<string>>t3, int v) {
    stack<string> open;    
    open.push(m1);   
    bool close[v]={false}; // Khởi tạo giá trị mặc định cho các phần tử của close là false
    if (s2.find(m1)!=s2.end()) {
        while (!open.empty()) {    
            string m3=open.top();open.pop();
            cout<<m3<<" ";
            close[t2[m3]]=true;
            if (t1[t2[m3]][t2[m2]] != 0){
                cout<<m2 << " ";    
                break;
            }
            for (auto i:t3[m3]) {
                if ((close[t2[i]] == false) && (check(open, i)) == 0 && t2.find(i) != t2.end()) {
                    open.push(i);    
                }
            }
        }
    }
    else cout << "no_path";     
}

int main() {
    srand(unsigned(time(NULL)));
    int z = rand()% 2+1;
    if(z==1){
        int n, e, m;
        cin >> n >> e;
        vector<vector<int>> g(n, vector<int>(n, 0));
        map<string, int> mp;   
        map<string, vector<string>> ss;   
        for (int i = 0; i < n; i++) {   
            string s;   
            cin >> s;
            s1.push_back(s);
            mp[s] = i;
        }
        for (int i = 0; i < e; i++) {
            string s, t;
            cin >> s >> t;
            g[mp[s]][mp[t]] = 1;
            s2.insert(s);   
                ss[s].push_back(t);   
        }
        cin >> m;
        vector<vector<string>> p;
        p.resize(m);
        for (int i = 0; i < m; i++) {
            p[i].resize(2);   
            for (int j = 0; j < 2; j++)
                cin >> p[i][j];    
        }
        for (int i = 0; i < m; i++) {
            DFS_call(g, mp, p[i][0], p[i][1], ss, n);
            cout << "\n";    
        }        
    }
    else{
        int v,e;
        cin >> v >> e;
        vector< vector<int> > G (v,vector<int>(v,0));
        map<char, int> v_index;
        nhap(v,v_index,e,G);
        int N;
        cin >> N;
        while(N--) {
            BFS(G,v_index,v);
        }
    }
    return 0;
}