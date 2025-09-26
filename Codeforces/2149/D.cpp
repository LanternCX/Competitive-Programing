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
void sol(){
    int n;
    string s;
    cin >> n >> s;
    auto work = [&](string s, char ch) -> ll {
        vector<int> p;
        for (int i = 0; i < n; i++) {
            if(s[i] == ch) {
                p.push_back(i);
            }
        } 
        if (p.empty()) {
            return 0;
        }
        int m = p.size();
        vector<int> q(m);
        for(int i = 0; i < m; i++) {
            q[i] = p[i] - i;
        } 
        int mid = q[m / 2];
        int res = 0;
        for(int i = 0; i < m; i++) {
            res += llabs(q[i] - mid);
        }
        return res;
    };
    cout << min(work(s, 'a'), work(s, 'b')) << '\n';
}
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}
/**
 * abbbbbbba
 * 
 * 相当于一个找重心的问题
 * 找到一个中心使得所有的 a 到这个位置的距离之和最短
*/