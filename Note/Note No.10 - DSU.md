# ACM Note No.10: DSU

**并查集**（DSU， Disjoint Set Union），顾名思义是一种能高效**合并**两个集合并**查询**某个数属于哪一个集合的数据结构，在处理连通分量（连通块）问题方面应用十分广泛

并查集实现的为一个森林，其核心思想有二：

1. 将每个集合构建为一颗树
2. 合并两个集合就是将将一颗树的根接到另一颗树的根上

这里给出一个并查集的封装，带路径压缩不带启发式合并

```c++
struct DSU {
    // fa 数组是一个森林，存储的是每个节点的父节点
    vector<int> fa;
    int n;
    // 初始化
    DSU(int size) {
        n = size;
        fa = vector<int>(n);
        // 最开始 fa 数组的每个数的根指向自己
        for(int i = 0; i < n; i++){
            fa[i] = i;
        }
    };
    
    // 递归查找一个节点的根节点，并进行路径压缩
    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
    
    // 合并两个节点所在的集合
    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }
    
    // 查询两个节点是否属于同一个集合
    bool query(int x, int y){
        return find(x) == find(y);
    }
    
    // 查询根的数量（即连通块的数量）
    int root(void){
        int res = 0;
        for(int i = 0; i < n; i++){
            if(fa[i] == i){
                res += i;
            }
        }
        return res;
    }
};
```



