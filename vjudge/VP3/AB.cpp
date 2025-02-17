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
    vector<int> a(10, 2021);
    int cnt = 0;
    for(int i = 0; i < 1e9; i++){
        string s = to_string(i);
        for(auto ch : s){
            a[ch - '0']--;
        }
        int tag = 1;
        for(auto x : a){
            if(x <= 0){
                tag = 0;
            }
        }
        if(tag){
            cnt++;
        }else {
            break;
        }
    }
    cout << cnt;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 256MB
 */