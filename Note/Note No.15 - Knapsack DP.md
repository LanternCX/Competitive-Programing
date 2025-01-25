# Note No.15: Knapsack DP

**背包DP**分为01背包、完全背包、多重背包等等

## 01背包

背包容量有限，在 n 个物品中拿若干个，如何使得拿到的物品价值最大

因为一个物品只有拿或者不拿两种选择，因此称为**01背包**

### Luogu P1048 采药

- 状态定义：`dp[i][j]`表示在只考虑前`i`个物品的情况下，背包容量为`j`时背包内物品价值的最大值
- 状态转移方程：`dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j])`

优化一维之后：

- 状态定义：`dp[j]`表示背包容量为`j`时的物品价值的最大值
- 状态转移方程：`dp[j] = max(dp[j - w[i]] + v[i], dp[j])`

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int W, m;
    cin >> W >> m;
    vector<int> w(m);
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> w[i] >> v[i];
    }
    // dp[i] 表示背包内重量为 i 时物品的最大价值
    vector<int> dp(t + 1);
    int ans = 0;
    // 从第 1 个物品开始考虑
    for(int i = 0; i < m; i++){
        // 从满背包容量开始考虑到背包容量为只能装下w[i]
        // 背包越满子问题越小，所以从背包满开始考虑
        for(int j = W; j >= w[i]; j--){
            // 选择拿或者不拿第 i 个，取最大值
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
            ans = max(dp[j], ans);
        }
    }
    cout << ans;
    return 0;
}
```

## 完全背包

与0**1背包**不同的是**完全背包**问题中的物品可以无限次拿取，因此被称为完全背包

### Luogu P1616 疯狂的采药

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int W, m;
    cin >> W >> m;
    vector<int> w(m);
    vector<int> v(m);
    for(int i = 0; i < m; i++){
        cin >> w[i] >> v[i];
    }
    vector<ll> dp(t + 1);
    for(int i = 0; i < m; i++){
        for(int j = w[i]; j <= W; j++){
            dp[j] = max(dp[j - w[i]] + v[i], dp[j]);
        }
    }
    cout << dp[t];
    return 0;
}
```

代码惊人地相似！

这是因为，在考虑不优化第一维的情况时不难发现：对于当前处理的物品`i` 和当前状态`dp[i][j]`，`j - w[i] <= j`恒成立，因此`j`从小到大枚举时，`dp[i][j]` 是会被已经更新过的`dp[i][j - w[i]]`所影响的。也就是说可能多次出现`dp[j] = dp[j - w[i]] + v[i] `的情况。这就相当于物品`i`可以多次被放入背包。

01背包为了避免这种情况发生，改变了枚举的顺序，从`W`枚举到`w[i]`，这样就不会出现上述的错误，因为`dp[i][j]` 总是在`dp[i][j - w[i]]`前被更新。而完全背包问题则正需要这种情况发生，因此很容易从01背包得出完全背包的解法。

### 多重背包

只需要在01背包的基础上改造一下多遍历一层物品数量就好

```c++
for(int i = 0; i < m; i++){
    for(int j = W; j >= w[i]; j--){
         // 多遍历一层物品数量
        for (int k = 1; k * w[i] <= j && k <= cnt[i]; k++) {
          dp[j] = max(dp[j], dp[j - k * w[i]] + k * v[i]);
        }
    }
}
```

