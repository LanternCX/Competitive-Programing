#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif

void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (auto &x : w) {
        cin >> x;
    }

    sort(w.begin(), w.end());

    // 逆向 DP dp[i][j] 表示使用第 i 个到末尾的硬币，能否恰好凑出金额 j
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[n][0] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= m; j++) {
            // 不选当前硬币
            dp[i][j] = dp[i + 1][j];
            // 选
            if (j >= w[i] && dp[i + 1][j - w[i]]) {
                dp[i][j] = true;
            }
        }
    }

    // 无法凑出目标金额
    if (!dp[0][m]) {
        cout << "No Solution\n";
        return;
    }

    // 正向贪心回溯：寻找字典序最小的序列
    int rem = m;
    bool first = true;
    for (int i = 0; i < n && rem > 0; i++) {
        // 因硬币已升序排列，只要选中当前硬币后剩余序列仍有解，即为最优选择
        if (rem >= w[i] && dp[i + 1][rem - w[i]]) {
            if (!first) cout << ' ';
            cout << w[i];
            rem -= w[i];
            first = false;
        }
    }
    cout << '\n';
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