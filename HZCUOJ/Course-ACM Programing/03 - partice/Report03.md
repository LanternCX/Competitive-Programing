**题目：**How Many Tables

**OJ平台判题结果：**   AC

### 一、问题描述

Economic times these days are tough, even in Byteland. To reduce the operating costs, the government of Byteland has decided to optimize the road lighting. Till now every road was illuminated all night long, which costs 1 Bytelandian Dollar per meter and day. To save money, they decided to no longer illuminate every road, but to switch off the road lighting of some streets. To make sure that the inhabitants of Byteland still feel safe, they want to optimize the lighting in such a way, that after darkening some streets at night, there will still be at least one illuminated path from every junction in Byteland to every other junction.

What is the maximum daily amount of money the government of Byteland can save, without making their inhabitants feel unsafe?

题目大意：给定一个无向图，求这个无向图的总边权和与这个无向图的最小生成树的边权和的差值。

**输入格式**：

The input file contains several test cases. Each test case starts with two numbers m and n, the number of junctions in Byteland and the number of roads in Byteland, respectively. Input is terminated by m=n=0. Otherwise, 1 ≤ m ≤ 200000 and m-1 ≤ n ≤ 200000. Then follow n integer triples x, y, z specifying that there will be a bidirectional road between x and y with length z meters (0 ≤ x, y < m and x ≠ y). The graph specified by each test case is connected. The total length of all roads in each test case is less than 2^31.

输入文件包含多个测试用例。每个测试用例以两个数字 m 和 n 开始，分别表示无向图的边数和节点数。输入以 m=n=0 作为终止标志。除此之外，1 ≤ m ≤ 200000 且 m-1 ≤ n ≤ 200000。接下来是 n 个整数三元组 x、y、z，表示在 x 和 y 之间有权值为 z 的边（其中 0 ≤ x, y < m 且 x ≠ y）。每个测试用例所描述的图是连通的。每个测试用例中所有边权之和小于 2^31。

**输出格式**：

For each test case print one line containing the maximum daily amount the government can save.

对于每组测试样例，打印一行一个数字作为答案。

**输入样例**：

```
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
```

**输出样例**：

```
51
```

### 二、数据结构定义与分析

本次实验中定义了以下 3 个数据结构，（包含 2 个成员变量和 3 个成员函数）:

- `DSU`：

	成员变量

    - `fa`：并查集的 `fa` 数组，其中 `fa[i] = j` 表示下标为 `i`的父亲下标 `j`

    - `n`：并查集的大小

	成员方法

    - `int find(int x)`：递归查找下标为 x 的元素的父亲并进行路径压缩，其中 x 为查询的下标

    - `void merge(int x, int y)`：将下标为 x 和下标为 y 的元素合并，其中 x 和 y 为需要合并的下标

- `node`：

  成员变量

  - `x， y`：连接的节点下标 x, y
  - `w`：边权

- ` vector<node> a(m)`：无向边集合，大小为 m

本次实验中定义了以下 5 个变量:

- `long long sum`：无向图的边权和
- `int n, m`：无向图的节点数和边数
- `int cnt`：维护的当前构造的生成树的边的数量
- `long long ans`：最小生成树的边权和

### 三、算法分析

阅读题面，不难看出这是一道与最小生成树算法有关的图题。题目的本质就是求无向图的总边权和与这个无向图的最小生成树的边权和的差值。

关于最小生成树算法，常见的有 Kruskal 算法，和 Prim 算法，由于 Kruskal 算法使用带路径压缩的并查集在多数情况下较 Prim 算法更优，因此选用 Kruskal 算法。

Kruskal 算法是一种贪心算法，其基本思想是贪心地从小到大加入边，其中每次加入的边需要满足对当前构造的生成树的联通性质产生贡献。

由于需要判断节点之间的联通性，很容易想到使用并查集维护节点直接的连通性。

结合树的性质，树的边数量等于树的节点数量减一，可以用来判断贪心终点。

在使用了时间复杂度为`O(nlogn)`的排序算法和时间复杂度为`O(m × α(m, n))`的并查集之后就可以得到时间复杂度为`O(nlogn)`的最小生成树算法。

### 四、测试用例设计及测试结果

#### 1. 样例测试

**输入：**

```
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
0 0
```

**预期输出：**

```
51
```

**实际输出：**



#### 2. 单个结点

**输入：**

```
1 0
0 0
```

**预期输出：**

```
0
```

**实际输出：**



#### 3. 链状图

```
4 3
0 1 5
1 2 10
2 3 15
0 0
```

**预期输出：**

```
0
```

**实际输出：**



#### 4. 三角形（简单环）

**输入：**

```
3 3
0 1 4
1 2 5
2 0 6
0 0
```

**预期输出：**

```
6
```

**实际输出：**



#### 5. 完全图

**输入：**

```
4 6
0 1 1
0 2 2
0 3 3
1 2 4
1 3 5
2 3 6
0 0
```

**预期输出：**

```
15
```

**实际输出：**



从以上测试当中可以检验出程序的完备性

### 五、存在问题及可能原因

1. **并查集实现问题**

  **问题**：并查集未初始化或者初始化错误

  **原因**：并查集初始化需要将每个节点的根设置为自己

2. **题意理解错误**

  **问题**：答案直接输出了最小生成树

  **原因**：并查集使用 0 开头下标但是输入的数据使用的是 1 开头下标，需要进行下标的转换

3. **没有使用路径压缩**

  **问题**：并查集查询时间复杂度过大

  **原因**：并查集算法中没有使用路径压缩算法导致递归调用栈过长使得时间复杂度超出限制

### 六、附源代码以及代码相应注释

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * @brief 并查集封装
 */
struct DSU {
    /**
     * @brief fa 数组, 节点 x 的父亲节点为 fa[x]
     */
    vector<int> fa;

    /**
     * @brief 并查集大小
     */
    int n;

    /**
     * @brief 构造函数
     * @param size 并查集大小
     */
    DSU(int size): n(size), fa(size) {
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };

    /**
     * @brief 递归查找根节点并进行路径压缩
     * @param x 当前查询的节点下标
     */
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    /**
     * @brief 合并两个节点
     * @param x 需要合并的节点下标 x
     * @param y 需要合并的节点下标 y
     */
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    /**
     * @brief 查询两个节点是否属于同一集合
     * @param x 查询的第一个节点下标
     * @param y 查询的第二个节点下标
     */
    bool query(int x, int y) {
        return find(x) == find(y);
    }
};

/**
 * @brief 无向边结构体定义
 */
struct node {
    /**
     * @brief 连接的节点下标 x
     */
    int x;
    
    /**
     * @brief 连接的节点下标 y
     */
    int y;
    
    /**
     * @brief 边权
     */
    int w;
};

void sol() {
    // 题目给定的边的数量和节点数量
    int m, n;
    while (cin >> n >> m) {
        // 循环输入直到 (m == 0 && n == 0)
        if (m == 0 && n == 0) {
            return;
        }
        // 初始化边权和
        ll sum = 0;
        // 初始化节点数组
        vector<node> a(m);
        // 读入节点数据并计算边权和
        for (auto &[x, y, w] : a) {
            cin >> x >> y >> w;
            sum += w;
        }

        // 初始化并查集
        DSU dsu(n);
        
        // 将节点按照边权从小到大排序方便贪心
        sort(a.begin(), a.end(), [&](node a, node b) {
            return a.w < b.w;
        });
        
        // 初始化当前最下生成树的边的数量
        int cnt = 0;
        ll ans = 0;
        for (auto [x, y, w] : a) {
            // 一颗树的边的数量为 节点数量 - 1, 利用这个性质可以判断贪心终点
            if (cnt == n - 1) {
                break;
            }

            // 如果两个节点已经联通则当前边的加入对最小生成树没有贡献，应该跳过
            if (dsu.query(x, y)) {
               continue; 
            }

            // 加入新的边并用并查集维护两个节点的连通性，也就是维护当前的最小生成树的状态
            dsu.merge(x, y);
            // 记录已经加入的边的数量
            cnt++;
            // 累加边权和
            ans += w;
        }
        // 按照题目要求打印答案
        cout << sum - ans << '\n';
    }
}

int main() {
    // 快读快写
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
```

### 七、实验总结及建议

一道最小生成树的模板题，最小生成树的贪心思想十分容易理解，难点在于带情景的题意理解。在边权和的计算中，由于边权和是`int`类型的累加，需要注意开`long long` 防止`int`溢出。在某些最小生成树有关的题目中，还存在一些不联通的图，需要在跑最小生成树算法的时候对这些情况进行判断。