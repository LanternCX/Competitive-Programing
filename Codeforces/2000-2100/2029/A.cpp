#include <bits/stdc++.h>
using namespace std;
void sol(){
    int l, r, k;
    cin >> l >> r >> k;
    int ans = max(0, r / k - l + 1);
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        sol();
    }
    return 0;
}