#include <stdio.h>

int main() {
    double x;
    scanf("%lf", &x);
    double xn = 1;
    double ans = 0;
    int n = 0;
    while (xn >= 1e-5) {
        ans += xn;
        n++;
        xn *= x / n;
    }
    ans += xn;
    printf("%.4lf\n", ans);
    return 0;
}
