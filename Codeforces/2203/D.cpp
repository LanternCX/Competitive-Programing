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

#define int ll

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(int a, int b){return (a * b) / gcd(a, b);}

void sol() {
    int n, m;
    cin >> n >> m; 
    vector<ll> a(n), b(m);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    
    ll l = 1;
    
    for (int i = 0; i < n; i++) {
        ll g = gcd(l, a[i]);
        l = lcm(l, a[i]);
    }
    
    int c_A = 0, c_B = 0, c_AB = 0;
    
    for (auto y : b) {
        if (y % l == 0) {
            c_A++;
        } else {
            bool div_by_any = false;
            for (auto x : a) {
                if (y % x == 0) {
                    div_by_any = true;
                    break;
                }
            }
            
            if (!div_by_any) {
                c_B++;
            } else {
                c_AB++;
            }
        }
    }
    
    if (c_A + (c_AB % 2) > c_B) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}
/**
 * 可以分为三类：
 * a 能选但是 b 不能选
 * b 能选但是 a 不能选
 * ab 都可以选
 * 
 * 所以策略就是争夺 ab 都能选的
 * 
 * 于是实际上就是吧这三类分出来就好了
 * 
 * 我们只考虑一个数组
 * 
 * 对于 b 中的任意一个 y：
 * A：数组存在至少一个 x 能整除 y
 * B：数组存在至少一个 x 不能整除 y
 * 
 */