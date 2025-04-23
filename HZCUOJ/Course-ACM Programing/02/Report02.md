**题目：**How Many Tables

**OJ平台判题结果：**   AC

### 一、问题描述

Today is Ignatius' birthday. He invites a lot of friends. Now it's dinner time. Ignatius wants to know how many tables he needs at least. You have to notice that not all the friends know each other, and all the friends do not want to stay with strangers.

One important rule for this problem is that if I tell you A knows B, and B knows C, that means A, B, C know each other, so they can stay in one table.

For example: If I tell you A knows B, B knows C, and D knows E, so A, B, C can stay in one table, and D, E have to stay in the other one. So Ignatius needs 2 tables at least.

题目大意：有若干个人相互之间有朋友关系，朋友关系可以传递，相互有朋友关系的人坐一桌，问最少需要几张桌子。

**输入格式**：

The input starts with an integer T(1<=T<=25) which indicate the number of test cases. Then T test cases follow. Each test case starts with two integers N and M(1<=N,M<=1000). N indicates the number of friends, the friends are marked from 1 to N. Then M lines follow. Each line consists of two integers A and B(A!=B), that means friend A and friend B know each other. There will be a blank line between two cases.

输入的第一行为一个整数 T (1 ≤ T ≤ 25)，表示测试用例的个数。
接下来是 T 组测试数据。每组测试数据开始包含两个整数 N 和 M (1 ≤ N, M ≤ 1000)，
其中 N 表示朋友的数量（编号为 1 到 N），M 表示接下来的 M 行关系。
每一行包含两个整数 A 和 B (A ≠ B)，表示 A 和 B 互相认识。每两个测试用例之间会有一个空行。

**输出格式**：

对于每组测试数据，输出至少需要的桌子数。输出时不要输出空格。

**输入样例**：

```
2
5 3
1 2
2 3
4 5

5 1
2 5
```

**输出样例**：

```
2
4
```

### 二、数据结构定义与分析

本次实验中定义了以下 1 个数据结构，（包含 2 个成员变量和 3 个成员函数）:

- `DSU`:

  ​		成员变量

  - `fa`：并查集的 `fa` 数组，其中 `fa[i] = j` 表示下标为 `i`的父亲下标 `j`

  - `n`：并查集的大小

  - `b`：病人优先级 B

    成员方法

  - `int find(int x)`：递归查找下标为 x 的元素的父亲并进行路径压缩，其中 x 为查询的下标

  - `void merge(int x, int y)`：将下标为 x 和下标为 y 的元素合并，其中 x 和 y 为需要合并的下标

  - `int root(void)`： 查询并查集中维护的集合数量，也就是根的数量

本次实验中定义了以下 5 个变量:

- `t`：测试用例的数目（整形变量）
- `n, m`：人的数量和关系的数量（整形变量）
- `a, b`：两个互相有朋友关系的人（整形变量）

### 三、算法分析

由于每个人相互之间有朋友关系，很容易想到用一个树形结构维护每个人相互之间的朋友关系。

又注意到相互之间的朋友关系可以传递，也就是说可以通过这些关系维护若干个独立的集合，集合的数量就是答案。

这和并查集的性质很像，容易想到使用并查集这种数据结构维护相互之间的关系，然后并查集维护的集合数量就是答案。

对于并查集的实现，一般采用 fa 数组维护一个树形结构，其中 `fa[i] = j` 表示下标为 `i`的父亲下标 `j`。

通过简单的推导可以知道，合并两个树形结构表示的集合其实就是将一棵树的根连接到另一棵树的根上。其中查询元素的根操作可以用递归实现。

为了优化时间复杂度，可以引入路径压缩，也就是将所有元素直接连接到根上。这种方法有效避免了递归深度过大带来的时间复杂度问题。

可以知道，在使用带路径压缩的并查集算法之后，时间复杂度在题目要求的范围内。

### 四、测试用例设计及测试结果

#### 1. 样例测试

**输入：**

```
2
5 3
1 2
2 3
4 5

5 1
2 5
```

**预期输出：**

```
2
4
```

**实际输出：**



#### 2. 所有人互不认识

**输入：**

```
1
4 0
```

**预期输出：**

```
4
```

**实际输出：**



#### 3. 所有人互相认识

```
1
4 3
1 2
2 3
3 4
```

**预期输出：**

```
1
```

**实际输出：**



#### 4. 多组朋友各自成团

**输入：**

```
1
6 3
1 2
3 4
5 6

```

**预期输出：**

```
3
```

**实际输出：**



#### 5. 最大 N

**输入：**

```
1
1000 0

```

**预期输出：**

```
1000
```

**实际输出：**



从以上测试当中可以检验出程序的完备性

### 五、存在问题及可能原因

1. 并查集实现问题

  问题：并查集未初始化或者初始化错误

  原因：并查集初始化需要将每个节点的根设置为自己

2. 下标问题

  问题：下标过大引起的访问越界

  原因：并查集使用 0 开头下标但是输入的数据使用的是 1 开头下标，需要进行下标的转换

3. 没有使用路径压缩

  问题：并查集查询时间复杂度过大

  原因：并查集算法中没有使用路径压缩算法导致递归调用栈过长使得时间复杂度超出限制

### 六、附源代码以及代码相应注释

```c++
#include <bits/stdc++.h>
using namespace std;
// 并查集封装
struct DSU {
    // fa[i] = j 表示下标为 i 的父亲下标 j
    vector<int> fa;
    // 并查集大小
    int n;

    /**
     * @param size 并查集大小
     */
    DSU(int size): n(size), fa(size) {
        // 初始化所有元素的父亲节点为自己
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };

    /**
     * 递归查找下标为 x 的元素的父亲并进行路径压缩
     * @param x 查询的下标
     */
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    /**
     * 将下标为 x 和下标为 y 的元素合并
     * @param x 需要合并的下标 x
     * @param y 需要合并的下标 y
     */
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    /**
     * 查询下标为 x 的元素和下标为 y 的元素是否属于同一个集合
     * @param x 需要查询的下标 x
     * @param y 需要查询的下标 y
     */
    bool query(int x, int y){
        return find(x) == find(y);
    }

    /**
     * 查询并查集中维护的集合数量，也就是根的数量
     */
    int root(void){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == i){
                res++;
            }
        }
        return res;
    }
};
void sol(){
    // 按题目要求输入 n, m
    int n, m;
    cin >> n >> m;
    // 初始化并查集
    DSU dsu(n);
    for(int i = 0; i < m; i++){
        // 按题目要求输入需要合并的 a, b
        int a, b;
        cin >> a >> b;
        // 对齐到 0 开头下标
        a--, b--;
        // 执行合并操作
        dsu.merge(a, b);
    }
    // 打印答案
    cout << dsu.root() << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
```

### 七、实验总结及建议

一道并查集的模板题，主要测试的是选手的数据结构基础能力。在实现并查集的时候，对于并查集算法进行适当的封装可以提高代码的可读性和可复用性。在较为复杂的题目中，可能会出现使用多个并查集维护数据的情况，使用并查集封装可以维护较好的代码结构。对于并查集算法本身而言，多用于求联通问题，在图上问题中的应用较多。