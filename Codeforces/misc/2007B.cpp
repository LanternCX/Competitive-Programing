#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    vector<vector<int>> ans;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        int max = INT_MIN;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            max = max > x ? max : x;
        }
        vector<int> vec;
        for (int j = 0; j < m; j++) {
            char ch;
            int l, r;
            cin >> ch >> l >> r;
            int opt = (ch == '+') ? 1 : -1;
            if (r >= max && l <= max) {
                max += opt;
            }
            vec.push_back(max);
        }
        ans.push_back(vec);
    }
    for (const vector<int>& vec : ans) {
        for (int i : vec) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
