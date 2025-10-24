#include <bits/stdc++.h>
using namespace std;

struct node {
    int id;
    int x;
};

void sol() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        sort(mp[i].begin(), mp[i].end());
    }

    vector<node> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].id = i;
        arr[i].x = mp[i][0];
    }

    sort(arr.begin(), arr.end(), [](node a, node b) -> int {
        return a.x < b.x;
    });

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = arr[i].id;
    }

    int temp = -1;
    for (int round = 0; round < m; round++) {
        bool valid = true;
        for (int i = 0; i < n; i++) {
            int cow = p[i];
            auto it = upper_bound(mp[cow].begin(), mp[cow].end(), temp);
            if (it == mp[cow].end()) {
                valid = false;
                break;
            }
            temp = *it;
            mp[cow].erase(it);
        }
        if (!valid) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int x : p) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
