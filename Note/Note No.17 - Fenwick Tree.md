# ACM Note No.17: Fenwick Tree

**树状数组**（Fenwick Tree, Binary Indexed Trees, BIT）是一种能够快速修改并查询数组前缀和的数据结构。

从树状数组的英文名 **Binary Indexed Trees** 或许更好理解，树状数组的索引值与修改位的二进制形式有关。

[BV1ce411u7qP](https://www.bilibili.com/video/BV1ce411u7qP/) 树状数组的原理可以从线段树的原理优化精简得到

[BV1gABEYMEqj (2:40 - 15:10)](https://www.bilibili.com/video/BV1gABEYMEqj/) 从另一个角度出发，如果需要对信息进行修改，使用分治的方法在前缀和数组的基础上进行修改，将前缀和数组原本每位都存储前`n`个元素的前缀和变成每一位只存储一部分区间和，在查询的时候将不同的区间和组合加和，这样修改的时候就不需要修改前缀和数组的前`n`位了。虽然牺牲了前缀和和`O(1)`复杂度的查询，但是却可以把修改之后重新求前缀和这个操作的复杂度降低到`log(n)`。

下面给出树状数组的实现模板

```c++
using ll = long long;
template<typename T> struct Fenwick{
    int n;
    vector<T> tr;
    // 树状数组的索引从 1 开头，这样操作起来更为方便
    Fenwick(int size): n(size), tr(size + 1){}
    
    // 返回函数的最低有效位，例如lowbit(8) = lowbit(1000) = 8
    int lowbit(int x){
        return x & -x;
    }
    
    // 修改点值
    void add(int idx, T val){
        // 向后更新，步进为 lowbit(i)
        for(int i = idx; i <= n; i += lowbit(i)){
            tr[i] += val; 
        }
    }
    
    // 求该点的前缀和
    T query(int idx){
        T res = T();
        // 向前查询并加和，步进为 lobit(i)
        for(int i = idx; i > 0; i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }
    
    // 查询区间和
    T query(int l, int r){
        return query(r) - query(l - 1);
    }
};
using BIT = Fenwick<ll>;
```

### 例题

[Luogu P3374 【模板】树状数组 1](https://www.luogu.com.cn/problem/P3374)

树状数组的一个较为直接的应用就是实现数组的前缀和`log(n)`的修改与查询

```c++
#include <bits/stdc++.h>
using namespace std;
// Fenwick Tree Template
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    BIT bit(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        bit.add(i + 1, arr[i]);
    }
    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int x, k;
            cin >> x >> k;
            bit.add(x, k);
        }
        if(op == 2){
            int x, y;
            cin >> x >> y;
            cout << bit.query(x, y) << '\n';
        }
    }
    return 0;
}
```

[Luogu P3368 【模板】树状数组 2](https://www.luogu.com.cn/problem/P3368)

由前缀和自然可以联想到差分。差分数组做一遍前缀和就可以还原成原数组，因此可以用树状数组存储的差分数组进行`log(n)`复杂度区间修改与点值查询

```c++
#include <bits/stdc++.h>
using namespace std;
// Fenwick Tree Template
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1);
    BIT bit(n);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> diff(n + 1);
    for(int i = 1; i <= n; i++){
        diff[i] += arr[i] - arr[i - 1];
        bit.add(i, diff[i]);
    }

    while(m--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y, k;
            cin >> x >> y >> k;
            bit.add(x, k);
            bit.add(y + 1, -k);
        }
        if(op == 2){
            int x;
            cin >> x;
            cout << bit.query(x) << '\n';
        }
    }
    return 0;
}
```

[2025牛客寒假算法基础集训营6 - I](https://ac.nowcoder.com/acm/contest/95338/I)

题意：给定一个排列`p`，对于每组询问`l, r, idx`打印`p[idx]`在区间`[l, r]`内从小到大排序之后的下标

可以将区间计数转化为区间求和，通过动态维护树状数组解决一些区间计数问题

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// Fenwick Tree Template
struct node{
    int l, r, id;
};
void sol(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 1), pos(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        // arr[i] 的位置，由于是排列所以只需要存一个
        pos[arr[i]] = i;
    }

    vector<vector<node>> query(n + 1);
    for(int i = 0; i < m; i++){
        int l, r, x;
        cin >> l >> r >> x;
        // 离线存储 arr[x] 的查询
        query[arr[x]].push_back({l, r, i});
    }

    vector<int> ans(m);
    BIT bit(n);
    // 从小到大更新，此时树状数组中只有 <= i 的数的位置被更新，也就是说此时求得的区间和就是 <= i 的数的个数
    for(int i = 1; i <= n; i++){
        bit.add(pos[i], 1);
        for(auto nd : query[i]){
            int l = nd.l, r = nd.r, id = nd.id;
            int cnt = bit.query(l, r);
            int idx  = l + cnt - 1;
            ans[id] = idx;
        }
    }
    for(auto x : ans){
        cout << x << '\n';
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        sol();
    }
}
```

