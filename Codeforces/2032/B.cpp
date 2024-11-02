#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1) {
        cout << "1\n1\n";
        return;
    }
    for (int i = 0; i * 2 + 1 <= n - 2; i++) {
        int left = k - i;
        int right = k + i;

        if ((left - 1) % 2 == 1 && ((n - right) % 2 == 1)) {
            cout << "3\n" << 1 << ' ' << left << ' ' << right + 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
/**
 * [1 2 3 4 5 6 7] [8] [9 10 11 12 13 14 15]
 */