# ACM Note No.16: Sqrt Decomposition

**数论分块**，是一种能在`O(sqrt(n))`复杂度下枚举`x / i`的值的算法

### 结论

满足式子`n / i == n / j`的`j`的最大值为`n / (n / i)`

也就是说下面这两段代码等价：

```c++
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    // Code A
    vector<int> a;
    for(int i = 1; i <= n ; i++){
        a.push_back(n / i);
    }
    
    // Code B
    vector<int> b;
    for(int i = 1, mx; i <= n; i = mx + 1){
        mx = n / (n / i);
        int val = n / i;
        for(int j = 0; j <= mx - i; j++){
            b.push_back(val);
        }
    }
    
    // Code A equals Code B
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ' << b[i] << '\n';
    }
    return 0;
}
```

实际上，在实际应用中，我们并不需要像上文`Code B`一样在第二层循环进行枚举，只需要保留最外层循环，算出每种因数的个数即可