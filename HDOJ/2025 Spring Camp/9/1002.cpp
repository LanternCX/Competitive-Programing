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

#define int long long
const int inf = 1e10;
auto manacher(const vector<int> s) {
    vector<int> T = {inf};
    for (auto c : s) {
        T.push_back(c);
        T.push_back(inf);
    }
    int n = T.size();
    vector<int> P(n, 0);  
    int C = 0, R = 0;
    int maxLen = 0, centerIndex = 0; 
    for (int i = 0; i < n; ++i) {
        if (i < R) {
            P[i] = min(R - i, P[2 * C - i]);
        }
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    int start = (centerIndex - maxLen) / 2;
    return P;
}

void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<int> s;
    for(int i = 1; i < n; i++){
        s.push_back(a[i] - a[i - 1]);
    }
    int sum = 0;
    auto m = manacher(s);
    for(auto x : m){
        sum += x / 2;
    }
    debug(s);
    debug(m);
    cout << sum + n + n - 1 << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}