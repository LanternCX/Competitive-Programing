**题目：**Max Sum

**OJ平台判题结果：**   AC

### 一、问题描述

Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14. Input The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000). Output For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

题目大意：给定一个序列，求这个序列的一个连续子序列的最大和。

**输入格式**：

The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).

输入的第一行是一个整数 `T (1 <= T <= 20)`，表示测试用例的数量。接下来的 `T` 行，每行包含一个整数 `N (1 <= N <= 100000)`，表示该测试用例中数列的长度，接着是 `N` 个整数，所有整数都在 `-1000` 到 `1000` 之间。

**输出格式**：

For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.

对于每组测试数据，输出两行：

- 第一行输出格式为 `"Case #:"`，`#` 表示当前是第几个测试用例（从1开始）。
- 第二行输出三个整数，依次为：**最大子序列和**、**该子序列的起始位置**、**该子序列的结束位置**。下标从1开始计数。
   如果存在多个最大和相同的子序列，输出第一个出现的那个。

**输入样例**：

```
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
```

**输出样例**：

```
Case 1:
14 1 4

Case 2:
7 1 6
```

### 二、数据结构定义与分析

- 本次实验中定义了以下 2 个数据结构（包含 2 个类型别名、1 个数组、1 个区间对）：

  - `vector<int> a(n)`：存储长度为 `n` 的整数序列，作为题目中输入的原始数组。
  - `vector<int> dp(n)`：动态规划数组，`dp[i]` 表示以第 `i` 个数结尾的最大连续子段和.
  - `pair<int, int> ans` ：存储左右端点区间，用于记录最大连续子段的起止位置。

  本次实验中定义了以下 6 个变量：

  - `int n`：表示输入序列的长度。
  - `int mx`：用于记录当前遇到的最大连续子段和。
  - `int l, r`：用于维护当前正在计算的连续子段的左右端点位置。
  - `pii ans`：用于记录最终最大连续子段和所对应的区间端点。
  - `int T`：表示测试样例的个数。
  - `int t`：用于标记当前正在处理的第几组测试样例。

### 三、算法分析

阅读题面，发现是一个经典的线性动态规划问题：求解最大子段和。动态规划算法的核心在于解决三个问题：如何定义状态，如何构建状态转移方程，确定状太转移的边界条件。在不知道动态规划解法之前，很容易由前缀和算法想到一个基于枚举区间左右端点的复杂度为 $O(n^2)$ 的算法。进一步的，通过前缀和算法我们还能注意到，对于每一个下标  `i` 结尾的最大子段和其实就是当前下标的前缀和 `pre[i]` 减去该下标之前的前缀和数组中出现的最小前缀和。对于这个问题，我们很容易从前缀和算法的解法推导出一种动态规划的解法，毕竟前缀和算法本质上是冬天规划算法的一种。如果从另一些问题出发，例如最长上升子序列问题或者背包问题，也可以想到相同的结论。无论从哪个角度出发，我们可以设 `dp[i]` 表示以第 `i` 个数结尾的最大连续子序列和。对于当前的下标，如果延续上一个连续子序列的那么和是`dp[i] = dp[i - 1] + a[i]`，如果不延续那么 `dp[i] = a[i]`，只需要在这两者之间取最大值就行，即： `dp[i] = max(dp[i - 1] + a[i], a[i])`。

### 四、测试用例设计及测试结果

#### 1. 样例测试

**输入：**

```
2
5 -1 2 3 -2 4
4 -3 -2 -1 -4
```

**预期输出：**

```
Case 1:
14 1 4

Case 2:
7 1 6
```

**实际输出：**



#### 2. 多个子序列最大和相同

**输入：**

```
1
9 1 -2 3 -1 3 -1 3 -2 1
```

**预期输出：**

```
Case 1:
7 3 7
```

**实际输出：**



#### 3. 所有数字都是负数

```
1
4 -8 -3 -9 -2
```

**预期输出：**

```
Case 1:
-2 4 4
```

**实际输出：**



从以上测试当中可以检验出程序的完备性

### 五、存在问题及可能原因

1. **状态转移方程推导错误**

  **问题**：状态转移方程没有正确推导

  **原因**：并查集初始化需要将每个节点的根设置为自己

2. **题意理解错误**

  **问题**：理解了题意

  **原因**：错误理解了题意，认为最大连续子序列和的子序列定义与最长上升子序列问题中的子序列定义相同，忽略了连续的要求

### 六、附源代码以及代码相应注释

```c++
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

void sol() {
    // 按题目要求读入序列的大小
    int n;
    cin >> n;

    // 按题目要求
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

```

### 七、实验总结及建议

对于动态规划问题，可以先在数据层面对复杂度进行简单的判定，如果复杂度是`O(n^2)`可以猜测可能是背包问题，而对于一些明显存在递推关系的代码，可以注意到状态转移方程的建立由此推断出动态规划的解法。在推断动态规划算法的时候，可以从如何定义状态以及如何转移状态入手，结合题意，进行答案的推导。