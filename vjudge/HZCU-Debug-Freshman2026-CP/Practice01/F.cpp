#include <stdio.h>

// caoxin

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            ans *= x % 2 ? x : 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}