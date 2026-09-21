#include <stdio.h>

// caoxin

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += i;
        }
        printf("%d\n\n", ans);
    }
    return 0;
}