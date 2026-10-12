#include <stdio.h>
#include <math.h>

int a[100 + 10];

int main() {
    int n, m;
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        int idx = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i != 0) {
                if (a[i - 1] <= m && a[i] > m) {
                    idx = i;
                }   
            }
        }
        if (idx == -1) {
            if (a[0] > m) {
                idx = 0;
            } else {
                idx = n;
            }
        }

        for (int i = 0; i < idx; i++) {
            printf("%d ", a[i]);
        }
        printf("%d ", m);
        for (int i = idx; i < n; i++) {
            printf("%d", a[i]);
            printf(i != (n - 1) ? " " : "\n");
        }
    }
    return 0;
}