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
struct node {
    int x;
    int dis;
};
void sol(){
    int n;
    cin >> n;
    vector<node> arr;
    int idx = 0;
    vector<int> vis(n + 1);
    // 查找 now 到没有 vis 的块的 max len
    auto find = [&](int now) {
        // 找到 len 等于 mx - 1 的起点
        cout << "? " << now << ' ';
        vector<int> q;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                q.push_back(i);
            }
        }
        cout << q.size() << ' ';
        for (auto x : q) {
            cout << x << ' ';
        }
        cout << '\n';
        int x;
        cin >> x;
        return x;
    };

    // 查询 now 直接联通的边
    auto check = [&](int now) {
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && i != now) {
                cout << "? " << now << ' ';
                cout << 2 << ' ';
                cout << i << ' ';
                cout << now << ' ';
                cout << '\n';
                int x;
                cin >> x;
                if (x == 1) {
                    res.push_back(i);
                }
            }
        }
        return res;
    };

    int pre = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            int x = find(i);
            if (x > mx) {
                mx = x;
                pre = i;
            }
        }
    }
    vector<int> ans = {pre};

    while (1) {
        vis[pre] = 1;
        for (auto i : check(pre)) {
            int x = find(i);
            if (x == mx - 1) {
                mx = x;
                pre = i;
                ans.push_back(pre);
                break;
            }
        }
        debug("loop");
        if (mx == 0) {
            break;
        }
    }
    cout << "! ";
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}
int main(){
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * 
 */