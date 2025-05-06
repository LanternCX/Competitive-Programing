#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.cpp"
#else
#define debug(...) (void)(0)
#endif
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
void sol() {
    int n, k;
    cin >> n >> k;
 
    vector<int> v(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        v[i] = (a[i] > k ? -1 : 1);
        // 然后分3类情况讨论？
    }
 
    // "pre & suf" is 1 - indexed, However "v & a" array is 0 - indexed
    vector<int> pre(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + v[i - 1];
    }
    vector<int> suf(n + 2, 0);
    for (int i = n; i > 0; i--) {
        suf[i] = suf[i + 1] + v[i - 1];
    }
 
    // // debug part
    // out(v);
    // output(pre);
    // output(suf);
 
    bool chk = false;
    for (int i = 1; i <= n; i++) {
        if (pre[i] >= 0) {
            for (int j = i + 1; j <= n; j++) {
                if (pre[j] - pre[i] >= 0) {
                    chk = true;
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (pre[i] >= 0) {
            for (int j = n; j > i; j--) {
                if (suf[j] >= 0) {
                    chk = true;
                    break;
                }
            }
        }
    }
    for (int i = n; i > 0; i--) {
        if (suf[i] >= 0) {
            for (int j = i - 1; j > 0; j--) {
                if (suf[j] - suf[i] >= 0) {
                    chk = true;
                    break;
                }
            }
        }
    }
    
    cout << (chk ? "YES" : "NO") << "\n";
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
/**
 * 二值化
 * 大于 k 的 等于 -1
 * 小于 k 的 等于 1
 * 
 * 如果一个分割的中位数 < k
 * 那么这个分割求和 >= 0
 * 
 * 至少 两段的中位数 < k, 也就是至少两段的和 >= 0
 * 
 * 首先第一段前缀和 >= 0
 * 第二段的和其实是 (sum - pre[l] - suf[r]) >= 0
 * 所以我们可以找到每一个满足条件的 pre[l], 如果 (sum - max(suf[r]) - pre[l]) >= 0 那就是 YES
 * 
 * 这个过程从后往前和从前往后都需要一遍
 * 
 * 这样就处理了两种情况也就是 中位数 < k 的两个分割连续出现在开头和末尾
 * 
 * 还有出现在 只有开头和只有末尾的情况
 * 直接找到 pre > 0 的第一个位置 l 和 suf < 0 的第一个位置 r
 * 判断 l < r
 * 
 */