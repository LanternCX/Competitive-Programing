#include <bits/stdc++.h>
using namespace std;
const int N = 5e4;
int fa[N + 10];
int root(int x){
    return fa[x] = fa[x] == x ? x : root(fa[x]);
}
void merge(int x, int y){
    fa[root(x)] = fa[root(y)];
}
bool query(int x, int y){
    return root(x) == root(y);
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0; i <= N; i++){
        fa[i] = i;
    }
    map<string, int> id;
    map<int, string> name;
    int idx = 1;
    string s;
    string temp;
    while(cin >> s){
        if(s == "$"){
            break;
        }
        char op = s[0];
        s = s.substr(1, s.size());
        if(id[s] == 0){
            id[s] = idx;
            name[idx++] = s;
        }
        if(op == '#'){
            temp = s;
        }
        if(op == '+'){
            merge(id[s], id[temp]);
        }
        if(op == '?'){
            cout << s << ' ' << name[root(id[s])] << '\n';
        }
    }
    return 0;
}