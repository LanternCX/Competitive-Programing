#include <stdio.h>
#include <math.h>

// caoxin

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        double ans = 0;
        int mx = -1e9;
        int mn = 1e9;
        for (int i = 0; i < n; i++) {
            double x;
            scanf("%lf", &x);
            if (mx < x) {
                mx = x;
            }
            if (mn > x) {
                mn = x;
            }
            ans += x;
        }
        printf("%.2lf\n", (ans - mx - mn) / (n * 1.0 - 2)); 
    }
    return 0;
}
