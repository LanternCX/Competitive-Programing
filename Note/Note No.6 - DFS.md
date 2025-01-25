# ACM Note No.6: DFS

深度优先搜索（DFS）常常用于解决图的连通性问题，暴力枚举问题等等

DFS常常用递归实现：

### P10448 组合型枚举

从`1∼*n* `这 `n`个整数中随机选出 `m`个，输出所有可能的选择方案。

```cpp
#include <bits/stdc++.h>
using namespace std;
int n, m;
void dfs(int now, vector<int> arr){
    // 判断DFS到达终点，打印答案
    if(arr.size() == m){
        for(int x : arr){
            cout << x << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 如果没有到达终点，枚举下一个数字
    for(int i = now; i <= n - (m - arr.size() - 1); i++){
        vector<int> temp = arr;
        temp.push_back(i);
        dfs(i + 1, temp);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    dfs(1, {});
    return 0;
}
```