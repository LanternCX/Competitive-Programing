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
    int H, W;
    cin >> H >> W;
    vector<vector<char>> mp(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> mp[i][j];
        }
    }

    vector<vector<int>> vis(H, vector<int>(W));
    vector<int> dx = {1, -1, 0,0};
    vector<int> dy = {0, 0, 1, -1};

    int ans = 0;

    auto bfs = [&](int x, int y) {
        assert(x != 0 && x != W - 1 && y != 0 && y != H - 1);
        assert(x > 0 && x < W - 1 && y > 0 && y < H - 1);

        if (vis[y][x] != 0 || mp[y][x] == '#') {
            return 0;
        }

        debug(x, y);

        queue<pii> q;
        q.push(pii(x, y));
        vis[y][x] = 1;

        int flag = 1;

        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();

            if (cx == 0 || cx == W - 1 || cy == 0 || cy == H - 1) {
                flag = 0;
            }

            for (int i = 0; i < 4; i++) {
                int xn = cx + dx[i];
                int yn = cy + dy[i];

                if (xn < 0 || xn >= W || yn < 0 || yn >= H) {
                    continue;
                }

                if (vis[yn][xn] == 0 && mp[yn][xn] != '#') {
                    vis[yn][xn] = 1;
                    q.push({xn, yn});
                }
            }
        }
        debug("ok", x, y);
        return flag;
    };

    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (mp[i][j] == '.' && vis[i][j] == 0) {
                ans += bfs(j, i);
            }
        }
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