#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int a[10001], b[10001], g[10001], k[10001];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
    }
    int x, y;
    scanf("%d %d", &x, &y);
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int x1 = a[i], y1 = b[i], x2 = a[i] + g[i], y2 = b[i] + k[i];
        if (x >= x1 && y >= y1 && x <= x2 && y <= y2) {
            ans = fmax(ans, i + 1);
        }
    }
    printf("%d", ans);
    return 0;
}