#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);    
    double ans = 0, sum = 0;
    while (sum <= k) {
        ans++;
        sum += 1.0 / ans;
    }
    printf("%.lf", ans);
    return 0;
}