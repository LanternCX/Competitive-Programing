#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void sol() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (int i = 0; i < m; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    ll ans = 0;
    for (int i = 1; i <= n - 1; ++i) {
        auto it1 = lower_bound(arr.begin(), arr.end(), i);
        auto it2 = lower_bound(arr.begin(), arr.end(), n - i);
        ans += (arr.end() - it1) * (arr.end() - it2);
        ans -= arr.end() - (i > n - i ? it1 : it2);
    }
    cout << ans << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--){
        sol();
    }
    return 0;
}