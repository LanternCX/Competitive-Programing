#include <stdio.h>
#include <math.h>

int a[100 + 10];

int main() {
    int n, m;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        
        for (int i = 0; i < n; i++) {
            int idx = i, max = abs(a[i]);
            for (int j = i + 1; j < n; j++) {
                if (abs(a[j]) > max) {
                    idx = j;
                    max = abs(a[j]);
                }
            }
            int temp = a[i];
            a[i] = a[idx];
            a[idx] = temp;
        }

        for (int i = 0; i < n; i++) {
            printf("%d", a[i]);
            printf(i != (n - 1) ? " " : "\n");
        }
    }
    return 0;
}