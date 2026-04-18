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
    queue<int> A, B, C;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            A.push(i);
        }
        if (s[i] == 'B') {
            B.push(i);
        }
        if (s[i] == 'C') {
            C.push(i);
        }
    }

    auto find = [&](queue<int>& q, int val) {
        if (q.empty()) {
            return -1;
        }
        while (q.front() < val) {
            q.pop();
            if (q.empty()) {
                return -1;
            }
        }
        int res = q.front();
        q.pop();
        return res;
    };

    int ans = 0;
    for (int i = 0; i < s.length() / 3; i++) {
        if (A.empty()) {
            break;
        }
        int a = A.front();
        A.pop();

        int b = find(B, a);
        if (b == -1) {
            break;
        }

        int c = find(C, b);
        if (c == -1) {
            break;
        }
        ans++;
    }
    cout << ans << '\n';
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