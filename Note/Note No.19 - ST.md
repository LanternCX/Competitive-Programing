# ACM Note No.19: ST

ST表(Sparse Table)，是解决可重复贡献问题的区间查询的数据结构，可以做到时间复杂度`O(NlogN)`的预处理和`O(1)`的查询。

- **可重复贡献问题**：对于运算`opt`满足`x opt x == x`（例如`max(x, x) == x`）则对应的区间询问就是一个可重复贡献问题。较为常见的`opt`有`max gcd and or`等等

ST表基于倍增思想实现，下面给出一个ST表的模板

```c++
template <typename T>
struct ST {
    using fun = function<T(T &, T &)>;
    // ST表，st[i][j] 代表从 arr[i] 向后长度为 2^j - 1 的区间的计算结果
    vector<vector<T>> st;
    // 可重复贡献问题的操作，例如 max gcd 等等，默认为 max
    fun op;
    ST(vector<T> arr, fun f = [](T a, T b){ return max(a, b); }) {
        // 初始化变量
        op = f;
        int n = arr.size(), LOG = ceil(log2(n)) + 1;
        st = vector<vector<T>>(n, vector<T>(LOG));
        
        // 初始化，op(arr[i], arr[i]) == arr[i]，因此 s[i][0] = arr[i]
        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }
        
        for (int j = 1; j < LOG; j++) {
            // 步长 2^(j - 1)
            int t = (1 << (j - 1));
            // 对每个点处理所有步长
            for (int i = 0; i + t < n; i++) {
                // 以最大值为例：
                // arr[i] 向后长度为 2^j 的区间的最大值
                // 等于 arr[i] 向后长度为 2^(j - 1) - 1 的区间 和 arr[i] 向后长度为 2^(j - 1) 再向后长度为 2^(j - 1) 的区间的最大值
                // 例如 arr[0] 向后长度为 8 的区间的最大值，也就是区间 [0, 8] 的最大值
                // 等于 [0, 3] 和 [4, 8] 两个区间最大值的最大值
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        // 例如查询区间 [2, 12]
        // t = 3
        int t = floor(log2(r - l + 1));
        // 那么最大值就是 [2, 2 + 8] 和 [12 - 8，12] 两段的最大值
        // 也就是说 ST 表的查询实际上把一个区间长度为 len 的查询拆分成两段 2 的幂次长度的查询，以此做到 O(1) 的查询
        return op(st[l][t], st[r - (1 << t) + 1][t]);
        
    }
};
```

