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

struct node {
    string id;
    int n;  
};
void sol() {
    int n;
    cin >> n;
    map<int, node> mp;
    for (int i = 0; i < n; i++) {
        string id;
        int idx, num;
        cin >> id >> idx >> num;
        mp[idx] = {id, num};
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto [id, num] = mp[x];
        cout << id << ' ' << num << '\n';
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