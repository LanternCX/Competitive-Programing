#include <stdio.h>

#define PI 3.1415927

int main() {
    int M;
    scanf("%d", &M);
    while (M--) {
        double a, b, c;
        scanf("%lf %lf %lf", &a, &b, &c);
        if (a + b > c && a + c > b && b + c > a) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}