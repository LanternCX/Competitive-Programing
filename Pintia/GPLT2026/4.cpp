#include <bits/stdc++.h>

using namespace std;

void sol() {
    int a, b;
    cin >> a >> b;
    int ans = b - a;
    cout << ans << '\n';
    if (ans > 250) {
        cout << "jiu ting tu ran de...";
        return;
    }
    if (ans < 0) {
        cout << "hai sheng ma?";
        return;
    }
    cout << "nin tai cong ming le!";
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