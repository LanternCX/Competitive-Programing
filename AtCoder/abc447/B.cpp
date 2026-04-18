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
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto ch : s) {
        cnt[ch]++;
    }
    vector<pair<int, char>> arr;
    for (auto [ch, c] : cnt) {
        arr.push_back({c, ch});
    }
    sort(arr.begin(), arr.end(), greater<pii>());
    debug(arr);
    map<char, int> mp;
    for (auto [c, ch] : arr) {
        if (c == arr[0].first) {
            mp[ch] = 1;
        } else {
            break;
        }
    }
    for (auto ch : s) {
        if (!mp[ch]) {
            cout << ch;
        }
    }
    cout << '\n';
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