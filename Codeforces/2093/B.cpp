#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol(){
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    int mx = 0;
    int idx = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] != '0'){
            break;
        }
        idx++;
    }
    for(int i = 0; i < n - idx; i++){
        if(s[i] == '0'){
            cnt++;
        }
    }
    cout << max((int) s.length() - 1 - cnt, 0) << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}