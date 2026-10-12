#include <stdio.h>
#include <math.h>

int a[100 + 10];

int get_min_idx(int a[], int n) {
    int mn = a[0];
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < mn) {
            mn = a[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int idx = get_min_idx(a, n);
        
        int temp = a[idx];
        a[idx] = a[0];
        a[0] = temp;

        for (int i = 0; i < n; i++) {
            printf("%d", a[i]);
            printf(i != (n - 1) ? " " : "\n");
        }
    }
    return 0;
}