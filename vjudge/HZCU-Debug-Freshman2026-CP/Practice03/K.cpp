#include <stdio.h>

int main() {
    int n;
    int a[30][30] = {0};

    for (int i = 0; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
    }

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j > 0) {
                    printf(" ");
                }
                printf("%d", a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}