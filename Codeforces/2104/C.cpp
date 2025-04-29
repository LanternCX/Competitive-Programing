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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a, b;
    for(int i = 0; i < n; i++){
        if (s[i] == 'A'){
            a.push_back(i + 1);
        }else{
            b.push_back(i + 1);
        }
    }

    int mx = *max_element(b.begin(), b.end());
    int res = 0;
    for(int x : b){
        if(x == 1){
            res = 1;
        }
    }
    
    set<int> st(b.begin(), b.end());
    int ans = 0;
    for(auto i : a){
        if(i == 1){
            if (st.size() == 1 && st.count(n) == 1){
                ans = 1;
                break;
            }
        }else if(i == n){
            if (!res) {
                ans = 1;
                break;
            }
        }else{
            if(i > mx){
                ans = 1;
                break;
            }
        }
    }
    cout << (ans ? "Alice\n" : "Bob\n");
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
/**
 * A先手
 * 只要 A 一直能出一张最大的那么就一定是 A 赢
 * 然后特判 1
 * 
 */