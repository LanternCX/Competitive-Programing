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
void sol() {
    vector<string> arr;
    for (int i = 0; i < 32; i++) {
        arr.push_back(to_string(1 << i));
    }

    vector<int> mp;

    auto dfs = [&](auto && dfs, string pre) -> void {
        for (auto suf : arr) {
            if (pre.length() + suf.length() > 9) {
                continue;
            }
            dfs(dfs, pre + suf);
        }

        if (pre.length() > 0 && pre.length() <= 9) {
            mp.push_back(stoi(pre));
        }
    };

    
    dfs(dfs, "");
    
    int n;
    
    cin >> n;
    
    sort(mp.begin(), mp.end());

    auto x = unique(mp.begin(), mp.end());
        
    cout << mp[n - 1] << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}