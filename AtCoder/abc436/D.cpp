#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using pii = pair<int, int>;

struct node {
    int x, y, d;
};

void sol() {
    int n, m;
    cin >> m >> n;
    vector<vector<char>> mp(m, vector<char>(n));
    map<char, vector<pii>> dict;
    map<char, int> dict_vis;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] != '.' && mp[i][j] != '#') {
                dict[mp[i][j]].push_back({i, j});
                dict_vis[mp[i][j]] = 0;
            }
        }
    }

    queue<node> q;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    q.push({0, 0, 0});
    vis[0][0] = 1;

    while (!q.empty()) {
        auto [x, y, d] = q.front();
        q.pop();

        if (x == m - 1 && y == n - 1) {
            cout << d << '\n';
            return;
        }

        // warp
        if (mp[x][y] != '.' && mp[x][y] != '#' && !dict_vis[mp[x][y]]) {
            for (auto [xi, yi] : dict[mp[x][y]]) {
                if (!vis[xi][yi]) {
                    vis[xi][yi] = 1;
                    q.push({xi, yi, d + 1});
                }
            }
            dict_vis[mp[x][y]] = 1;
        }

        // walk
        static int dx[4] = {0, 0, 1, -1};
        static int dy[4] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++) {
            int xi = x + dx[i];
            int yi = y + dy[i];
            if (xi < 0 || yi < 0 || xi >= m || yi >= n) continue;
            if (mp[xi][yi] == '#') {
                continue;
            }
            if (!vis[xi][yi]) {
                vis[xi][yi] = 1;
                q.push({xi, yi, d + 1});
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sol();
    return 0;
}
