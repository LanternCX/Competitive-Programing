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
    string a, b;
    cin >> a >> b;
    int ans = 1;
    auto work = [&](string s){
        vector<int> res;
        int n = s.length();
        int cnt = 1;
        char now = s[0];
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (now == s[i]) {
                cnt++;
            } else {
                res.push_back(cnt);
                cnt = 1;
                flag = 1;
                now = s[i];
            }
        }
        res.push_back(cnt);
        return res;
    };
    vector<int> x = work(a), y = work(b);
    debug(x, y);
    if (x.size() != y.size() || a[0] != b[0]) {
        cout << "NO\n";
        return;
    }

    int n = x.size();
    for (int i = 0; i < n; i++) {
        if (y[i] >= x[i] && x[i] * 2 >= y[i]) {
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
 * 上面 a 个下面 b 个
 * 
 * 下面至少是 a 个
 * 下面最多是 b * 2 个
 */