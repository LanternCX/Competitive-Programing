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
    int x, y;
    cin >> x >> y;
    vector<ll> arr = {x, y};
    for (int i = 2; i < 10; i++) {
        ll sum = arr[i - 1] + arr[i - 2];
        string s = to_string(sum);
        reverse(s.begin(), s.end());
        arr.push_back(stoll(s));
    }
    cout << arr[9] << '\n';
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