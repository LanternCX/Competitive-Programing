#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// caoxin

typedef struct {
    double x, y;
} Point;

double get_dist(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {
    Point a, b;
    while (scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y) != EOF) {
        printf("%.2lf\n", get_dist(a, b));
    }
    return 0;
}