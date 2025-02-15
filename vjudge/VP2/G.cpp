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
struct node{
    int v, w;
};
void sol(){
    int n;
    cin >> n;
    vector<node> a(n);
    for(auto &x : a){
        cin >> x.w >> x.v;
    }
    sort(a.begin(), a.end(), [&](node a, node b){
        return a.v + a.w < b.v + b.w;
    });
    vector<int> dp(a[n - 1].w + a[n - 1].v + 1);
    for(int i = 0; i < n; i++){
        for(int j = a[i].w + a[i].v; j >= a[i].w; j--){
            dp[j] = max(dp[j - a[i].w] + a[i].v, dp[j]);
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * dp?
 * 状态定义
 * dp[j] 表示背包容量为 j 时物品价值的最大值
 * 转移方程
 * dp[j] = max(dp[j - w[i]] + v[i], dp[j])
 * 
 * 奥好像排序一下保证顺序就好了
 * 
 * 如果 i 可以放在 j 上面，那么
 * 从上到下依次是 W w[i] w[j]
 * 1) v[i] > W && v[j] >= W + w[i];
 * 
 * 如果 j 可以放在 i 上面，那么
 * 从上到下依次是 W w[j] w[i]
 * 2) v[j] > W && v[i] >= W + w[j];
 * 
 * 什么情况下 i 可以在 j 上面但是 j 不可以在 i 上面？
 * 也就是 1) 式为真 2) 式为假
 * 由 1) 式 v[j] >= W + w[i] && w[i] > 0 推出 v[j] > W
 * 因此要使 2) 式为假，v[i] >= W + w[j]需要为假，也就是 v[i] < W + w[j]
 * 2)式中 v[i] > W + w[j] 两侧同时加上 w[i] 得到 3) v[i] + w[i] < W + w[j] + w[i]
 * 1)式中 v[j] > W + w[i] 两侧同时加上 w[j] 得到 4) v[j] + w[j] >= W + w[i] + w[j]
 * 注意到 3) 和 4) 式子的右侧相同，将 3) 和 4) 联立得 v[i] + w[i] < v[j] + w[j]
 * 
 * 因此按照 v[i] + w[i] < v[j] + w[j] 的顺序排序就好
 */