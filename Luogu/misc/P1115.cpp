#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    int mn = 0, ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        ans = max(ans, pre[i] - mn);
        mn = min(mn, pre[i]);
    }

    cout << ans;
    return 0;
}
