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
void sol(){
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> arr;
    int cnt = 1;
    char now = s[0];
    for (int i = 1; i < n; i++) {
        char ch = s[i];
        if (ch == now) {
            cnt++;
        } else {
            arr.push_back(cnt);
            cnt = 1;
            now = ch;
        }
    }
    while (q--) {
        int x;
        cin >> x;
        if (s[0] == 'A') {
            int ans = 0;
            int idx = 0;
            while (x) {
                if (idx % 2 == 0) {
                    ans += min(x, arr[idx]);
                    x -= min(x, arr[idx]);
                } else {
                    for (int i = 0; i < arr[idx]; i++) {
                        x /= 2;
                        ans++;
                        if (x <= 0) {
                            break;
                        }
                    }
                }
                idx++;
                idx %= arr.size();
            }
            cout << ans << '\n';
        }
        if (s[0] == 'B') {
            int ans = 0;
            int idx = 0;
            while (x) {
                if (idx % 2 == 1) {
                    ans += min(x, arr[idx]);
                    x -= min(x, arr[idx]);
                } else {
                    for (int i = 0; i < arr[idx]; i++) {
                        x /= 2;
                        ans++;
                        if (x <= 0) {
                            break;
                        }
                    }
                }
                idx++;
                idx %= arr.size();
            }
            cout << ans << '\n';
        }
    }
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