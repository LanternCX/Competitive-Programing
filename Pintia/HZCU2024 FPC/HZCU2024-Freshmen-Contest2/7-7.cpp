#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }

    vector<int> a(n-1), b(n-1), c(n-1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<ll> sum(n);
    for(int i = 0; i < m - 1; i++) {
        sum[max(p[i], p[i + 1]) - 1]--;
        sum[min(p[i], p[i + 1]) - 1]++;
    }

    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        sum[i] += (i > 0 ? sum[i - 1] : 0);
        ans += min(sum[i] * a[i], sum[i] * b[i] + c[i]);
    }

    cout << ans;
    return 0;
}
