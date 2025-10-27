# ACM Note No.21: KMP

KMP 是一种用来匹配最长相等的真前缀串和真后缀串的方法。

我们首先定义失配数组（又叫前缀数组）`fail[i]` 为字符串 `s` 的子串 `s[0 ... i]` 的最长相等的真前缀串和真后缀串的长度

如何计算这个数组，我们可以注意到两个优化：

第一个优化，我们注意到对于当前的检查的下标 `i`， `pi[i]` 至多比 `pi[i - 1]` 大一，因此我们可以考虑通过分类讨论从 `pi[i - 1]` 转移。我们令 `j` 为前缀串最后一个字符的下一个字符，`i` 为后缀串最后一个字符的下一个字符，如果 `s[i] == s[j]`，我们就可以直接从 `pi[i - 1]` 转移到 `pi[i - 1] + 1`

当然有不能直接转移到情况，这时候我们就要用到第二个优化。

第二个优化，对于不能转移的情况，就需要找到次长相等前后缀串。我们先将注意力放到下标 `i - 1` 的最长相等前后缀串的前缀串。我们注意到这个串的最长相等前后缀串的后缀串，实际上就是下标 `i - 1` 的最长相等前后缀串的后缀串的次长相等前后缀串的后缀串。

![img](https://oi-wiki.org/string/images/prefix_str_3.svg)

因此我们可以在这个性质上进行状态转移，也就是在 `pi[]` 上进行动态规划。

通过这两个优化，我们就能将 `pi` 数组的计算优化到 `O(n)`

我们也可以通过这个计算方法，在一个字符串中查找另一个字符串的子串。

例如查找的子串为 `S` ，被查找的串为 `T` 那么我们可以构造 `S#T` 其中 `#` 为在两个串中均未出现的字符。

然后计算 `S#T` 的 `pi` 数组，如果 `pi[i] == S.length()` 则成功匹配子串。 

```c++
#include <bits/stdc++.h>
using namespace std;

template<class T>
struct KMP {
    const T s;
    int n;
    vector<int> pi;

    KMP(const T &s) : s(s), n((int)s.size()), pi(n) {
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
          	// 不满足第一个优化条件的情况：s[i] != s[j]
        		// DP, 如果不满足第一个优化的条件就使用第二个优化条件进行状态转移
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
          	// 第一个优化条件：s[i] == s[j] 
        		// 状态转移结束后检查第一个优化条件
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
    }

    vector<int> match(const T &t) {
        int m = (int)t.size();
        vector<int> res;
        int j = 0;
        for (int i = 0; i < m; i++) {
            while (j > 0 && t[i] != s[j]) j = pi[j - 1];
            if (t[i] == s[j]) j++;
            if (j == n) {
                res.push_back(i - n + 1);
                j = pi[j - 1];
            }
        }
        return res;
    }
};

```

