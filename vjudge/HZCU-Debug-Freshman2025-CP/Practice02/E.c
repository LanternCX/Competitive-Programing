#include <math.h>
#include <stdio.h>
#include <string.h>

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    double a[3][2];
    for (int i = 0; i < 3; i++) {
        scanf("%lf %lf", &a[i][0], &a[i][1]);
    }
    double ans = 0;
    for (int i = 0; i < 3; i++) {
        ans += dist(a[i][0], a[i][1], a[(i + 1) % 3][0], a[(i + 1) % 3][1]);
    }
    printf("%.2lf", ans);
    return 0;
}