# ACM Note No.14: Liner DP

## 引入

动态规划（Dynamic Programming, DP），动态规划是一种重要的思维方法，通过利用已有的子问题信息高效求出当前问题的最优解。使用动态规划需要满足三个条件：最优子结构，无后效性和子问题重叠。

- 最优子结构：一个问题的最优解可以通过子问题的最优解来构造
- 无后效性：已经求解的子问题，不会再受到后续决策的影响
- 子问题重叠：一个相同的子问题如果需要被求解多次，可以先求解一次然后将子问题的解存起来后续直接使用

xxxxxxxxxx /*** @param g 图的邻接矩阵*/void floyd(vector<vector<int>> &g){    int n = g.size();    for(int k = 0; k < n; k++){        for(int i = 0; i < n; i++){            for(int j = 0; j < n; j++){                if (g[i][k] != inf && g[k][j] != inf) {                    // 状态转移                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);                }            }        }    }}c++

1. 通过与状态有关的变量**定义状态**
2. 确定**状态转移方程**
3. 确定**边界条件**

## 线性DP

### Luogu P1216 数字三角形

走到当前节点的权值最大值取决于上一层节点到达当前节点的两条路径中权值和最大的那一条

- 状态定义：定义`dp[i][j]`表示到第`i`层第`j`个节点的最大权值和

- 状态转移方程：最大权值和取决于经过上一层第`j - 1`个节点还是第`j`个节点，于是有`dp[i][j] = max(dp[i - 1][j] + mp[i][j], dp[i - 1][j - 1] + mp[i][j])`

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r;
    cin >> r;
    vector<vector<int>> mp(r, vector<int>(r));
    vector<vector<int>> dp(r, vector<int>(r));
    for(int i = 0; i < r; i++){
        for(int j = 0; j <= i; j++){
            cin >> mp[i][j];
        }
    }
    int ans = 0;
    dp[0][0] = mp[0][0];
    for(int i = 1; i < r; i++){
        dp[i][0] = dp[i - 1][0] + mp[i][0];
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j] + mp[i][j], dp[i - 1][j - 1] + mp[i][j]);
            ans = max(dp[i][j], ans);
        }
    }
    cout << ans;
    return 0;
}
```

### Luogu B3637 最长上升子序列

给出一个由 n 个正整数组成的序列，输出这个序列的**最长上升子序列**的长度。

- 定义状态：`dp[i]`表示以第`i`个数结尾的最长上升子序列，当然表示以第`i`个数结尾的最长上升子序列也可以，但是不能定义表示到第`i`个数为止的最长上升子序列
- 状态转移方程：我们找到每个前`i`个数据中比`arr[i]`小的数字`arr[j]`，于是有`dp[i] = max(dp[j] + 1, dp[i])`

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n + 1, 1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i; j >= 1; j--){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
            ans = max(dp[i], ans);
        }
    }
    cout << ans;
    return 0;
}
```

### Luogu P1115 最大子段和

给出一个长度为 n 的序列 a，选出其中连续且非空的一段使得这段和最大

- 定义状态：类似上一题可以用`dp[i]`表示以第`i`个数结尾的最大子段和
- 状态转移方程：容易列出状态转移方程`dp[i] = max(dp[i - 1] + a[i], a[i])`，只需要选择是否延续前一个数继续进行加法即可

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n);
    dp[0] = a[0];
    int ans = INT_MIN;
    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i - 1] + a[i], a[i]);
        ans = max(dp[i], ans);
    }
    cout << ans;
    return 0;
}
```

有趣的是，此题还可以由子段和联想到从前缀和的角度考虑。

当然如果单就这题而言前缀和做法可以很容易化简为 DP 做法，但是如果从前缀和的角度出发，考虑`长度至少为d的最大子段和`这一问题就较为轻松

```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    int mn = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, pre[i] - mn);
        // 如果是长度至少为 d 的最大子段和那么只需要使用 mn = min(mn, pre[i - m]);
        mn = min(mn, pre[i]);
    }
    cout << ans;
    return 0;
}

```

前缀和算法其实也是一种动态规划算法

