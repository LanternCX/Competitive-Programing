#include <bits/stdc++.h>
using namespace std;

int a[200][200];
int s[200][200];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = -1e7;

    for (int i1 = 1; i1 <= n; i1++) {
        for (int j1 = 1; j1 <= n; j1++) {
            for (int i2 = i1; i2 <= n; i2++) {
                for (int j2 = j1; j2 <= n; j2++) {
                    int sum = s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1];
                    ans = max(ans, sum);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
