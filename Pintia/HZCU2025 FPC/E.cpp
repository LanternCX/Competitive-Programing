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
    int a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    pair<char, int> ans;
    map<int, int> cnt;
    int tag = 0;
    for (int i = 0; i < n; i++) {
        vector<int> arr(4);
        for (auto &x : arr) {
            cin >> x;
        }
        int sum = arr[0] + arr[2];
        if (sum == arr[1] && sum == arr[3]) {
            continue;
        }
        if (arr[0] + arr[2] == arr[1]) {
            a--;
            cnt[0]++;
        } else if (arr[0] + arr[2] == arr[3]) {
            b--;
            cnt[1]++;
        }
        if (a < 0 && !tag) {
            tag = 1;
            ans = {'A', cnt[1]};
        }
        if (b < 0 && !tag) {
            tag = 1;
            ans = {'B', cnt[0]};
        }
    }
    cout << ans.first << '\n' << ans.second;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while (t--) sol();
    return 0;
}

/**
1 1
6
8 10 9 12 17
5 10 5 10 10
3 8 5 12 8
12 18 1 13 
4 16 12 15
15 1 1 16
 */