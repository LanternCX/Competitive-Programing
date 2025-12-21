## 一、实验题目：



## 二、数据结构定义：
- node: 物品数据结构

  - w：重量
  - v：价值

  ```c++
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
  ```

- arr：存储所有的物品的数组

  ```c++
  vector<node> arr(n);
  ```

- pq：STL 堆，用于维护贪心策略

  ```c++
  priority_queue<node, vector<node>, greater<node>> pq(arr.begin(), arr.end());
  ```

- x：x 答案数组

  ```c++
  vector<double> x(n);
  ```

## 三、算法分析：

题意：从若干物品中取物品放入背包，物品可以取任意大小的部分，问如何取才能在满足背包最大容量的情况下使得取的物品的总价值最高。

观察题面，很容易可以想到一个贪心策略：单位价值越高的物品应该越先拿到包里。

而每次取最值这一策略，可以通过堆来维护。

因此我们很容易设计出算法：取出未拿的物品中单位价值最大的，如果背包能全装下就全拿，如果背包装不下只拿能拿的部分。每次取单位价值最大的操作使用堆来维护。

具体实现可以参考：
```c++
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
```

## 四、算法的复杂度

堆初始化：$ O(n\log(n)) $

```c++
priority_queue<node, vector<node>, greater<node>> pq(arr.begin(), arr.end());
```

计算答案：$ O(nlog(n) + n) $

```c++
// O(n)
vector<double> x(n);
// O(nlog(n))
auto [w, v, id] = pq.top();
pq.pop();
```

## 五、测试运行结果

## 六、存在问题及可能原因

1. 当某个物品重量 `w` 为 0 时，计算单位价值 `v / w` 会产生除零错误，导致程序异常
2. 使用 `double` 进行浮点运算，在多次累加价值或比例计算时可能产生精度误差，使最终结果与理论值存在微小偏差
3. 三是对 `priority_queue` 中比较函数的理解不够准确，若运算符重载方向写反，可能导致堆中维护的并非单位价值最大的物品，从而影响贪心策略的正确性

## 七、附源代码以及代码相应注释

```c++
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
```
