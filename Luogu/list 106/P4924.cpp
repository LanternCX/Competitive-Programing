#include <bits/stdc++.h>
using namespace std;

int main() {
    int an[505][505];
    int temp[505][505];
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;

    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            an[i][j] = num++;
        }
    }

    for (int k = 0; k < m; k++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                temp[i][j] = an[i][j];
            }
        }

        for (int i = -r; i <= r; i++) {
            for (int j = -r; j <= r; j++) {
                int x1 = x + i; 
                int y1 = y + j;

                int x2, y2;

                if (z == 0) {
                    x2 = x + j;
                    y2 = y - i;
                } else {
                    x2 = x - j;
                    y2 = y + i;
                }

                temp[x2][y2] = an[x1][y1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                an[i][j] = temp[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << an[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
