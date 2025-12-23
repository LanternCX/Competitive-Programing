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
    char op;
    ll step;
};
map<char, char> rev;
set<char> xmove;
set<char> ymove;
void sol() {
    vector<pii> p(2);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }

    ll n;
    int m, l;
    cin >> n >> m >> l;
    vector<vector<node>> move(2);
    for (auto &arr : move) {
        ll tot = 0;
        while (tot < n) {
            node nd;
            auto &[op, step] = nd;
            cin >> op >> step;
            if (step < 0) {
                op = rev[op];
                step = abs(step);
            }
            arr.push_back(nd);
            tot += step;
        }
    }

    auto cut = [&](int i, int j) {
    };

    // 对齐后的新队，每一步步长都一样
    vector<vector<node>> cal(2);
    int i = 0, j = 0;
    while (i < move.size() || j < move.size()) {
        // 0 全部加入，1 加入部分
        if (move[0][i].step < move[1][j].step) {
            // 加入
            cal[0].push_back(move[0][i]);
            cal[1].push_back({move[1][j].op, move[0][i].step});
            // 在 1 减去
            move[1][j].step -= move[0][i].step;
            // 更新下标
            i++;
            j = j;
        }

        // 0 加入部分，1 全部加入
        if (move[0][i].step > move[1][j].step) {
            // 加入
            cal[0].push_back({move[0][i].op, move[1][j].step});
            cal[1].push_back(move[1][j]);
            // 在 0 减去
            move[0][i].step -= move[1][j].step;
            // 更新下标
            i = i;
            j++;
        }
        
        // 两者同时加入
        if (move[0][i].step == move[1][j].step) {
            cal[0].push_back(move[0][i]);
            cal[1].push_back(move[1][j]);
            i++;
            j++;
        }
    }

    assert(cal[0].size() == cal[1].size());

    auto calc = [&](pii a1, pii b1, pii a2, pii b2) {

    };
    int siz = cal[0].size();
    int ans = 0;
    for (int i = 0; i < siz; i++) {
        auto &[opa, da] = cal[0][i];
        auto &[opb, db] = cal[1][i];
        auto &[ax, ay] = p[0];
        auto &[bx, by] = p[1];
        
    }
}

void init () {
    rev['U'] = 'D';
    rev['D'] = 'U';
    rev['R'] = 'L';
    rev['L'] = 'R';
    
    xmove = set<char>({'L', 'R'});
    ymove = set<char>({'U', 'D'});
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
/**
 * 只能离散处理
 * 什么情况一定会相遇？
 * 
 * 首先就是 a 步数多就等待 b
 * 相反也是
 * 
 * 也就是第一步就是对齐
 * 起点对齐，然后终点对齐
 * 
 * 
 * 对齐之后如何判断相遇？
 * 
 * 对齐之后
 * 
 * 对于 x y 的情况
 * xi, yi
 * xj, yj
 * dx, dy
 * 
 * mx, my
 * 
 * dx = dy && (dx < mx && dy < my)
 * 
 * 对于 x x / y y 的情况
 * dxi + dyi
 */