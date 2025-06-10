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
    int v, idx;
};
void sol(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    vector<int> idx(n);
    for (int i = 0; i < n; i++) {
        idx[a[i]] = i;
    }
    string ans(n, ' ');
    for (int x = n - 1; x >= 0; x--) {
        int now = idx[x];
        ans[now] = 'B';
        int nxt;
        nxt = now;
        while (1) {
            nxt -= (x + 1);
            if (nxt < 0) {
                break;
            }
            if (ans[nxt] == 'B') {
                ans[now] = 'A';
                break;
            }
        }
        nxt = now;
        while (1) {
            nxt += (x + 1);
            if (nxt >= n) {
                break;
            }
            if (ans[nxt] == 'B') {
                ans[now] = 'A';
                break;
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--){
        sol();
    }
    return 0;
}