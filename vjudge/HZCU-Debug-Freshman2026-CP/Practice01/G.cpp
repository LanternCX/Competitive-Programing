#include <stdio.h>

// caoxin

// 4 100 400

int main() {
    int y, m, d;
    while (scanf("%d/%d/%d", &y, &m, &d) != EOF) {
        int is_run = 0;
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            is_run = 1;
        }
        int ans = d;
        for (int i = 1; i <= m - 1; i++) {
            if (i == 2) {
                if (is_run) {
                    ans += 29;
                } else {
                    ans += 28;
                }
            } else if (i == 1 
                || i == 3 
                || i == 5 
                || i == 7 
                || i == 8 
                || i == 10 
                || i == 12
            ) {
                ans += 31;
            } else {
                ans += 30;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
