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
    int n, m;
    n = 30, m = 50;
    vector<vector<char>> mp(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mp[i][j];
        }
    }
    ll ans = 0;
    auto work = [&](string s){
        ll cnt = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                for(int k = j; k < len; k++){
                    if(s[i] < s[j] && s[j] < s[k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    };
    auto work1 = [&](string s){
        ll cnt = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            for(int j = i; j < len; j++){
                for(int k = j; k < len; k++){
                    if(s[i] < s[j] && s[j] < s[k] || s[i] > s[j] && s[j] > s[k]){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    };
    // 行
    for (int i = 0; i < n; ++i) {
        string s = "";
        for (int j = 0; j < m; ++j) {
            s += mp[i][j];
        }
        ans += work(s);
    }

    // 列
    for (int j = 0; j < m; ++j) {
        string s = "";
        for (int i = 0; i < n; ++i) {
            s += mp[i][j];
        }
        ans += work(s);
    }

    // 主对角线
    {
        for (int j = 0; j < m; ++j) {
            string s = "";
            int x = 0, y = j;
            while (x < n && y < m) {
                s += mp[x][y];
                ++x;
                ++y;
            }
            ans += work(s);
        }
        for (int i = 1; i < n; ++i) {
            string s = "";
            int x = i, y = 0;
            while (x < n && y < m) {
                s += mp[x][y];
                ++x;
                ++y;
            }
            ans += work(s);
        }
    }
    // 副对角线
    {
        for (int j = 0; j < m; ++j) {
            string s = "";
            int x = n - 1, y = j;
            while (x >= 0 && y < m) {
                s += mp[x][y];
                --x;
                ++y;
            }
            ans += work1(s);
        }
        for (int i = n - 2; i >= 0; --i) {
            string s = "";
            int x = i, y = 0;
            while (x >= 0 && y < m) {
                s += mp[x][y];
                --x;
                ++y;
            }
            ans += work1(s);
        }
    }
    cout << ans;
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