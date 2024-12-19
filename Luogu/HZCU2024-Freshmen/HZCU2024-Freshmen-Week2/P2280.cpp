#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
int a[5010][5010];
int s[5010][5010];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        a[x + 1][y + 1] = v;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    int ans = 0;

    for (int i = m; i <= N; i++) {
        for (int j = m; j <= N; j++) {
            int sum = s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m];
            ans = max(ans, sum);
        }
    }

    cout << ans << '\n';
    return 0;
}