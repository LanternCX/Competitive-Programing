#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// caoxin

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m)) {
        if (n == m && m == 0) {
            break;
        }
        int a[100], b[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d", b + i);
        }

        int ans[100];

        int idx = -1;

        for (int * p = a; p < a + n; p++) {
            int flag = 0;
            for (int * q = b; q < b + m; q++) {
                if (*p == *q) {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                ans[++idx] = *p;
            }
        }

        if (idx == -1) {
            printf("NULL");
        } else {
            qsort(ans, idx + 1, sizeof(int), cmp);
            for (int i = 0; i <= idx; i++) {
                printf("%d ", ans[i]);
            }
        }
        printf("\n");
    } 
    return 0;
}