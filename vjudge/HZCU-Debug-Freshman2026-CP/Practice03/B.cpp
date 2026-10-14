#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n;
    while (scanf("%d", &n)) {
        if (n == 0) {
            break;
        } 
        double a[100];
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
        }
        int cnt[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) {
            int idx = (a[i] > 0 ? 2 : 1) * (a[i] == 0 ? 0 : 1);
            cnt[idx]++; 
        }
        printf("%d %d %d\n", cnt[1], cnt[0], cnt[2]);
    }
    return 0;
}