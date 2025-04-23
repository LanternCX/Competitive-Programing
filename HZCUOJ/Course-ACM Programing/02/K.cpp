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