# ACM Note No.8: Manacher

马拉车算法可以用于解决**最长回文子串**的问题

当然也可以通过对下文的**回文半径数组P**求和，以获得**回文子串的总数**

```cpp
#include <bits/stdc++.h>
using namespace std;
string manacher(const string& s) {
    // 步骤 1: 在原字符串中插入特殊字符 '#'，以统一处理奇偶回文串
    string T = "#";
    for (char c : s) {
        T += c;
        T += "#";
    }
    int n = T.length();
    // 回文半径数组
    vector<int> P(n, 0);  
    // 当前回文中心和右边界
    int C = 0, R = 0;
    // 最长回文的长度和中心位置
    int maxLen = 0, centerIndex = 0; 
    // 步骤 2: 遍历字符串进行回文扩展
    for (int i = 0; i < n; ++i) {
        // 步骤 3: 利用对称性初始化P[i]
        if (i < R) {
            P[i] = min(R - i, P[2 * C - i]);  // 对称位置的回文半径
        }
        // 步骤 4: 尝试扩展回文
        while (i + P[i] + 1 < n && i - P[i] - 1 >= 0 && T[i + P[i] + 1] == T[i - P[i] - 1]) {
            P[i]++;
        }
        // 步骤 5: 更新C和R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
        // 步骤 6: 更新最大回文长度和中心
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    // 步骤 7: 从回文半径数组中恢复最长回文子串
    // 计算原字符串中的起始位置
    int start = (centerIndex - maxLen) / 2;  
    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;
    string result = manacher(s);
    cout << "Longest Loop String: " << result << endl;
    return 0;
}

```

