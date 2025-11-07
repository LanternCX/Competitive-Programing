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
struct DSU {
    vector<int> fa;
    int n;
    DSU(int size) : n(size), fa(size) {
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    };

    int find(int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        fa[find(x)] = fa[find(y)];
    }

    bool query(int x, int y) {
        return find(x) == find(y);
    }

    int root(void) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (fa[i] == i) {
                res++;
            }
        }
        return res;
    }
};
struct edge {
    int i, j, w;  
    int operator< (const edge a) const {
        return w > a.w;
    } 
};
void sol() {
    int n;
    cin >> n;
    priority_queue<edge, vector<edge>> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w != 0) {
                pq.push({i, j, w});
            }
        }
    }
    int q;
    cin >> q;
    DSU dsu(n + 1);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        dsu.merge(a, b);
    }
    int cnt = 0;
    ll ans = 0;
    while (!pq.empty()) {
        auto [i, j, w] = pq.top();
        pq.pop();
        if (!dsu.query(i, j)) {
            cnt++;
            ans += w;
            dsu.merge(i, j);
        }
        if (cnt == n - 1) {
            break;
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}