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
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    set<int> mp;
    for (auto x : a) {
        mp.insert(x);
    }
    vector<int> val;
    for (int x : mp) {
        val.push_back(x);
    }
    sort(val.begin(), val.end());
    int maxA = val.empty() ? 0 : val.back();

    map<int, int> can;
    for (int b : val) {
        ll need = k / b;
        if (need == 0) {
            can[b] = 0;
            continue;
        }

        ll cnt = 0;
        for (ll m = b; m <= maxA; m += b) {
            if (mp.find((int)m) != mp.end())
                cnt++;
        }
        can[b] = (cnt == need);
    }

    map<int, int> bad;
    for (int b : val) {
        if (!can[b])
            continue;
        for (ll m = 2LL * b; m <= maxA; m += b) {
            if (can.count(m)) {
                if (can[m]) {
                    bad[m] = 1;
                }
            }
        }
    }

    vector<int> ans;
    for (int b : val) {
        if (can[b] && !bad[b])
            ans.push_back(b);
    }

    set<int> mask;
    for (int b : ans) {
        for (ll m = b; m <= maxA; m += b) {
            if (mp.count(m)) {
                mask.insert(m);
            }
        }
    }

    int ok = 1;
    for (int x : a) {
        if (!mask.count(x)) {
            ok = 0;
            break;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
        return;
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}

/**
 * 对于第二条
 * 先不考虑 k 
 * 首先要满足 bi * 1 存在于 a
 * 那么 bi 就是 a 的子集
 * 
 * 也就是说可以使用类似筛法的方法去做
 * 
 * 筛完一定是满足第一条
 * 
 * 如果考虑 k 呢？
 * 首先我们可以将数组 a 分为两段 >k 和 <k
 * 
 * 对于 <k 我们可以直接筛
 * 
 * 对于大于 k 的这一段筛一遍，然后求 gcd？
 * 
 * emm
 * 
 * 所以可以对去重后的 a 进行类似筛法的处理，对每个可能的 b 枚举它的倍数
 * 检查所有 <=k 的倍数是否全部出现在 a 中，从而判断 b 是否满足条件2
 *
 * 满足条件2 的候选中，较小的数会覆盖掉倍数，因此在筛的时候可以更小的合法 b 所覆盖的候选打标记
 *
 * 筛完后剩下的 b 一定满足第二条，且必然是最小化的选择
 * 然后检查是否能覆盖所有 ai 从而保证第一条
 *
 * 不需要分 <k 或 >k貌似
 * 我们只需要检查到 maxa，其余倍数缺失会自动导致 b 不满足条件2
 * 
 * 好像是对的
 */