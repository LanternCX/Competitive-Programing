#include <stdio.h>
#include <math.h>

// caoxin

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF) {
        int is_found = 0;
        for (int i = m; i <= n; i++) {
            int x = i / 100;
            int y = i / 10 - x * 10;
            int z = i % 10;
            // printf("%d %d %d %d\n", i, x, y, z);
            int res = pow(x, 3) + pow(y, 3) + pow(z, 3);
            if (i == res) {
                printf("%d ", i);
                is_found = 1;
            }
        }
        if (!is_found) {
            printf("no\n");
        }
    }
    return 0;
}
// 31 + 28 + 12