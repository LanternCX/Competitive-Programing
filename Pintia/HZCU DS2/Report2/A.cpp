#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol() {
    int n;
    cin >> n;
    
    // 用于标记行是否防止棋子
    vector<int> col(n, 0);
    // 用于标记主副对角线是否放置棋子
    vector<vector<int>> diag(2, vector<int>(n * 2, 0));
    
    // 答案可能很大因此开 long long 防溢出
    ll ans = 0;
    // dfs 搜索放到第 row 行的时候接下来可放的位置
    auto dfs = [&](auto&& dfs, int row) -> void {
        //  统计答案
        if (row == n) {
            ans += 1;
            return;
        }

        // 对于当前行逐列枚举搜索可放位置
        for (int i = 0; i < n; i++) {
            // 第 row 行 第 i 列 对应 第 n - i + row 条主对角线与 第 i + row 条副对角线
            if (!col[i] && !diag[0][i + row] && !diag[1][n - i + row]) {
                // 对列、主对角线、副对角线标记访问
                col[i] = 1;
                diag[0][i + row] = 1;
                diag[1][n - i + row] = 1;

                dfs(dfs, row + 1);

                // 回溯
                col[i] = 0;
                diag[0][i + row] = 0;
                diag[1][n - i + row] = 0;
            }
        }
    };

    // 从第 0 行开始搜索
    dfs(dfs, 0);
    
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