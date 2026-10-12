#include <stdio.h>
#include <math.h>

int a[100 + 10][100 + 10];

int main() {
    int m, n;
    while (scanf("%d %d", &n, &m) != EOF) {
        int x = -1, y = -1, max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);

                if (abs(a[i][j]) > max) {
                    max = abs(a[i][j]);
                    x = i;
                    y = j;
                }
            }
        }
        printf("%d %d %d", x + 1, y + 1, a[x][y]);
    }

    return 0;
}