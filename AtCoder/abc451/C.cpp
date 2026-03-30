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
    int q;
    cin >> q;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (q--) {
        int op, h;
        cin >> op >> h;
        if (op == 1) {
            pq.push(h);
            cout << pq.size() << '\n';
        }

        if (op == 2) {
            while (!pq.empty() && pq.top() <= h) {
                pq.pop();
            }
            cout << pq.size() << '\n';
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