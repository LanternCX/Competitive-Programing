#include <bits/stdc++.h>
using namespace std;
// 物品数据结构定义
struct node {
    // 重量，价值
    double w, v;
    // 物品编号
    int id;
    bool operator>(node a) const {
        // 重载运算符
        // 单位价值高的在前
        return v / w < a.v / a.w;
    }
};
void sol() {
    // 输入与初始化
    int n;
    double W;
    cin >> n >> W;
    vector<node> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].id = i;
    }
    for (auto &[w, v, id] : arr) {
        cin >> w;
    }
    for (auto &[w, v, id] : arr) {
        cin >> v;
    }
    
    // 利用堆维护贪心策略
    priority_queue<node, vector<node>, greater<node>> pq(arr.begin(), arr.end());

    // 贪心计算答案
    vector<double> x(n);
    double tot = 0;
    while (!pq.empty()) {
        // 取出未拿的物品中单位价值最大的
        auto [w, v, id] = pq.top();
        pq.pop();
        if (W >= w) {
            // 如果背包能全装下就全拿
            x[id] = 1;
            tot += v;
            W -= w;
        } else {
            // 如果背包装不下只拿能拿的部分
            x[id] = 1 - (w - W) / w;
            tot += v * x[id];
            break;
        }
    }

    // 打印答案
    cout << tot << '\n';
    for (auto x : x) {
        cout << x << ' ';
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(2);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}