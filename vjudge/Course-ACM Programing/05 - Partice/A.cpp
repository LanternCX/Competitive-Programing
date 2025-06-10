#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void sol() {
    // 按题目要求读入序列的大小
    int n;
    cin >> n;

    // 按题目要输入
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    // 第一步：定义dp数组。定义 dp[i] 表示以第 i 个数结尾的最大连续子段和
    vector<int> dp(n);
    // 第二步：初始化。初始化 dp[0] 为 a[0], 表示以第 0 个数结尾的的最大连续子段和为 a[0], 符合定义
    dp[0] = a[0];
    // 维护的最大连续子段和
    int mx = a[0];
    // 维护的当前下标结尾的最大连续子段和区间的左右端点
    int l = 0, r = 0;
    // 维护的出现最大连续子段和的区间的左右端点作为答案
    pii ans = {0, 0};

    // 第三步：建立状态转移方程并进行状态转移
    for (int i = 1; i < n; i++) {
        // 转移方程：dp[i] = max(dp[i - 1] + a[i], a[i])
        // 并在转移的同时维护当前子段的左右端点
        if (dp[i - 1] + a[i] < a[i]) {
            l = i;
            r = i;
            dp[i] = a[i];  
        } else {
            r = i;
            dp[i] = dp[i - 1] + a[i];
        }

        // 维护当前最大连续子段和以及当前最大连续子段和的左右端点
        if (dp[i] > mx) {
            ans = {l , r};
            mx = dp[i];
        }
    }

    // 按要求打印答案
    auto [ansl, ansr] = ans;
    ansl++, ansr++;
    cout << mx << ' ' << ansl << ' ' << ansr << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // 测试样例数量
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        // 按要求打印答案信息
        cout << "Case " << t << ":\n"; 
        sol();
        if (t != T) cout << "\n";
    }
    return 0;
}
