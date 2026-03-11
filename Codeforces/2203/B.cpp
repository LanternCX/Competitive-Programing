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
    int sum = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += s[i] - '0';
    }
    s[0] -= 1;
    sort(s.begin(), s.end(), greater<int>());
    int cnt = 0;
    for (auto ch : s) {
        if (sum < 10) {
            break;
        }
        sum -= ch - '0';
        cnt++;
    }
    cout << cnt << '\n';
}
void test() {
    for (int i = 0; i < 162; i++) {
        string s = to_string(i);
        ll sum = 0;
        for (auto ch : s) {
            sum += ch - '0';
        }
        if (sum == i) {
            cout << i << ' ';
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}