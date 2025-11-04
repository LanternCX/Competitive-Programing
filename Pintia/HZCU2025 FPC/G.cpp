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
    int n;
    cin >> n;
    for (int i = n + 1; i <= 9000; i++) {
        set<char> s;
        string str = to_string(i);
        for (auto ch : str) {
            s.insert(ch);
        }
        if (s.size() == 4) {
            cout << i << '\n';
            return;
        }
    }
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