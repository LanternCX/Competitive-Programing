#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct node {
    int idx, x;
};

void sol() {
    int n, T;
    cin >> n >> T;
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
    }
    vector<int> ans;

    double sum = 0;
    vector<node> l;
    for (int i = 0; i < n; i++) {
        if (c[i] > T) {
            l.push_back({i, c[i]});
            sum += c[i];
        } else {
            ans.push_back(i);
        }
    }

    while (!l.empty()) {
        T = sum / l.size();
        reverse(l.begin(), l.end());
        vector<node> temp;
        for (auto [idx, x] : l) {
            if (x > T) {
                temp.push_back({idx, x});
            } else {
                sum -= x;
                ans.push_back(idx);
            }
        }
        l = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " \n"[i == n - 1];
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