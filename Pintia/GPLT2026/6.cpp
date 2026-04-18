#include <bits/stdc++.h>

using namespace std;

void sol() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x, op;
        cin >> x >> op;
        mp[x] = max(mp[x], op);
    }
    int ans = 0;
    vector<int> temp;
    for (auto [x, y] : mp) {
        if (y == 0) {
            temp.push_back(x);
        }
    }
    if (temp.empty()) {
        cout << "NONE";
        return;
    }
    for (int i = 0; i < temp.size(); i++) {
        cout << temp[i] << " \n"[i == temp.size() - 1];
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