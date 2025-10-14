#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    double feb[100] = {0};
    feb[0] = 0;
    feb[1] = 1;
    feb[2] = 1;
    for (int i = 3; i <= n; i++) {
        feb[i] = feb[i - 1] + feb[i - 2];
    }

    printf("%.2lf", feb[n]);
    return 0;
}