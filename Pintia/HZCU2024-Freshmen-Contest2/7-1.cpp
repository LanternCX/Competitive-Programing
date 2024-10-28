#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
        a[i] %= 10;
    }

    vector<int> mod(10, -1);
    int ans = 0;

    mod[0] = 0;

    for (int i = 1; i <= n; i++) {
        int idx = a[i];
        if (mod[idx] != -1) {
            ans = max(ans, i - mod[idx]);
        } else {
            mod[idx] = i;
        }
    }

    cout << ans << '\n';
    return 0;
}
