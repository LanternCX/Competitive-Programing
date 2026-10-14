#include <stdio.h>
#include <math.h>

// caoxin

typedef struct {
    double x, y;
} Point;

int main() {
    int n;
    Point p[105];

    while (scanf("%d", &n) == 1 && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }

        double sum = 0;

        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;

            sum += p[i].x * p[j].y
                 - p[j].x * p[i].y;
        }

        printf("%.1f\n", fabs(sum) / 2.0);
    }

    return 0;
}
