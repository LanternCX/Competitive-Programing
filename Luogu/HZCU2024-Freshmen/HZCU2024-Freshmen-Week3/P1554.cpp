#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<int> ans(10);
    for(int i = m; i <= n; i++){
        string s = to_string(i);
        for(char c : s){
            ans[c - '0']++;
        }
    }
    for(int i : ans){
        cout << i << ' ';
    }
    return 0;
}